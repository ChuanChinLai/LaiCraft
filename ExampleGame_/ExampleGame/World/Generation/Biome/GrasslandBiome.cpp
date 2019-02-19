#include "GrasslandBiome.h"

#include <ExampleGame/World/Generation/Structures/TreeGenerator.h>

LaiEngine::GrasslandBiome::GrasslandBiome(int seed) : Biome(GetNoiseParameters(), 1000, 20, seed)
{

}

LaiEngine::BlockType LaiEngine::GrasslandBiome::GetBeachBlock(Rand & rand) const
{
	return rand.intInRange(0, 10) > 2 ? BlockType::Grass : BlockType::Dirt;
}

LaiEngine::BlockType LaiEngine::GrasslandBiome::GetPlant(Rand & rand) const
{
	return BlockType::Grass;
}

LaiEngine::BlockType LaiEngine::GrasslandBiome::GetTopBlock(Rand & rand) const
{
	return BlockType::Grass;
}

LaiEngine::BlockType LaiEngine::GrasslandBiome::GetUnderWaterBlock(Rand & rand) const
{
	return rand.intInRange(0, 10) > 8 ? BlockType::Dirt : BlockType::Sand;
}

void LaiEngine::GrasslandBiome::MakeTree(Rand & rand, Chunk * chunk, int x, int y, int z) const
{
	MakeOakTree(chunk, rand, x, y, z);
}

LaiEngine::NoiseParameters LaiEngine::GrasslandBiome::GetNoiseParameters()
{
	NoiseParameters heightParams;
	heightParams.octaves = 9;
	heightParams.amplitude = 85;
	heightParams.smoothness = 235;
	heightParams.heightOffset = -20;
	heightParams.roughness = 0.51f;

	return heightParams;
}
