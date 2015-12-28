/********************************************************************
	created:	2009/08/20
	created:	20:8:2009   11:01
	filename: 	i:\Trab\ZShoot\Development\Sources\InputEvent.h
	file path:	i:\Trab\ZShoot\Development\Sources
	file base:	InputEvent
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/
#ifndef _INPUTEVENT_H_
#define _INPUTEVENT_H_
#include <irrlicht.h>
using namespace irr;
class InputEventReceiver : public IEventReceiver
{
public:
	unsigned int uiLastKey;
	bool bKeyPressed;
	core::array<SJoystickInfo> joystickInfo;
	// This is the one method that we have to implement
	virtual bool OnEvent(const SEvent& event)
	{
		// Remember whether each key is down or up
		if (event.EventType == irr::EET_KEY_INPUT_EVENT)
		{
			KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
			uiLastKey= event.KeyInput.Key; 
			bKeyPressed = true;
		}
		else
		{
			bKeyPressed = false;
		}
		// The state of each connected joystick is sent to us
		// once every run() of the Irrlicht device.  Store the
		// state of the first joystick, ignoring other joysticks.
		// This is currently only supported on Windows and Linux.
		if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT
			&& event.JoystickEvent.Joystick == 0)
		{
			JoystickState = event.JoystickEvent;
		}
		return false;
	}
	const SEvent::SJoystickEvent & GetJoystickState(void) const
	{
		return JoystickState;
	}
	// This is used to check whether a key is being held down
	virtual bool IsKeyDown(EKEY_CODE keyCode) const
	{
		return KeyIsDown[keyCode];
	}

	InputEventReceiver()
	{
		for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
			KeyIsDown[i] = false;
		bKeyPressed = false;
	}

private:
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];

private:
	SEvent::SJoystickEvent JoystickState;
};
#endif// _INPUTEVENT_H_