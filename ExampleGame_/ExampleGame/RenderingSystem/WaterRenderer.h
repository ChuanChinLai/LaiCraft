#pragma once

#include <Engine/Shader/WaterShader.h>

namespace LaiEngine
{
	class IBlock;

	class WaterRenderer
	{
	public:

		void Draw(IBlock * block);

	private:

		WaterShader m_shader;
	};
}