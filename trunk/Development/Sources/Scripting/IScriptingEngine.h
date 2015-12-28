/********************************************************************
	created:	2009/09/12
	created:	12:10:2009   21:03
	filename: 	i:\Trab\ZShoot\Development\Sources\Scripting\IScriptingEngine.h
	file path:	i:\Trab\ZShoot\Development\Sources\Scripting
	file base:	IScriptingEngine
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/
#ifndef _ISCRIPTINGENGINE_H_
#define _ISCRIPTINGENGINE_H_
#include "string"
namespace Scripting
{
	class IEngine
	{
		
		public:
			// 
			virtual void IScriptEngine() = 0;
			
			// 
			virtual void ExecuteFile(const std::string &_filename) = 0;
			
			// 
			virtual void ExecuteString(const std::string &_str) = 0;
			
			// 
			virtual std::string GetErrorString() = 0;
			
			// 
			virtual void InitVM() = 0;
			
			// 
			virtual void ShutdownVM() = 0;
	};
}
#endif // _ISCRIPTINGENGINE_H_