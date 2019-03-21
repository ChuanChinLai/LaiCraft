#pragma once

#include <Engine/Shader/WaterShader.h>
#include <Engine/Texture/basictexture.h>

namespace LaiEngine
{
	class IBlock;

	class WaterRenderer
	{
	public:

		WaterRenderer();

		void Draw(IBlock * block);

	private:

		WaterShader m_shader;
		BasicTexture m_texture;
	};
}