/********************************************************************
	created:	2009/09/12
	created:	12:10:2009   23:45
	filename: 	i:\Trab\ZShoot\Development\Sources\Rendering\SH.cpp
	file path:	i:\Trab\ZShoot\Development\Sources\Rendering
	file base:	SH
	file ext:	cpp
	author:		
	
	purpose:	
*********************************************************************/

#include "SH.h"
namespace SH
{
//----------------------------------------------------------------------------
/// @brief UpdateSHShaderConstants.
//----------------------------------------------------------------------------
void UpdateSHShaderConstants(Constants&_SHSource,Coefficients& _Values)
{

	D3DXMATRIX mWorldInv;
	D3DXMatrixIdentity(&mWorldInv);
	//DWORD dwOrder = 6;

	// Lighting environment coefficients
	D3DXVECTOR4 vCoefficients[3];
	memset( vCoefficients, 0, 3*sizeof(D3DXVECTOR4) );

	// These constants are described in the article by Peter-Pike Sloan titled 
	// "Efficient Evaluation of Irradiance Environment Maps" in the book 
	// "ShaderX 2 - Shader Programming Tips and Tricks" by Wolfgang F. Engel.

	static const float s_fSqrtPI = sqrt(D3DX_PI);
	static const float fC0 = 1.0f/(2.0f*s_fSqrtPI);
	static const float fC1 = sqrt(3.0f)/(3.0f*s_fSqrtPI);
	static const float fC2 = sqrt(15.0f)/(8.0f*s_fSqrtPI);
	static const float fC3 = sqrt(5.0f)/(16.0f*s_fSqrtPI);
	static const float fC4 = 0.5f*fC2;

	int iChannel;
	for( iChannel=0; iChannel<3; iChannel++ )
	{
		vCoefficients[iChannel].x = -fC1*_SHSource.fOriginalConstant[iChannel][3];
		vCoefficients[iChannel].y = -fC1*_SHSource.fOriginalConstant[iChannel][1];
		vCoefficients[iChannel].z =  fC1*_SHSource.fOriginalConstant[iChannel][2];
		vCoefficients[iChannel].w =  fC0*_SHSource.fOriginalConstant[iChannel][0] - fC3*_SHSource.fOriginalConstant[iChannel][6];
	}
	_Values.m_values[0] = vCoefficients[0];
	_Values.m_values[1] = vCoefficients[1];
	_Values.m_values[2] = vCoefficients[2];

	for( iChannel=0; iChannel<3; iChannel++ )
	{
		vCoefficients[iChannel].x =      fC2*_SHSource.fOriginalConstant[iChannel][4];
		vCoefficients[iChannel].y =     -fC2*_SHSource.fOriginalConstant[iChannel][5];
		vCoefficients[iChannel].z = 3.0f*fC3*_SHSource.fOriginalConstant[iChannel][6];
		vCoefficients[iChannel].w =     -fC2*_SHSource.fOriginalConstant[iChannel][7];
	}
	_Values.m_values[3] = vCoefficients[0];
	_Values.m_values[4] = vCoefficients[1];
	_Values.m_values[5] = vCoefficients[2];

	vCoefficients[0].x = fC4*_SHSource.fOriginalConstant[0][8];
	vCoefficients[0].y = fC4*_SHSource.fOriginalConstant[1][8];
	vCoefficients[0].z = fC4*_SHSource.fOriginalConstant[2][8];
	vCoefficients[0].w = 1.0f;
	_Values.m_values[6] = vCoefficients[0];

}
}// namespace SH