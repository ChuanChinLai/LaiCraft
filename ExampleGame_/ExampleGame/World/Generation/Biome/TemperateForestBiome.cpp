#include "TemperateForestBiome.h"

#include <ExampleGame/World/Generation/Structures/TreeGenerator.h>

LaiEngine::TemperateForestBiome::TemperateForestBiome(int seed) : Biome(GetNoiseParameters(), 55, 75, seed)
{

}

LaiEngine::BlockType LaiEngine::TemperateForestBiome::GetPlant(Rand & rand) const
{
	return BlockType::Grass;
}

LaiEngine::BlockType LaiEngine::TemperateForestBiome::GetTopBlock(Rand & rand) const
{
	return rand.intInRange(0, 10) < 8 ? BlockType::Grass : BlockType::Dirt;
}

LaiEngine::BlockType LaiEngine::TemperateForestBiome::GetUnderWaterBlock(Rand & rand) const
{
	return rand.intInRange(0, 10) > 8 ? BlockType::Dirt : BlockType::Sand;
}

void LaiEngine::TemperateForestBiome::MakeTree(Rand & rand, Chunk * chunk, int x, int y, int z) const
{
	MakeOakTree(chunk, rand, x, y, z);
}

LaiEngine::NoiseParameters LaiEngine::TemperateForestBiome::GetNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.octaves = 5;
	heightParams.amplitude = 100;
	heightParams.smoothness = 195;
	heightParams.heightOffset = -30;
	heightParams.roughness = 0.52f;

	return heightParams;
}
