#pragma once

#include "IRenderer.h"

#include <Engine/Shader/WaterShader.h>

namespace LaiEngine
{
	class WaterRenderer : public IRenderer
	{
	public:

		void Draw() override;

	private:

		WaterShader m_shader;
	};
}