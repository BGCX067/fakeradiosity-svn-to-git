/********************************************************************
	created:	2009/09/12
	created:	12:10:2009   21:08
	filename: 	i:\Trab\ZShoot\Development\Sources\Scripting\CScriptingLua.h
	file path:	i:\Trab\ZShoot\Development\Sources\Scripting
	file base:	CScriptingLua
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/
#ifndef _CSCRIPTINGLUA_H_
#define _CSCRIPTINGLUA_H_
#include "IScriptingEngine.h"

// forward
struct lua_State;


//
namespace Scripting
{

	class CScriptingLua : public IEngine
	{
		public:
			
			// from IScriptingEngine
			
			//
			virtual ~CScriptingLua();

			// 
			virtual void ExecuteFile(const std::string &_strFilename);

			// 
			virtual void ExecuteString(const std::string &_str);

			// 
			virtual std::string GetErrorString();

			// 
			virtual void InitVM();

			// 
			virtual void ShutdownVM();

		public:
			CScriptingLua();
		
		
		private:
			std::string		m_strError;
			lua_State	*	m_pLuaState;
	};

}




#endif // _CSCRIPTINGLUA_H_