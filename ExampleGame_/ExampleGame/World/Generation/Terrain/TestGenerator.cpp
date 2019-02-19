#include "TestGenerator.h"

#include <ExampleGame/World/WorldConstants.h>
#include <ExampleGame/World/Chunk/Chunk.h>
#include <ExampleGame/World/Block/BlockType.h>

#include <ExampleGame/World/Generation/Structures/TreeGenerator.h>


void LaiEngine::TestGenerator::GenerateTerrainFor(Chunk * chunk)
{
	for (int x = 0; x < CHUNK_SIZE; x++)
	{
		for (int z = 0; z < CHUNK_SIZE; z++)
		{
			chunk->SetBlock(x, 0, z, BlockType::Dirt);
		}
	}

	chunk->SetBlock(3, 1, 3, BlockType::Grass);

	
	Random<std::minstd_rand> rand;
	MakeCactus(chunk, rand, 3, 2, 3);
}

int LaiEngine::TestGenerator::GetMinimumSpawnHeight() const noexcept
{
	return 1;
}
