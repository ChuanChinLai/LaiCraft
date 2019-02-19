#include "LightForestBiome.h"

#include <ExampleGame/World/Generation/Structures/TreeGenerator.h>

LaiEngine::LightForestBiome::LightForestBiome(int seed) : Biome(GetNoiseParameters(), 60, 80, seed)
{
}

LaiEngine::BlockType LaiEngine::LightForestBiome::GetPlant(Rand & rand) const
{
	return BlockType::Grass;
}

LaiEngine::BlockType LaiEngine::LightForestBiome::GetTopBlock(Rand & rand) const
{
	return BlockType::Grass;
}

LaiEngine::BlockType LaiEngine::LightForestBiome::GetUnderWaterBlock(Rand & rand) const
{
	return rand.intInRange(0, 10) > 9 ? BlockType::Sand : BlockType::Dirt;
}

void LaiEngine::LightForestBiome::MakeTree(Rand & rand, Chunk * chunk, int x, int y, int z) const
{
	MakeOakTree(chunk, rand, x, y, z);
}

LaiEngine::NoiseParameters LaiEngine::LightForestBiome::GetNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.octaves = 5;
	heightParams.amplitude = 100;
	heightParams.smoothness = 195;
	heightParams.heightOffset = -32;
	heightParams.roughness = 0.52f;

	return heightParams;
}
