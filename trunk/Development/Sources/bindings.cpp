/*
** Lua binding: bindings
** Generated automatically by tolua++-1.0.92 on 10/13/09 23:06:27.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_bindings_open (lua_State* tolua_S);

#include <irrlicht.h>
using namespace irr;

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
}

/* Open function */
TOLUA_API int tolua_bindings_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"X",0);
  tolua_beginmodule(tolua_S,"X");
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_bindings (lua_State* tolua_S) {
 return tolua_bindings_open(tolua_S);
};
#endif

