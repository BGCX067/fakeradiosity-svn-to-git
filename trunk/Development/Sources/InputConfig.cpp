/********************************************************************
	created:	2009/08/20
	created:	20:8:2009   17:23
	filename: 	i:\Trab\ZShoot\Development\Sources\InputConfig.cpp
	file path:	i:\Trab\ZShoot\Development\Sources
	file base:	InputConfig
	file ext:	cpp
	author:		
	
	purpose:	
*********************************************************************/
#include "InputConfig.h"

std::map<std::string,InputConfig*> InputConfig::gs_mapInputConfig;
void InputConfig::Register()
{
	gs_mapInputConfig[m_strName] = this;
	return;
}
