#version 330

in vec2 vertexUV;

out vec4 o_color;

uniform sampler2D texSampler;

void main()
{
	vec4 water = texture2D(texSampler, vertexUV);
	water.w = 0.8f;
	o_color = water;
}