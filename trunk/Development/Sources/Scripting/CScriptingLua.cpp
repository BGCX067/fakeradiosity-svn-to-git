/********************************************************************
created:	2009/09/12
created:	12:10:2009   21:08
filename: 	i:\Trab\ZShoot\Development\Sources\Scripting\CScriptingLua.cpp
file path:	i:\Trab\ZShoot\Development\Sources\Scripting
file base:	CScriptingLua
file ext:	cpp
author:		

purpose:	
*********************************************************************/

#include "CScriptingLua.h"

#define ENABLE_LUA 

extern "C"
{
	#include "lua.h"
	#include <lauxlib.h>
	#include <lualib.h>
}
#include <Tolua++.h>
TOLUA_API int  tolua_bindings_open (lua_State* tolua_S);

//
namespace Scripting
{
	// From IScriptingEngine
	// -------------------------------------
	///  constructor
	// -------------------------------------
	CScriptingLua::CScriptingLua() 
	{

	}
	// -------------------------------------
	///  destructor
	// -------------------------------------
	CScriptingLua::~CScriptingLua() 
	{

	}
	// -------------------------------------
	///@brief : ExecuteFile by VM
	///@param : name of file to execute
	// -------------------------------------
	void CScriptingLua::ExecuteFile(const std::string &_strFilename)
	{
		int r = 0;

		r = luaL_dofile(m_pLuaState, _strFilename.c_str());
		if(r != 0)
		{
			m_strError = lua_tostring(m_pLuaState, -1);
			lua_pop(m_pLuaState, 1);
		}
	}
	// -------------------------------------
	///@brief : ExecuteString by VM
	///@param : string to execute
	// -------------------------------------
	void CScriptingLua::ExecuteString(const std::string &_str)
	{
		int r = 0;
		r = luaL_dostring(m_pLuaState, _str.c_str());
		if(r != 0)
		{
			m_strError = lua_tostring(m_pLuaState, -1);
			lua_pop(m_pLuaState, 1);
		}
	}
	// -------------------------------------
	/// @brief retrieve error message
	/// @return : string 
	// ------------------------------------- 
	std::string CScriptingLua::GetErrorString()
	{
		return m_strError;
	}
	// -------------------------------------
	/// @brief : start of VM, initialisation
	/// 
	// -------------------------------------
	void CScriptingLua::InitVM()
	{
		m_pLuaState = lua_open();
		luaL_openlibs(m_pLuaState);
		tolua_bindings_open(m_pLuaState);
	}
	// -------------------------------------
	/// @brief : end of VM, destroy
	/// 
	// -------------------------------------
	void CScriptingLua::ShutdownVM()
	{
		lua_close(m_pLuaState);
	}

} // namespace Scripting
