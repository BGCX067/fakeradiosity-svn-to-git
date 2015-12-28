// part of the Irrlicht Engine Shader example.
// These simple Direct3D9 pixel and vertex shaders will be loaded by the shaders
// example. Please note that these example shaders don't do anything really useful. 
// They only demonstrate that shaders can be used in Irrlicht.

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
float4x4 mWorldViewProj;  // World * View * Projection transformation
float4x4 mInvWorld;       // Inverted world matrix
float4x4 mTransWorld;     // Transposed world matrix
float3 mLightPos;         // Light position
float4 mLightColor;       // Light color

float  fImpulse;
// Vertex shader output structure
struct VS_OUTPUT
{
	float4 Position   : POSITION;   // vertex position 
	float3 Normal		:TEXCOORD0;
};


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
	float3 pos = vPosition+normal*float4(fImpulse,fImpulse,fImpulse,1);
	Output.Position = mul(float4(pos,1), mWorldViewProj);
	
	return Output;
}
	
float4 pixelMain(in float3 vNormal   : TEXCOORD0 ): COLOR0 
{ 
	
	return float4(fImpulse,0,0,saturate(1-fImpulse));
}

