/********************************************************************
	created:	2009/09/12
	created:	12:10:2009   23:51
	filename: 	i:\Trab\ZShoot\Development\Sources\Rendering\CRadiantObject.cpp
	file path:	i:\Trab\ZShoot\Development\Sources\Rendering
	file base:	CRadiantObject
	file ext:	cpp
	author:		
	
	purpose:	
*********************************************************************/

#include "CRadiantObject.h"
#include "..\devices.h"
namespace Lighting
{
	core::vector3df pos[8]=
	{
		core::vector3df(0.379856f	,	1.26562f	,	0.429463f	),
		core::vector3df(0.379856f	,	1.26562f	,	-0.512678f	),
		core::vector3df(-0.540492f	,	1.26562f	,	-0.512678f	),
		core::vector3df(-0.540492f	,	1.26562f	,	0.429463f	),
		core::vector3df(-0.540492f	,	2.14507f	,	-0.512678f	),
		core::vector3df(-0.540492f	,	2.14507f	,	0.429463f	),
		core::vector3df(0.379856f	,	2.14507f	,	-0.512678f	),
		core::vector3df(0.379856f	,	2.14507f	,	0.429463f	),
	};
// -------------------------------------
//  Constructor
// -------------------------------------
CRadiantObject::CRadiantObject() : m_SceneNode(0)
{

}
// -------------------------------------
//  Destructor
// -------------------------------------
CRadiantObject::~CRadiantObject()
{

}
// -------------------------------------
/// Init()
/// @brief initialize and setup radiant probe
/// prepare object for radiosity rendering : the preprocess 
// -------------------------------------
void CRadiantObject::Init()
{
	// Retrieve scene manager
	scene::ISceneManager*smgr = Device::GetSceneManager();
	
	// Load the mesh : a cube
	m_SceneNode = Device::GetSceneManager()->addAnimatedMeshSceneNode(smgr->getMesh("Data/cubetest.3ds"));
	
	// Set a texture on this cube and default material
	m_SceneNode->setMaterialTexture(0,Device::GetVideoDriver()->getTexture("Data/1d_debug.png"));
	m_SceneNode->setMaterialFlag(video::EMF_LIGHTING, false);
	
	// Front face culling because we will generate cubemap from inside the mesh
	m_SceneNode->setMaterialFlag(video::EMF_FRONT_FACE_CULLING, true);
	
	// This object has 8 probes inside
	// For each probe, we generate a cubemap, project it into SH coefficients
	for(u32 i = 0; i< 8; i++)
	{
		SHProbes[i].SetNode(smgr->addEmptySceneNode());
		SHProbes[i].SetPosition(pos[i]);
		SHProbes[i].GenerateCubeMap(pos[i],i);
	}

	// Restore
	m_SceneNode->setMaterialFlag(video::EMF_FRONT_FACE_CULLING, false);
}
// -------------------------------------
/// Shutdown()
/// @brief  
// -------------------------------------
void CRadiantObject::Shutdown()
{
	for(u32 i = 0; i< 8; i++)
	{
		SHProbes[i].Shutdown();
	}
}
// -------------------------------------
///
// -------------------------------------
void CRadiantObject::SetNode(irr::scene::ISceneNode* _node)
{
	m_SceneNode = _node;
}
// -------------------------------------
/// GetNode
// -------------------------------------
irr::scene::ISceneNode* CRadiantObject::GetNode()
{
	return m_SceneNode;
}
// -------------------------------------
/// SetPosition
// -------------------------------------
void CRadiantObject::SetPosition(const irr::core::vector3df _pos)
{
	m_SceneNode->setPosition(_pos);
}
// -------------------------------------
/// GetPosition
// -------------------------------------
irr::core::vector3df CRadiantObject::GetPosition() const
{
	return m_SceneNode->getPosition();
}

// -------------------------------------
/// SetRotation
// -------------------------------------
void CRadiantObject::SetRotation(const irr::core::vector3df _pos)
{
	m_SceneNode->setRotation(_pos);
}
// -------------------------------------
/// GetRotation
// -------------------------------------
irr::core::vector3df CRadiantObject::GetRotation() const
{
	return m_SceneNode->getRotation();
}

}// namespace Lighting
