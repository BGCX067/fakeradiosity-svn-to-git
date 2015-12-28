// part of the Irrlicht Engine Shader example.
// These simple Direct3D9 pixel and vertex shaders will be loaded by the shaders
// example. Please note that these example shaders don't do anything really useful. 
// They only demonstrate that shaders can be used in Irrlicht.

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
float4x4 mWorldViewProj;  // World * View * Projection transformation
float4x4 mInvWorld;       // Inverted world matrix
float4x4 mWorld;     // Transposed world matrix
float3 mLightPos;         // Light position
float4 mLightColor;       // Light color

float  fImpulse;
float4x4 ColorCubeNodeWorld;
float4x4 InvColorCubeNodeWorld;
//float4 CubePosition;
// Vertex shader output structure
struct VS_OUTPUT
{
	float4 Position   : POSITION;   // vertex position 
	float3 Normal		:TEXCOORD0;
	float3 WorldPos		:TEXCOORD1;
};
struct SHConstant
{
	float4 coef[7];
};
SHConstant SHConstants[8];
float3 SHProbesPositions[8];

float3 ComputeDiffuseSH(float4 Normal,SHConstant _kCoefficients)
{
	float3 x1, x2, x3;
	// Linear + constant polynomial terms
	x1.r = dot(_kCoefficients.coef[0],Normal);
	x1.g = dot(_kCoefficients.coef[1],Normal);
	x1.b = dot(_kCoefficients.coef[2],Normal);

	// 4 of the quadratic polynomials
	float4 vB = Normal.xyzz * Normal.yzzx;   
	x2.r = dot(_kCoefficients.coef[3],vB);
	x2.g = dot(_kCoefficients.coef[4],vB);
	x2.b = dot(_kCoefficients.coef[5],vB);

	// Final quadratic polynomial
	float vC = Normal.x*Normal.x - Normal.y*Normal.y;
	x3 = _kCoefficients.coef[6] * vC;    
	return  (x1 + x2 + x3);
}


VS_OUTPUT vertexMain( in float4 vPosition : POSITION,
                      in float3 vNormal   : NORMAL,
                      float2 texCoord     : TEXCOORD0 )
{
	VS_OUTPUT Output;

	
	// transform normal 
	float3 normal = mul(vNormal, mInvWorld);
	
	// renormalize normal 
	Output.Normal = normal = normalize(normal);
	// transform position to clip space 
	float3 pos = vPosition;
	Output.Position = mul(float4(pos,1), mWorldViewProj);
	Output.WorldPos = mul(float4(pos,1), mWorld);
	
	return Output;
}
	
float4 pixelMain(in VS_OUTPUT In ): COLOR0 
{ 

	float3 N = -In.Normal;
	const int numSH = 2;
	float3 c = 0;
	float min_d  =1;
	float min_dao  =1;

	float3 L = float3(0,1,0);
	for (int i = 0 ;i<numSH;i++)
	{
		// do the calculation in the space of the RadiantObject
		float3 shprobePos = mul(float4(SHProbesPositions[i],1),ColorCubeNodeWorld).xyz;
		float3 NProbeSpace = mul(N,InvColorCubeNodeWorld).xyz;
		float3 LProbeSpace = mul(L,InvColorCubeNodeWorld).xyz;

		float dist = distance(shprobePos,In.WorldPos);
		SHConstant kConstant = SHConstants[i];
		min_d = min(min_d,saturate(1-5/(dist*dist)));
		min_dao = min(min_dao,saturate(1-4/(dist*dist)));
		float coefLambert=max(0,dot(NProbeSpace,LProbeSpace));
		c+=ComputeDiffuseSH(float4(NProbeSpace,1),SHConstants[i])*max(0,dot(In.Normal,(shprobePos-In.WorldPos)));
	}
	
	float d = distance(SHProbesPositions[0],In.WorldPos.rgb);
	float3 cf = ComputeDiffuseSH(float4(N,1),SHConstants[0]);
	cf.rgb = lerp(cf.rgb,float3(0.5,0.5,0.5),saturate(d/10.0f));
	c.rgb = lerp(c.rgb,float3(0.0,0.0,0.0),min_d);
	//c.rgb =max(0,dot(N,L));;
	//return float4(min_d,min_d,min_d,1);
	return float4(c,1);
}

 