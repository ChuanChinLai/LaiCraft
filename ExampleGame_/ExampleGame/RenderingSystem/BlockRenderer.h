#pragma once

#include <Engine/Shader/BasicShader.h>
#include <Engine/Texture/basictexture.h>

namespace LaiEngine
{
	class IBlock; 

	class BlockRenderer
	{
	public:

		BlockRenderer();

		void Draw(IBlock* block);

	private:

		BasicShader  m_shader;
		BasicTexture m_texture;
	};
}