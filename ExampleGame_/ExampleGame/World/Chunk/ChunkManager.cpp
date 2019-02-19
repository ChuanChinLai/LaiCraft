#include "ChunkManager.h"

#include "Chunk.h"

#include <ExampleGame/World/Generation/Terrain/ClassicWorldGenerator.h>
#include <ExampleGame/World/Generation/Terrain/SuperFlatGenerator.h>
#include <ExampleGame/World/Generation/Terrain/TestGenerator.h>

#include <iostream>


LaiEngine::ChunkManager::ChunkManager(World * world) : m_pWorld(world), m_pTerrainGenerator(nullptr)
{
	m_pTerrainGenerator = new ClassicWorldGenerator();

	for (int x = 0; x < WORLD_SIZE; x++)
	{
		for (int z = 0; z < WORLD_SIZE; z++)
		{
			const VectorXZ pos = { x, z };

			if (m_chunks.count(pos))
			{
				delete m_chunks[pos];
			}

			Chunk* chunk = new Chunk(m_pWorld, glm::ivec2(x, z));
			m_pTerrainGenerator->GenerateTerrainFor(chunk);
			m_chunks[pos] = chunk;
		}
	}
}

LaiEngine::ChunkManager::~ChunkManager()
{
	for (auto& chunk : m_chunks)
	{
		if (chunk.second != nullptr)
		{
			delete chunk.second;
		}
	}

	m_chunks.clear();


	if (m_pTerrainGenerator != nullptr)
	{
		delete m_pTerrainGenerator;
	}
}

ChunkMap & LaiEngine::ChunkManager::Get()
{
	return m_chunks;
}

LaiEngine::Chunk * LaiEngine::ChunkManager::qGetChunk(int x, int z)
{
	const VectorXZ pos = { x, z };
	return m_chunks.at(pos);
}

LaiEngine::Chunk * LaiEngine::ChunkManager::GetChunk(int x, int z)
{
	const VectorXZ pos = { x, z };

	if (!IsValid(x, z))
	{
		Chunk* chunk = new Chunk(m_pWorld, {x, z});
		m_pTerrainGenerator->GenerateTerrainFor(chunk);
		m_chunks[pos] = chunk;
	}

	return m_chunks.at(pos);
}

LaiEngine::TerrainGenerator* LaiEngine::ChunkManager::GetTerrainGenerator() const
{
	return m_pTerrainGenerator;
}

bool LaiEngine::ChunkManager::IsValid(int x, int z) const
{
	return m_chunks.count({ x, z });
}

void LaiEngine::ChunkManager::LoadChunk(const int x, const int z)
{
	GetChunk(x, z)->Load(m_pTerrainGenerator);
}

void LaiEngine::ChunkManager::UnloadChunk(const int x, const int z)
{
	if (IsValid(x, z))
	{
		const VectorXZ pos = { x, z };
		delete m_chunks[pos];
		m_chunks.erase(pos);
	}
}
