/********************************************************************
	created:	2009/08/17
	created:	17:8:2009   19:34
	filename: 	i:\Trab\ZShoot\Development\Sources\devices.h
	file path:	i:\Trab\ZShoot\Development\Sources
	file base:	devices
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/
#ifndef _DEVICES_H_
#define _DEVICES_H_
#include <irrlicht.h>

#include "InputEvent.h"
using namespace irr;


class Device
{
private:
	static scene::ISceneManager* smgr;
	static video::IVideoDriver* driver;
	static IrrlichtDevice*		device;
	static InputEventReceiver*		joystickReceiver; 
	static IEventReceiver*		keyboardReceiver; 
	
public:
	static f32					frameDuration;
	static u32					frameDurationMs;
	static scene::ISceneManager* GetSceneManager();
	static video::IVideoDriver* GetVideoDriver();
	static IrrlichtDevice * GetIrrlichtDevice();
	static InputEventReceiver* GetJoystickReceiver();
	static IEventReceiver* GetKeyboardReceiver();


public:
	static void SetSceneManager(scene::ISceneManager*_d);
	static void SetVideoDriver(video::IVideoDriver*_d);
	static void SetIrrlichtDevice(IrrlichtDevice *_d);
	static void SetJoystickReceiver(InputEventReceiver*_d);
	static void SetKeyboardReceiver(IEventReceiver*_d);
	
};
#endif //_DEVICES_H_