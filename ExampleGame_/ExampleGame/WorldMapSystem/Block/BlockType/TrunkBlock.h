#pragma once

#include "IBlock.h"

namespace LaiEngine
{
	class TrunkBlock : public IBlock
	{
	public:

		TrunkBlock();

	protected:

		void LoadFromLuaFile(std::string file) override;
	};
}