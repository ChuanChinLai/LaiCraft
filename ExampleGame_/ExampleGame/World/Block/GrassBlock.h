#pragma once

#include "IBlock.h"

namespace LaiEngine
{
	class GrassBlock : public IBlock 
	{
	public:

		GrassBlock();


	protected:

		void LoadFromLuaFile(std::string file) override;

	};
}