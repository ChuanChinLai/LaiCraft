#pragma once

#include <Engine/Model/Model.h>
#include <Engine/Shader/BasicShader.h>
#include <Engine/Texture/BasicTexture.h>

namespace LaiEngine
{
	class QuadRenderer
	{
	public:
		QuadRenderer();

		void Draw();

	private:

		void Init();

	private:

		Model        m_quadModel;
		BasicShader  m_shader;
		BasicTexture m_texture;
	};
}