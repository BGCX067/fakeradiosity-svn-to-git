/********************************************************************
created:	2009/09/12
created:	12:10:2009   22:11
filename: 	i:\Trab\ZShoot\Development\Sources\App\IApp.h
file path:	i:\Trab\ZShoot\Development\Sources\App
file base:	IApp
file ext:	h
author:		

purpose:	
*********************************************************************/
#ifndef _IAPP_H_
#define _IAPP_H_
namespace Main
{
	// @class abstract class for an application 
	class IApp
	{

	public:
		//
		virtual void Init()=0;

		//
		virtual void Draw()=0;

		//
		virtual void Update(float _frameDeltaTime)=0;

		//
		virtual void Shutdown()=0;
	};
} // namespace Main

#endif // _IAPP_H_