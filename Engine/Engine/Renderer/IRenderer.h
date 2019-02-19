#pragma once

#include <vector>

namespace LaiEngine
{
	class IRenderer
	{
	public:
		IRenderer() = default;
		virtual ~IRenderer(); 
		virtual void Draw() = 0;
	};
}