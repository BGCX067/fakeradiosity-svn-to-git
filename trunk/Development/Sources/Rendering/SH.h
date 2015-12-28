/********************************************************************
	created:	2009/09/12
	created:	12:10:2009   22:54
	filename: 	i:\Trab\ZShoot\Development\Sources\Rendering\SH.h
	file path:	i:\Trab\ZShoot\Development\Sources\Rendering
	file base:	SH
	file ext:	h
	author:		
	
	purpose:	
*********************************************************************/
#ifndef _SH_H_
#define _SH_H_
#include "d3dx9.h"
namespace SH
{
	struct Constants
	{
		float fOriginalConstant[3][D3DXSH_MAXORDER*D3DXSH_MAXORDER];  
	};
	struct Coefficients
	{
		D3DXVECTOR4 m_values[7];  
	};
	void UpdateSHShaderConstants(Constants&_SHSource,Coefficients& _Values);

}



#endif // _SH_H_