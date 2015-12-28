/********************************************************************
	created:	2009/08/20
	created:	20:8:2009   17:07
	filename: 	i:\Trab\ZShoot\Development\Sources\InputConfig.h
	file path:	i:\Trab\ZShoot\Development\Sources
	file base:	InputConfig
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/

#ifndef _INPUTCONFIG_H_
#define _INPUTCONFIG_H_
#include <irrlicht.h>
#include <map>
#include <string>

class InputConfig
{

private:
	

	
public:
	InputConfig(){}
	~InputConfig(){}
	static std::map<std::string,InputConfig*> gs_mapInputConfig;
	irr::EKEY_CODE m_eUp;
	irr::EKEY_CODE m_eDown;
	irr::EKEY_CODE m_eRight;
	irr::EKEY_CODE m_eLeft;
	irr::EKEY_CODE m_eShoot;
	std::string m_strName;
	void SetName(const char* _s ){m_strName=_s;}

	void SetKeyUp(int _e) { m_eUp =(irr::EKEY_CODE) _e;}
	void SetKeyDown(int _e){ m_eDown = (irr::EKEY_CODE)_e;}
	void SetKeyRight(int _e){ m_eRight = (irr::EKEY_CODE)_e;}
	void SetKeyLeft(int _e){ m_eLeft = (irr::EKEY_CODE)_e;}
	void SetKeyShoot(int _e){ m_eShoot = (irr::EKEY_CODE)_e;}
	void SetJoyPort(int i ){}
	void Register();
};
#endif //_INPUTCONFIG_H_
