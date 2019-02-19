#pragma once

#include "IBlock.h"

namespace LaiEngine
{
	class DirtBlock : public IBlock
	{
	public:

		DirtBlock();

	protected:

		void LoadFromLuaFile(std::string file) override;

	};
}