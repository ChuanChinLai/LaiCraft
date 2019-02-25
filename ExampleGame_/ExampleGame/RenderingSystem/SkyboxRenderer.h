#pragma once

#include <Engine/Model/Model.h>
#include <Engine/Shader/SkyboxShader.h>
#include <Engine/Texture/CubeTexture.h>

namespace LaiEngine
{
	class SkyboxRenderer
	{
	public:

		SkyboxRenderer();
		~SkyboxRenderer();

		void Draw();

	private:

		void Init();

	private:

		Model        m_model;
		SkyboxShader m_shader;
		CubeTexture  m_cubeTexture;

		const float m_size = 500.0f;
	};
}