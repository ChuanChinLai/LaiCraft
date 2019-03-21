#include "OceanBiome.h"

#include <ExampleGame/WorldMapSystem/Generator/Structures/TreeGenerator.h>

LaiEngine::OceanBiome::OceanBiome(int seed) : Biome(GetNoiseParameters(), 50, 100, seed)
{

}

LaiEngine::BlockType LaiEngine::OceanBiome::GetPlant(Rand & rand) const
{
	return BlockType::GRASS;
}

LaiEngine::BlockType LaiEngine::OceanBiome::GetTopBlock(Rand & rand) const
{
	return BlockType::GRASS;
}

LaiEngine::BlockType LaiEngine::OceanBiome::GetUnderWaterBlock(Rand & rand) const
{
	return BlockType::SAND;
}

void LaiEngine::OceanBiome::MakeTree(Rand & rand, Chunk * chunk, int x, int y, int z) const
{
	rand.intInRange(0, 5) < 3 ? MakePalmTree(chunk, rand, x, y, z) : MakeOakTree(chunk, rand, x, y, z);
}

LaiEngine::NoiseParameters LaiEngine::OceanBiome::GetNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.octaves = 7;
	heightParams.amplitude = 43;
	heightParams.smoothness = 55;
	heightParams.heightOffset = 0;
	heightParams.roughness = 0.50;

	return heightParams;
}
