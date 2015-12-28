/********************************************************************
	created:	2009/09/12
	created:	12:10:2009   23:51
	filename: 	i:\Trab\ZShoot\Development\Sources\Rendering\CRadiantObject.h
	file path:	i:\Trab\ZShoot\Development\Sources\Rendering
	file base:	CRadiantObject
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/
#ifndef _CRADIANTOBJECT_H_
#define _CRADIANTOBJECT_H_
#include "CRadiantProbe.h"
#include <vector>
namespace Lighting
{
class CRadiantObject
{

private:
	
	irr::scene::ISceneNode*	m_SceneNode;
	Lighting::CRadiantProbe SHProbes[8];

protected:
	CRadiantObject();
	~CRadiantObject();
	
	friend class CRadiosityManager;
	
	void Init();
	void Shutdown();

	void SetNode(irr::scene::ISceneNode*_node);
	irr::scene::ISceneNode* GetNode();

	void SetPosition(const irr::core::vector3df _pos);
	irr::core::vector3df GetPosition() const;
	
	void SetRotation(const irr::core::vector3df _pos);
	irr::core::vector3df GetRotation() const;



};
} // namespace Lighting

#endif // _CRADIANTOBJECT_H_