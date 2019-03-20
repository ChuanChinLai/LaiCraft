#include "TestGenerator.h"

#include <ExampleGame/WorldMapSystem/WorldConstants.h>
#include <ExampleGame/WorldMapSystem/Block/BlockType.h>
#include <ExampleGame/WorldMapSystem/Chunk/Chunk.h>

#include <ExampleGame/WorldMapSystem/Generator/Terrain/TerrainGenerator.h>


void LaiEngine::TestGenerator::GenerateTerrainFor(Chunk * chunk)
{
	for (int x = 0; x < CHUNK_SIZE; x++)
	{
		for (int z = 0; z < CHUNK_SIZE; z++)
		{
			chunk->SetBlock(x, 0, z, BlockType::DIRT);
		}
	}

	//chunk->SetBlock(1, 0, 0, BlockType::DIRT);
	chunk->SetBlock(0, 1, 0, BlockType::GRASS);
	//chunk->SetBlock(0, 0, 1, BlockType::DIRT);


	//Random<std::minstd_rand> rand;
	//MakeCactus(chunk, rand, 3, 2, 3);
}

int LaiEngine::TestGenerator::GetMinimumSpawnHeight() const noexcept
{
	return 1;
}
