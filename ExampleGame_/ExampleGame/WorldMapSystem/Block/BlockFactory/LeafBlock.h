#pragma once

#include "../IBlock.h"

namespace LaiEngine
{
	class LeafBlock : public IBlock
	{
	public:

		LeafBlock();

	protected:

		void LoadFromLuaFile(std::string file) override;
	};
}