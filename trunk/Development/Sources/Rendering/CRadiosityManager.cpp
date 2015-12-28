/********************************************************************
	created:	2009/10/13
	created:	13:10:2009   0:16
	filename: 	i:\Trab\ZShoot\Development\Sources\Rendering\CRadiosityManager.cpp
	file path:	i:\Trab\ZShoot\Development\Sources\Rendering
	file base:	CRadiosityManager
	file ext:	cpp
	author:		
	
	purpose:	
*********************************************************************/

#include "CRadiosityManager.h"
namespace Lighting
{
	Lighting::CRadiosityManager* CRadiosityManager::m_pRadiosityManager = 0;

// -------------------------------------
///@brief  Constructor
// -------------------------------------
CRadiosityManager::CRadiosityManager()
{

}
// -------------------------------------
///@brief  Destructor
// -------------------------------------
CRadiosityManager::~CRadiosityManager()
{

}
// -------------------------------------
/// @brief
// -------------------------------------
void CRadiosityManager::Init()
{
	Lighting::CRadiantObject * pCubeRadiant = new Lighting::CRadiantObject ;
	pCubeRadiant->Init();
	Add(pCubeRadiant);
}

// -------------------------------------
/// @brief
// -------------------------------------
void CRadiosityManager::Update()
{
	GatherLightingContext();
}
// -------------------------------------
///@brief  Shutdown all radiant objects
// -------------------------------------
void CRadiosityManager::Shutdown()
{	
	for (unsigned int i = 0 ; i< m_vecRadiantObjects.size();i++)
	{
		m_vecRadiantObjects[i]->Shutdown();
	}
}
// -------------------------------------
///@brief  GatherLightingContext
// -------------------------------------
void CRadiosityManager::GatherLightingContext()
{
	GatherLightingContextFromObject(m_vecRadiantObjects[0]);
	
	//FoundObjectAroundPosition(_pos);
	//For each object collect SH coefficients
}
// -------------------------------------
///GatherLightingContext
///@brief Collect all SH coefficient from probes of this object
// -------------------------------------
void CRadiosityManager::GatherLightingContextFromObject(const CRadiantObject *_obj)
{
	for(int i = 0; i< 8; i++)
	{
		SHCofficients[i] = _obj->SHProbes[i].GetCoefficients();
	}
	
}
// -------------------------------------
///@brief  Add object radiant
// -------------------------------------
void CRadiosityManager::Add( CRadiantObject* _obj )
{	
	m_vecRadiantObjects.push_back(_obj);
}

// -------------------------------------
///@brief  Shutdown all radiant objects
// -------------------------------------
irr::scene::ISceneNode* CRadiosityManager::GetNode()
{
	return m_vecRadiantObjects[0]->GetNode();
}

// -------------------------------------
/// GetCoefficients
// -------------------------------------
SH::Coefficients* CRadiosityManager::GetCoefficients() 
{
	return &SHCofficients[0];
}
// -------------------------------------
/// GetPositions
// -------------------------------------
irr::core::vector3df* CRadiosityManager::GetPositions() 
{
	return &pos[0];
}
} //namespace Lighting