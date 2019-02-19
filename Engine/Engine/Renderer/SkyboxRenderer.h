#pragma once

#include "IRenderer.h"

#include <Engine/Model/Model.h>
#include <Engine/Shader/SkyboxShader.h>
#include <Engine/Texture/CubeTexture.h>

namespace LaiEngine
{
	class SkyboxRenderer : public IRenderer
	{
	public:

		SkyboxRenderer();
		~SkyboxRenderer();

		void Draw() override;

	private:

		void BuildSkyboxModel();

	private:

		Model        m_model;
		SkyboxShader m_shader;
		CubeTexture  m_cubeTexture;

		const float m_size = 500.0f;
	};
}