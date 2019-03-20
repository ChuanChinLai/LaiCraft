#pragma once

#include "Biome.h"

namespace LaiEngine
{
	class LightForestBiome : public Biome
	{
	public:

		LightForestBiome(int seed);

		BlockType GetPlant(Rand& rand) const override;
		BlockType GetTopBlock(Rand& rand) const override;
		BlockType GetUnderWaterBlock(Rand& rand) const override;

		void MakeTree(Rand& rand, Chunk* chunk, int x, int y, int z) const override;


	private:
		NoiseParameters GetNoiseParameters() override;
	};
}