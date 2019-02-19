#pragma once

#include "IBlock.h"

namespace LaiEngine
{
	class GravelBlock : public IBlock
	{
	public:

		GravelBlock();

	protected:

		void LoadFromLuaFile(std::string file) override;

	};
}