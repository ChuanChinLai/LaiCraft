#pragma once

#include "TerrainGenerator.h"

#include <Engine/Utility/Array2D.h>
#include <Engine/Utility/Random.h>
#include <Engine/Utility/NoiseGenerator.h>

#include <ExampleGame/WorldMapSystem/WorldConstants.h>

#include <ExampleGame/WorldMapSystem/Generator/Biome/DesertBiome.h>
#include <ExampleGame/WorldMapSystem/Generator/Biome/GrasslandBiome.h>
#include <ExampleGame/WorldMapSystem/Generator/Biome/LightForestBiome.h>
#include <ExampleGame/WorldMapSystem/Generator/Biome/OceanBiome.h>
#include <ExampleGame/WorldMapSystem/Generator/Biome/TemperateForestBiome.h>


namespace LaiEngine
{
	class ClassicWorldGenerator : public TerrainGenerator
	{
	public:

		ClassicWorldGenerator();

		void GenerateTerrainFor(Chunk* chunk) override;
		int  GetMinimumSpawnHeight() const noexcept override;


	private:

		void SetBlocks(int maxHeight);

		void GetHeightMap();
		void GetBiomeMap();

		void GetHeightIn(int xMin, int zMin, int xMax, int zMax);
		const Biome& GetBiome(int x, int z) const;

	private:

		Array2D<int, CHUNK_SIZE>        m_heightMap;
		Array2D<int, CHUNK_SIZE + 1>    m_biomeMap;
		Random<std::minstd_rand>        m_random;
		Chunk*                          m_pChunk = nullptr;

		GrasslandBiome          m_grassBiome;
		TemperateForestBiome    m_temperateForest;
		DesertBiome             m_desertBiome;
		OceanBiome              m_oceanBiome;
		LightForestBiome        m_lightForest;

	private:
		static void SetUpNoise();
		static NoiseGenerator m_biomeNoiseGen;
	};

}