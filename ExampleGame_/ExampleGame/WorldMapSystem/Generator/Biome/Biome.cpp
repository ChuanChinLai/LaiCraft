#include "Biome.h"

LaiEngine::Biome::Biome(const NoiseParameters & parameters, int treeFreq, int plantFreq, int seed) : m_heightGenerator(seed) , m_treeFreq(treeFreq) , m_plantFreq(plantFreq)
{
	m_heightGenerator.SetParameters(parameters);
}


LaiEngine::BlockType LaiEngine::Biome::GetBeachBlock(Rand & rand) const
{
	return BlockType::SAND;
}

int LaiEngine::Biome::GetHeight(int x, int z, int chunkX, int chunkZ) const
{
	return static_cast<int>(m_heightGenerator.GetHeight(x, z, chunkX, chunkZ));
}

int LaiEngine::Biome::GetTreeFrequency() const noexcept
{
	return m_treeFreq;
}

int LaiEngine::Biome::GetPlantFrequency() const noexcept
{
	return m_plantFreq;
}
