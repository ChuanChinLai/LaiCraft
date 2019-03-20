#pragma once

#include "Biome.h"

namespace LaiEngine
{
	class GrasslandBiome : public Biome
	{
	public:
		GrasslandBiome(int seed);

		BlockType GetBeachBlock(Rand& rand) const override;
		BlockType GetPlant(Rand& rand) const override;
		BlockType GetTopBlock(Rand& rand) const override;
		BlockType GetUnderWaterBlock(Rand& rand) const override;

		void MakeTree(Rand& rand, Chunk* chunk, int x, int y, int z) const override;

	private:
		NoiseParameters GetNoiseParameters() override;
	};
}