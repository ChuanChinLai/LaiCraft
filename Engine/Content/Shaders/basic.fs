#version 330

in vec2 vertexUV;

out vec4 o_color;

uniform sampler2D texSampler;

void main()
{
	vec4 textureColor = texture2D(texSampler, vertexUV);
	
    if(textureColor.rgb == vec3(1.0, 1.0, 1.0))
        discard;

	o_color = textureColor;
}