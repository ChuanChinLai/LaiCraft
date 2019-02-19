#pragma once

#include <Engine/Utility/NoiseGenerator.h>
#include <Engine/Utility/Random.h>

#include <ExampleGame/World/Block/ChunkBlock.h>
#include <ExampleGame/World/Chunk/Chunk.h>

using Rand = LaiEngine::Random<std::minstd_rand>;

namespace LaiEngine
{
	class Biome
	{
	public:
		Biome(const NoiseParameters& parameters, int treeFreq, int plantFreq, int seed);
		virtual ~Biome() = default;

		virtual BlockType GetPlant(Rand& rand) const = 0;
		virtual BlockType GetTopBlock(Rand& rand) const = 0;
		virtual BlockType GetUnderWaterBlock(Rand& rand) const = 0;
		virtual BlockType GetBeachBlock(Rand& rand) const;

		virtual void MakeTree(Rand& rand, Chunk* chunk, int x, int y, int z) const = 0;

		int GetHeight(int x, int z, int chunkX, int chunkZ) const;
		int GetTreeFrequency() const noexcept;
		int GetPlantFrequency() const noexcept;

	protected:
		virtual NoiseParameters GetNoiseParameters() = 0;

	private:
		NoiseGenerator m_heightGenerator;
		int m_treeFreq;
		int m_plantFreq;
	};

}