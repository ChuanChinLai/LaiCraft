#pragma once

#include "IRenderer.h"

#include <GraphicsEngine/Model/Model.h>
#include <GraphicsEngine/Shader/BasicShader.h>
#include <GraphicsEngine/Texture/BasicTexture.h>

#include <glm/vec3.hpp>
#include <vector>

namespace LaiEngine
{
	class GameObject; 

	class QuadRenderer : public IRenderer
	{
	public:
		QuadRenderer();

		void Render() override;

	private:

		Model m_quadModel;
		BasicShader m_shader;
		BasicTexture m_texture;
	};
}