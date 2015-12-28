/********************************************************************
	created:	2009/08/17
	created:	17:8:2009   19:34
	filename: 	i:\Trab\ZShoot\Development\Sources\devices.cpp
	file path:	i:\Trab\ZShoot\Development\Sources
	file base:	devices
	file ext:	cpp
	author:		
	
	purpose:	
*********************************************************************/
#include "devices.h"
#include <irrlicht.h>

#include <assert.h>
scene::ISceneManager* Device::smgr = 0;
video::IVideoDriver* Device::driver = 0;
IrrlichtDevice* Device::device = 0;

InputEventReceiver* Device::joystickReceiver = 0;
IEventReceiver* Device::keyboardReceiver = 0;

f32	Device::frameDuration=0;
u32	Device::frameDurationMs=0;


scene::ISceneManager* Device::GetSceneManager()
{
	assert(smgr);
	return smgr;
}
video::IVideoDriver* Device::GetVideoDriver()
{
	assert(driver);
	return driver;
}
IrrlichtDevice * Device::GetIrrlichtDevice()
{
	assert(device);
	return device;
}
InputEventReceiver * Device::GetJoystickReceiver()
{
	assert(joystickReceiver);
	return joystickReceiver;

}
IEventReceiver * Device::GetKeyboardReceiver()
{
	assert(keyboardReceiver);
	return keyboardReceiver;
}

void Device::SetSceneManager(scene::ISceneManager*_d)
{
	smgr = _d;
}
void Device::SetVideoDriver(video::IVideoDriver*_d)
{
	driver = _d;
}
void Device::SetIrrlichtDevice(IrrlichtDevice *_d)
{
	device = _d;
}

void Device::SetJoystickReceiver(InputEventReceiver*_d)
{
	joystickReceiver = _d;
}
void Device::SetKeyboardReceiver(IEventReceiver*_d)
{
	keyboardReceiver = _d;
}
