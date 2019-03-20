#include "SuperFlatGenerator.h"

#include <ExampleGame/World/WorldConstants.h>
#include <ExampleGame/World/Chunk/Chunk.h>
#include <ExampleGame/World/Block/BlockType.h>

void LaiEngine::SuperFlatGenerator::GenerateTerrainFor(Chunk* chunk)
{
	if (chunk == nullptr) return;

	const int h = CHUNK_SECTION * CHUNK_SIZE - 1;

	for (int y = 0; y < CHUNK_SECTION * CHUNK_SIZE; y++)
	{
		for (int x = 0; x < CHUNK_SIZE; ++x)
		{
			for (int z = 0; z < CHUNK_SIZE; ++z)
			{
				if (y == h)
				{
					chunk->SetBlock(x, y, z, BlockType::Water);
				}
				else if (y > h - 3)
				{
					chunk->SetBlock(x, y, z, BlockType::Dirt);
				}
				else
				{
					chunk->SetBlock(x, y, z, BlockType::Gravel);
				}
			}
		}
	}
}

int LaiEngine::SuperFlatGenerator::GetMinimumSpawnHeight() const noexcept
{
	return 1;
}
