/********************************************************************
created:	2009/09/12
created:	12:10:2009   22:06
filename: 	i:\Trab\ZShoot\Development\Sources\Game\Demo.cpp
file path:	i:\Trab\ZShoot\Development\Sources\Game
file base:	Demo
file ext:	cpp
author:		

purpose:	
*********************************************************************/

#include "CDemo.h"
#include "assert.h"
#include <irrlicht.h>

#include "..\devices.h"
#include "..\InputEvent.h"
#include "..\Rendering/CRadiosityManager.h"
namespace Main
{

	class ProbeShaderCallback : public irr::video::IShaderConstantSetCallBack
	{
	public:

		virtual void OnSetConstants(irr::video::IMaterialRendererServices* services, int userData)
		{
			irr::video::IVideoDriver* driver = services->getVideoDriver();

			//const u32 now = Device::GetIrrlichtDevice()->getTimer()->getTime();


			Lighting::CRadiosityManager* pRadiosityManager = Lighting::CRadiosityManager::GetRadiosityManager();

			assert(NULL!=pRadiosityManager);

			if(pRadiosityManager->GetNode())
			{
				services->setPixelShaderConstant("SHConstants", (f32*)(pRadiosityManager->GetCoefficients()), 4*7*8);
				services->setPixelShaderConstant("SHProbesPositions", (f32*)(pRadiosityManager->GetPositions()), 3*8);
				core::matrix4 ColorCubeNodeWorld = pRadiosityManager->GetNode()->getAbsoluteTransformation();
				services->setPixelShaderConstant("ColorCubeNodeWorld", ColorCubeNodeWorld.pointer(), 16);
				ColorCubeNodeWorld.makeInverse();
				services->setPixelShaderConstant("InvColorCubeNodeWorld", ColorCubeNodeWorld.pointer(), 16);

			}

			core::matrix4 invWorld = driver->getTransform(irr::video::ETS_WORLD);
			services->setVertexShaderConstant("mWorld", invWorld.pointer(), 16);
			invWorld.makeInverse();

			services->setVertexShaderConstant("mInvWorld", invWorld.pointer(), 16);

			core::matrix4 worldViewProj;
			worldViewProj = driver->getTransform(irr::video::ETS_PROJECTION);			
			worldViewProj *= driver->getTransform(irr::video::ETS_VIEW);
			worldViewProj *= driver->getTransform(irr::video::ETS_WORLD);

			services->setVertexShaderConstant("mWorldViewProj", worldViewProj.pointer(), 16);

		}
	};
	// -------------------------------------
	///  constructor
	// -------------------------------------
	CDemo::CDemo()
	{

	}
	// -------------------------------------
	///  destructor
	// -------------------------------------
	CDemo::~CDemo()
	{

	}

	// -------------------------------------
	/// @brief
	// -------------------------------------
	void CDemo::Init()
	{
		video::E_DRIVER_TYPE driverType = video::EDT_DIRECT3D9;
		driverType = video::EDT_DIRECT3D9;
		// create device
		
		IrrlichtDevice*	device = createDevice(driverType,core::dimension2d<s32>(1280, 720), 32, false, false, false, &receiver);

		if (device == 0)
			return ; // could not create selected driver.

		irr::video::IVideoDriver* driver = device->getVideoDriver();
		irr::scene::ISceneManager*smgr = device->getSceneManager();
		Device::SetIrrlichtDevice(device);
		Device::SetSceneManager(smgr);
		Device::SetVideoDriver(driver);

		smgr->addCameraSceneNodeFPS(0, 50.0f, .02f);
		irr::scene::ICameraSceneNode* camera = smgr->getActiveCamera();
		device->getCursorControl()->setVisible(false);

		camera->setPosition(core::vector3df(17,3,2));

		// create skybox and skydome
		driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, false);
		irr::scene::ISceneNode* skydome=smgr->addSkyDomeSceneNode(driver->getTexture("Data/skydome.jpg"),16,8,0.95f,2.0f);
		driver->setTextureCreationFlag(irr::video::ETCF_CREATE_MIP_MAPS, true);

		skydome->setVisible(true);

		Device::frameDuration = 0.0f;
		Device::frameDurationMs = 0;

		
		u32 uiFrameCount = 0;


		Lighting::CRadiosityManager::CreateRadiosityManager();

		m_pRadiosityManager = Lighting::CRadiosityManager::GetRadiosityManager();
		m_pRadiosityManager->Init();

		irr::scene::ISceneNode* pbackgroundnode = Device::GetSceneManager()->addAnimatedMeshSceneNode(Device::GetSceneManager()->getMesh("Data/cubetestback.3ds"));
		const c8* vsFileName = 0; // filename for the vertex shader
		const c8* psFileName = 0; // filename for the pixel shader
		psFileName = "Data/sh.hlsl";
		vsFileName = psFileName; // both shaders are in the same file
		irr::video::IGPUProgrammingServices* gpu = Device::GetVideoDriver()->getGPUProgrammingServices();
		s32 newMaterialType1 = 0;
		ProbeShaderCallback* mc = new ProbeShaderCallback();
		newMaterialType1 = gpu->addHighLevelShaderMaterialFromFiles(vsFileName,
			"vertexMain",
			video::EVST_VS_3_0,
			psFileName,
			"pixelMain",
			video::EPST_PS_3_0,
			mc,
			video::EMT_TRANSPARENT_ALPHA_CHANNEL);
		mc->drop();
		pbackgroundnode->setMaterialType((video::E_MATERIAL_TYPE)newMaterialType1);
		pbackgroundnode->setMaterialFlag(video::EMF_FRONT_FACE_CULLING, false);
		pbackgroundnode->setMaterialFlag(video::EMF_BACK_FACE_CULLING, false);

		m_LastFPS = -1;
	}
	// -------------------------------------
	/// @brief
	// -------------------------------------
	void CDemo::Draw()
	{
		IrrlichtDevice*	device = Device::GetIrrlichtDevice();
		video::IVideoDriver* driver = device->getVideoDriver();
		scene::ISceneManager*smgr = device->getSceneManager();
		driver->beginScene(true, true, video::SColor(255,113,113,133));

		smgr->drawAll(); // draw the 3d scene
		device->getGUIEnvironment()->drawAll(); // draw the gui environment (the logo)

		driver->endScene();

		int fps = driver->getFPS();

		if (m_LastFPS != fps)
		{
			core::stringw tmp(L"Victor Ceitelis Portofolio [");
			tmp += driver->getName();
			tmp += L"] fps: ";
			tmp += fps;



			device->setWindowCaption(tmp.c_str());
			m_LastFPS = fps;
		}
	}
	// -------------------------------------
	/// @brief
	// -------------------------------------
	void CDemo::Update(float frameDeltaTime)
	{
		
		m_pRadiosityManager->Update();

		if(m_pRadiosityManager->GetNode())
		{
			float angularSpeed = 50.1f;
			float motionSpeed = 5.1f;
			core::vector3df colorCubeNodePos = m_pRadiosityManager->GetNode()->getPosition();
			if(receiver.IsKeyDown(KEY_NUMPAD4))
			{
				colorCubeNodePos.X+=motionSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD6))
			{
				colorCubeNodePos.X-=motionSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD8))
			{
				colorCubeNodePos.Y+=motionSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD5))
			{
				colorCubeNodePos.Y-=motionSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD7))
			{
				colorCubeNodePos.Z+=motionSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD9))
			{
				colorCubeNodePos.Z-=motionSpeed*frameDeltaTime;
			}
			m_pRadiosityManager->GetNode()->setPosition(colorCubeNodePos);
			core::vector3df rot = m_pRadiosityManager->GetNode()->getRotation();
			if(receiver.IsKeyDown(KEY_NUMPAD1))
			{
				rot.X+=angularSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD1) && receiver.IsKeyDown(KEY_SHIFT))
			{
				rot.X-=angularSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD2))
			{
				rot.Y+=angularSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD2) && receiver.IsKeyDown(KEY_SHIFT))
			{
				rot.Y-=angularSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD3))
			{
				rot.Z+=angularSpeed*frameDeltaTime;
			}
			if(receiver.IsKeyDown(KEY_NUMPAD3) && receiver.IsKeyDown(KEY_SHIFT))
			{
				rot.Z-=angularSpeed*frameDeltaTime;
			}
			m_pRadiosityManager->GetNode()->setRotation(rot);
		}


		
	}

	// -------------------------------------
	/// @brief
	// -------------------------------------
	void CDemo::Shutdown()
	{
		Lighting::CRadiosityManager::DestroyRadiosityManager();
		Device::GetIrrlichtDevice()->drop();

	}

} // namespace Main
