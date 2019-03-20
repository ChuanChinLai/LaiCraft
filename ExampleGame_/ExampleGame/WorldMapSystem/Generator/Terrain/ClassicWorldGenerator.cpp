//#include "ClassicWorldGenerator.h"
//
//#include <GraphicsEngine/Math/Math.h>
//#include <GraphicsEngine/Utility/Random.h>
//
//#include <ExampleGame/World/Chunk/Chunk.h>
//
//#include <iostream>
//
//namespace
//{
//	const int seed = LaiEngine::RandomSingleton::Get().intInRange(424, 325322);
//}
//
//LaiEngine::NoiseGenerator LaiEngine::ClassicWorldGenerator::m_biomeNoiseGen(seed * 2);
//
//
//LaiEngine::ClassicWorldGenerator::ClassicWorldGenerator() : m_grassBiome(seed), m_temperateForest(seed), m_desertBiome(seed), m_oceanBiome(seed), m_lightForest(seed)
//{
//	SetUpNoise();
//}
//
//void LaiEngine::ClassicWorldGenerator::GenerateTerrainFor(Chunk * chunk)
//{
//	m_pChunk = chunk;
//
//	const auto location = chunk->GetLocation();
//	m_random.setSeed((location.x ^ location.y) << 2);
//
//	GetHeightMap();
//	GetBiomeMap();
//
//	auto maxHeight = m_heightMap.GetMaxValue();
//
//	maxHeight = std::max(maxHeight, WATER_LEVEL);
//	
//	SetBlocks(maxHeight);
//}
//
//int LaiEngine::ClassicWorldGenerator::GetMinimumSpawnHeight() const noexcept
//{
//	return WATER_LEVEL;
//}
//
//
//void LaiEngine::ClassicWorldGenerator::SetBlocks(int maxHeight)
//{
//	std::vector<glm::ivec3> trees;
//	//std::vector<glm::ivec3> plants;
//
//
//	for (int y = 0; y < maxHeight + 1; y++)
//	{
//		for (int x = 0; x < CHUNK_SIZE; x++)
//		{
//			for (int z = 0; z < CHUNK_SIZE; z++)
//			{
//				int height = m_heightMap.Get(x, z);
//
//				auto& biome = GetBiome(x, z);
//
//				if (y > height)
//				{
//					if (y <= WATER_LEVEL)
//					{
//						m_pChunk->SetBlock(x, y, z, BlockType::Water);
//					}
//					continue;
//				}
//				else if (y == height)
//				{
//					if (y >= WATER_LEVEL)
//					{
//						if (y < WATER_LEVEL + 4)
//						{
//							m_pChunk->SetBlock(x, y, z, biome.GetBeachBlock(m_random));
//							continue;
//						}
//
//						if (m_random.intInRange(0, biome.GetTreeFrequency()) == 5)
//						{
//							trees.emplace_back(x, y + 1, z);
//						}
//
//						m_pChunk->SetBlock(x, y, z, GetBiome(x, z).GetTopBlock(m_random));
//					}
//					else
//					{
//						m_pChunk->SetBlock(x, y, z, biome.GetUnderWaterBlock(m_random));
//					}
//				}
//				else if (y > height - 3)
//				{
//					m_pChunk->SetBlock(x, y, z, BlockType::Dirt);
//				}
//				else
//				{
//					m_pChunk->SetBlock(x, y, z, BlockType::Gravel);
//				}
//			}
//		}
//	}
//
//	for (auto& tree : trees)
//	{
//		int x = tree.x;
//		int z = tree.z;
//
//		GetBiome(x, z).MakeTree(m_random, m_pChunk, x, tree.y, z);
//	}
//
//}
//
//void LaiEngine::ClassicWorldGenerator::GetHeightMap()
//{
//	constexpr static auto HALF_CHUNK = CHUNK_SIZE / 2;
//	constexpr static auto CHUNK = CHUNK_SIZE;
//
//	GetHeightIn(0, 0, HALF_CHUNK, HALF_CHUNK);
//	GetHeightIn(HALF_CHUNK, 0, CHUNK, HALF_CHUNK);
//	GetHeightIn(0, HALF_CHUNK, HALF_CHUNK, CHUNK);
//	GetHeightIn(HALF_CHUNK, HALF_CHUNK, CHUNK, CHUNK);
//}
//
//void LaiEngine::ClassicWorldGenerator::GetHeightIn(int xMin, int zMin, int xMax, int zMax)
//{
//	auto GetHeightAt = [&](int x, int z)
//	{
//		const Biome& biome = GetBiome(x, z);
//
//		return static_cast<float>(biome.GetHeight(x, z, m_pChunk->GetLocation().x, m_pChunk->GetLocation().y));
//	};
//
//	float bottomLeft  = GetHeightAt(xMin, zMin);
//	float bottomRight = GetHeightAt(xMax, zMin);
//	float topLeft     = GetHeightAt(xMin, zMax);
//	float topRight    = GetHeightAt(xMax, zMax);
//
//	for (int x = xMin; x < xMax; x++)
//	{
//		for (int z = zMin; z < zMax; z++)
//		{
//			if (x == CHUNK_SIZE || z == CHUNK_SIZE)
//				continue;
//
//			float h = SmoothInterpolation(bottomLeft, topLeft, bottomRight, topRight, xMin, xMax, zMin, zMax, x, z);
//
//			//std::cout << h << std::endl;
//
//			m_heightMap.Get(x, z) = static_cast<int>(h);
//		}
//	}
//}
//
//void LaiEngine::ClassicWorldGenerator::GetBiomeMap()
//{
//	const auto location = m_pChunk->GetLocation();
//
//	for (int x = 0; x < CHUNK_SIZE + 1; x++)
//	{
//		for (int z = 0; z < CHUNK_SIZE + 1; z++)
//		{
//			const int h = static_cast<int>(m_biomeNoiseGen.GetHeight(x, z, location.x + 10, location.y + 10));
//
//			m_biomeMap.Get(x, z) = h;
//		}
//	}
//}
//
//const LaiEngine::Biome & LaiEngine::ClassicWorldGenerator::GetBiome(int x, int z) const
//{
//	const int biomeValue = m_biomeMap.Get(x, z);
//
//	if (biomeValue > 160)
//	{
//		return m_oceanBiome;
//	}
//	else if (biomeValue > 150)
//	{
//		return m_grassBiome;
//	}
//	else if (biomeValue > 130)
//	{
//		return m_lightForest;
//	}
//	else if (biomeValue > 120)
//	{
//		return m_temperateForest;
//	}
//	else if (biomeValue > 110)
//	{
//		return m_lightForest;
//	}
//	else if (biomeValue > 100)
//	{
//		return m_grassBiome;
//	}
//	else
//	{
//		return m_desertBiome;
//	}
//}
//
//void LaiEngine::ClassicWorldGenerator::SetUpNoise()
//{
//	std::cout << "Seed: " << seed << '\n';
//	static bool noiseGen = false;
//	if (!noiseGen)
//	{
//		std::cout << "making noise\n";
//		noiseGen = true;
//
//		NoiseParameters biomeParmams;
//		biomeParmams.octaves = 5;
//		biomeParmams.amplitude = 120;
//		biomeParmams.smoothness = 1035;
//		biomeParmams.heightOffset = 0;
//		biomeParmams.roughness = 0.75f;
//
//		m_biomeNoiseGen.SetParameters(biomeParmams);
//	}
//}
