#pragma once

#include "../IBlock.h"

namespace LaiEngine
{
	class CactusBlock : public IBlock
	{
	public:

		CactusBlock();

	protected:

		void LoadFromLuaFile(std::string file) override;
	};
}