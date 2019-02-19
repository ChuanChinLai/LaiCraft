#version 330

layout(location = 0) in vec3 i_position;
layout(location = 1) in vec3 i_normal;
layout(location = 2) in vec2 i_UV;
layout(location = 3) in vec3 i_offset;

uniform mat4 modelMat;
uniform mat4 viewMat;
uniform mat4 projectedMat;


out vec2 vertexUV;
 
void main()
{
  gl_Position = projectedMat * viewMat * vec4(i_position + i_offset, 1.0);
  
  vertexUV = i_UV;
}