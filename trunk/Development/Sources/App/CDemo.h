/********************************************************************
	created:	2009/09/12
	created:	12:10:2009   20:57
	filename: 	i:\Trab\ZShoot\Development\Sources\Game\CDemo.h
	file path:	i:\Trab\ZShoot\Development\Sources\Game
	file base:	CDemo
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/
#ifndef _CDEMO_H_
#define _CDEMO_H_

#include "IApp.h"
#include "..\InputEvent.h"
namespace irr
{

}
namespace Lighting
{
	class CRadiosityManager;
}
namespace Main
{
	class CDemo : public IApp
	{
		public:
			

			// from IApp

			//
			virtual void Init();

			//
			virtual void Draw();

			//
			virtual void Update(float _frameDeltaTime);

			//
			virtual void Shutdown();
		public:
			CDemo();
			virtual ~CDemo();
		
		private:
				
			Lighting::CRadiosityManager *m_pRadiosityManager;
			int				m_LastFPS ;
			InputEventReceiver receiver;
	

	};
}


#endif // _CDEMO_H_
