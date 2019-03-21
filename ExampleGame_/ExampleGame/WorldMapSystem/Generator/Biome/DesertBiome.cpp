#include "DesertBiome.h"

#include <ExampleGame/WorldMapSystem/Generator/Structures/TreeGenerator.h>

LaiEngine::DesertBiome::DesertBiome(int seed) : Biome(GetNoiseParameters(), 1350, 500, seed)
{

}

LaiEngine::BlockType LaiEngine::DesertBiome::GetPlant(Rand & rand) const
{
	return BlockType::SAND;
}

LaiEngine::BlockType LaiEngine::DesertBiome::GetTopBlock(Rand & rand) const
{
	return BlockType::SAND;
}

LaiEngine::BlockType LaiEngine::DesertBiome::GetUnderWaterBlock(Rand & rand) const
{
	return BlockType::SAND;
}

void LaiEngine::DesertBiome::MakeTree(Rand & rand, Chunk * chunk, int x, int y, int z) const
{
	if (y < WATER_LEVEL + 15)
	{
		if (rand.intInRange(0, 100) > 75)
		{
			MakePalmTree(chunk, rand, x, y, z);
		}
		else
		{
			MakeCactus(chunk, rand, x, y, z);
		}
	}
	else
	{
		MakeCactus(chunk, rand, x, y, z);
	}
}

LaiEngine::NoiseParameters LaiEngine::DesertBiome::GetNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.octaves = 9;
	heightParams.amplitude = 80;
	heightParams.smoothness = 335;
	heightParams.heightOffset = -7;
	heightParams.roughness = 0.56f;

	return heightParams;
}
