#pragma once

#include "TerrainGenerator.h"

namespace LaiEngine
{
	class TestGenerator : public TerrainGenerator
	{
	public:
		void GenerateTerrainFor(Chunk* chunk) override;
		int  GetMinimumSpawnHeight() const noexcept override;
	};

}