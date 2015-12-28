/** Exemple of Fake radiosity 
by Victor Ceitelis
*/
#ifdef _MSC_VER
// We'll also define this to stop MSVC complaining about sprintf().
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Irrlicht.lib")
#endif

#include "devices.h"
#include "App/CDemo.h"

int main()
{
	Main::CDemo	demo;
	demo.Init();
	
	u32 then = Device::GetIrrlichtDevice()->getTimer()->getTime();

	while(Device::GetIrrlichtDevice()->run())
	{

		// Work out a frame delta time.
		const u32 now = Device::GetIrrlichtDevice()->getTimer()->getTime();
		const f32 frameDeltaTime = (f32)(now - then) / 1000.f; // Time in seconds
		Device::frameDuration = frameDeltaTime; 
		if(then==0)
		{
			Device::frameDurationMs =  10; 
		}
		else
		{
			Device::frameDurationMs =  (now - then); 
		}
		then = now;
		
		demo.Update(frameDeltaTime);
		demo.Draw();
	}
	
	demo.Shutdown();
	return 0;
}

/*
That's it. Compile and play around with the program.
**/
