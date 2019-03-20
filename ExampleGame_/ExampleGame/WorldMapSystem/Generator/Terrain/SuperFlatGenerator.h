#pragma once

#include "TerrainGenerator.h"

namespace LaiEngine
{
	class SuperFlatGenerator : public TerrainGenerator
	{
	public:
		void GenerateTerrainFor(Chunk* chunk) override;
		int  GetMinimumSpawnHeight() const noexcept override;
	};

}