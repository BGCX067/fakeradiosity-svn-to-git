/********************************************************************
	created:	2009/09/12
	created:	12:10:2009   22:52
	filename: 	i:\Trab\ZShoot\Development\Sources\Rendering\CRadiantProbe.cpp
	file path:	i:\Trab\ZShoot\Development\Sources\Rendering
	file base:	CRadiantProbe
	file ext:	cpp
	author:		
	
	purpose:	
*********************************************************************/

#include "CRadiantProbe.h"
#include "d3dx9.h"
#include <CD3D9Texture.h>
#include "..\devices.h"
namespace Lighting
{
// -------------------------------------
//  Constructor
// -------------------------------------
CRadiantProbe::CRadiantProbe():m_SceneNode(0)
{
	
}
// -------------------------------------
//  Destructor
// -------------------------------------
CRadiantProbe::~CRadiantProbe()
{

}
// -------------------------------------
/// Shutdown()
/// @brief  
// -------------------------------------
void CRadiantProbe::Shutdown()
{
	
}
SH::Coefficients CRadiantProbe::GenerateCubeMap(const  irr::core::vector3df _pos,const unsigned int _index,const unsigned int _resolution )
{
	
	SH::Coefficients SHCoefficient;
	IrrlichtDevice*	device = Device::GetIrrlichtDevice();

	video::IVideoDriver* driver = device->getVideoDriver();

	LPDIRECT3DCUBETEXTURE9 pCubeMap = 0;
	
	HRESULT hr = S_OK;
	
	IDirect3DDevice9* pID3DDevice= (IDirect3DDevice9*)driver->getGraphicDevice();;
	

	// Create the cubemap render target
	hr = pID3DDevice->CreateCubeTexture(_resolution, 1, D3DUSAGE_RENDERTARGET, D3DFMT_A8R8G8B8,D3DPOOL_DEFAULT, &pCubeMap,0);
	
	scene::ISceneManager*smgrLocal = device->getSceneManager();
	irr::scene::ICameraSceneNode* oldcamera = smgrLocal->getActiveCamera();

	const unsigned int D3DCUBEMAP_FACE_POSITIVE_X = 0;
	const unsigned int D3DCUBEMAP_FACE_NEGATIVE_X = 1;
	const unsigned int D3DCUBEMAP_FACE_POSITIVE_Y = 2;
	const unsigned int D3DCUBEMAP_FACE_NEGATIVE_Y = 3;
	const unsigned int D3DCUBEMAP_FACE_POSITIVE_Z = 4;
	const unsigned int D3DCUBEMAP_FACE_NEGATIVE_Z = 5;
	float PI_BY_2 =  D3DX_PI/2;
	
	// 6 irrlicht textures
	video::ITexture* rt[6];
	
	
	// add fixed camera at position "pos"
	scene::ICameraSceneNode* fixedCam = 0;
	fixedCam = smgrLocal->addCameraSceneNode(0, _pos);
	for (unsigned int i = 0 ;i<6;i++)
	{
		rt[i] = driver->addRenderTargetTexture(core::dimension2d<s32>(_resolution,_resolution), "RTT1");
		driver->setRenderTarget(rt[i], true, true, video::SColor(0,0,0,255));
		core::vector3df vEnvEyePt = _pos;
		core::vector3df vLookatPt, vUpVec;

		switch(i)
		{


		case D3DCUBEMAP_FACE_POSITIVE_X:
			vLookatPt = irr::core::vector3df(1.0f, 0.0f, 0.0f);
			vUpVec    = irr::core::vector3df(0.0f, 1.0f, 0.0f);
			
			break;
		case D3DCUBEMAP_FACE_NEGATIVE_X:
			vLookatPt = core::vector3df(-1.0f, 0.0f, 0.0f);
			vUpVec    = core::vector3df( 0.0f, 1.0f, 0.0f);

			break;
		case D3DCUBEMAP_FACE_POSITIVE_Y:
			vLookatPt = irr::core::vector3df(0.0f, 1.0f, 0.0f);;
			vUpVec    = irr::core::vector3df(0.0f, 0.0f, -1.0f);;
			
			break;
		case D3DCUBEMAP_FACE_NEGATIVE_Y:
			vLookatPt = core::vector3df(0.0f,-1.0f, 0.0f);
			vUpVec    = core::vector3df(0.0f, 0.0f, 1.0f);
			
			break;
		case D3DCUBEMAP_FACE_POSITIVE_Z:
			vLookatPt = core::vector3df( 0.0f, 0.0f, 1.0f);
			vUpVec    = core::vector3df( 0.0f, 1.0f, 0.0f);
			
			break;
		case D3DCUBEMAP_FACE_NEGATIVE_Z:
			vLookatPt = core::vector3df(0.0f, 0.0f,-1.0f);
			vUpVec    = core::vector3df(0.0f, 1.0f, 0.0f);
			
			break;
		}
		vLookatPt = vLookatPt+_pos;
		vUpVec    = vUpVec;

		fixedCam->setTarget(vLookatPt);
		fixedCam->setUpVector(vUpVec);
		fixedCam->setPosition(_pos);
	
		//projection matrix
		core::matrix4 projection;
		projection.buildProjectionMatrixPerspectiveFovLH( D3DX_PI/2, 1.0f, 0.005f, 100.0f);
		fixedCam->setProjectionMatrix(projection);
		driver->beginScene(true, true, video::SColor(0,0,0,1));

		smgrLocal->drawAll(); // draw the 3d scene

		driver->setRenderTarget(0, true, true, 0);

		driver->endScene();
		
		// Retrieve DX9 texure from irrlicht texture
		IDirect3DTexture9* tex = (IDirect3DTexture9*)((video::CD3D9Texture*)(rt[i]))->getDriverTexture();
		LPDIRECT3DSURFACE9 pFace;
		pCubeMap->GetCubeMapSurface((D3DCUBEMAP_FACES)i, 0, &pFace);
		IDirect3DSurface9 *surfSource;
		tex->GetSurfaceLevel(0,&surfSource); 
		pID3DDevice->StretchRect(surfSource,0,pFace,0,D3DTEXF_NONE);
		surfSource->Release();
		
		// DEBUG
		//char d[256];
		//sprintf(d,"cubemap%d.png",i);
		//D3DXSaveTextureToFile(d,D3DXIFF_PNG,tex,0);
	}
	
	//DEBUG
	//char deb[256];
	//sprintf(deb,"cubemapcomplete%d.dds",_index);
	//D3DXSaveTextureToFile(deb,D3DXIFF_DDS,pCubeMap,0);
	smgrLocal->setActiveCamera(oldcamera);

	// Do the SH projection 
	SH::Constants fOriginalConstant;  
	D3DXSHProjectCubeMap(6, pCubeMap, fOriginalConstant.fOriginalConstant[0], fOriginalConstant.fOriginalConstant[1], fOriginalConstant.fOriginalConstant[2] ) ;

	// Retrieve coeeficients
	UpdateSHShaderConstants(fOriginalConstant,SHCoefficient);
	m_Coefficients = SHCoefficient;
	return SHCoefficient; // copy

}
// -------------------------------------
///
// -------------------------------------
void CRadiantProbe::SetNode(irr::scene::ISceneNode* _node)
{
	m_SceneNode = _node;
}
// -------------------------------------
/// GetNode
// -------------------------------------
irr::scene::ISceneNode* CRadiantProbe::GetNode()
{
	return m_SceneNode;
}
// -------------------------------------
/// SetPosition
// -------------------------------------
void CRadiantProbe::SetPosition(const  irr::core::vector3df _pos)
{
	m_SceneNode->setPosition(_pos);
}
// -------------------------------------
///
// -------------------------------------
SH::Coefficients CRadiantProbe::GetCoefficients() const 
{
	return m_Coefficients;
}

} //namespace Lighting