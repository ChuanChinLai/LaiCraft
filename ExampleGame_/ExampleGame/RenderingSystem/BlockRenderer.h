#pragma once

#include <Engine/Shader/BasicShader.h>

namespace LaiEngine
{
	class IBlock; 

	class BlockRenderer
	{
	public:

		void Draw(IBlock* block);

	private:

		BasicShader m_shader;
	};
}