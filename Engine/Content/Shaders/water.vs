#version 330

layout(location = 0) in vec3 i_position;
layout(location = 1) in vec3 i_normal;
layout(location = 2) in vec2 i_UV;
layout(location = 3) in vec3 i_offset;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectedMat;

uniform float globalTime;

out vec2 vertexUV;
 
 
float A = 0.2f;
float Feq = 2.0f;

vec4 PosFromWaveEqu()
{
    vec3 vertexPos = i_position + i_offset;
    vertexPos.y += A * sin((globalTime - vertexPos.x) * Feq);
    vertexPos.y += A * cos((globalTime - vertexPos.z) * Feq);
    vertexPos.y -= 0.2;
    return vec4(vertexPos, 1);
}

 
void main()
{
  gl_Position = projectedMat * viewMat * PosFromWaveEqu();
  
  vertexUV = i_UV;
}