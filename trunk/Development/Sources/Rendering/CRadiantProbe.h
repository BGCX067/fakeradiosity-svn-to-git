/********************************************************************
	created:	2009/09/12
	created:	12:10:2009   22:52
	filename: 	i:\Trab\ZShoot\Development\Sources\Rendering\CRadiantProbe.h
	file path:	i:\Trab\ZShoot\Development\Sources\Rendering
	file base:	CRadiantProbe
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/
#ifndef _CRadiantProbe_h_
#define _CRadiantProbe_h_
#include "irrlicht.h"
#include "SH.h"
// forward declarations
namespace SH
{
	struct Coefficients;
}

// 
namespace Lighting
{
	class CRadiantProbe 
	{
	private:
		SH::Coefficients		m_Coefficients;
		irr::scene::ISceneNode*	m_SceneNode;
	public:
		CRadiantProbe();
		~CRadiantProbe();


	//private:
		SH::Coefficients GenerateCubeMap(const irr::core::vector3df _pos,const unsigned int _index,const unsigned int _resolution = 64);
	
		SH::Coefficients GetCoefficients() const ;

		void SetNode(irr::scene::ISceneNode*_node);
		void SetPosition(const irr::core::vector3df _pos);
		irr::scene::ISceneNode* GetNode();

		void Shutdown();
	};
} // namespace Lighting


#endif // _CRadiantProbe_h_