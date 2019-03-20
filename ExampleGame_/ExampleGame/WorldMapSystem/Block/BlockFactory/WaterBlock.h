#pragma once

#include "../IBlock.h"

namespace LaiEngine
{
	class WaterBlock : public IBlock
	{
	public:

		WaterBlock();

	protected:

		void LoadFromLuaFile(std::string file) override;

	};
}