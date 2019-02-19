#pragma once

#include "IRenderer.h"

#include <Engine/Shader/BasicShader.h>

namespace LaiEngine
{
	class ChunkRenderer : public IRenderer
	{
	public:

		void Draw() override;

	private:

		BasicShader m_shader;
	};
}