#pragma once


#include "IBlock.h"

namespace LaiEngine
{
	class SandBlock : public IBlock
	{
	public:

		SandBlock();

	protected:

		void LoadFromLuaFile(std::string file) override;

	};
}