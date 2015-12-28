/********************************************************************
	created:	2009/10/13
	created:	13:10:2009   0:16
	filename: 	i:\Trab\ZShoot\Development\Sources\Rendering\CRadiosityManager.h
	file path:	i:\Trab\ZShoot\Development\Sources\Rendering
	file base:	CRadiosityManager
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/
#ifndef _CRADIOSITYMANAGER_H_
#define _CRADIOSITYMANAGER_H_
#include "CRadiantObject.h"
#include <vector>
namespace Lighting
{
class CRadiantObject;
class CRadiosityManager
{

private:

	static Lighting::CRadiosityManager* m_pRadiosityManager;

	SH::Coefficients SHCofficients[8];
	irr::core::vector3df pos[8];

	std::vector<CRadiantObject*> m_vecRadiantObjects;
	
	//std::vector<SH::Coefficients> m_vecSHCofficients;

public :

	static Lighting::CRadiosityManager* GetRadiosityManager() 
	{
			return m_pRadiosityManager;
	}


	// friend class CDemo;
	static Lighting::CRadiosityManager* CreateRadiosityManager()
	{
		m_pRadiosityManager = new Lighting::CRadiosityManager;
		return m_pRadiosityManager;
	}
	static void DestroyRadiosityManager()
	{
		delete 	m_pRadiosityManager;
	}
private:

	void GatherLightingContext();

	void GatherLightingContextFromObject(const CRadiantObject *_obj);
	
	void Add(CRadiantObject* _obj);

public:

	CRadiosityManager();
	~CRadiosityManager();
	
	SH::Coefficients*GetCoefficients() ;
	
	irr::core::vector3df*GetPositions() ;
	
	irr::scene::ISceneNode* GetNode();
	
	//
	virtual void Init();

	//
	virtual void Update();

	//
	virtual void Shutdown();
};
}//namespace Lighting
#endif // _CRADIOSITYMANAGER_H_