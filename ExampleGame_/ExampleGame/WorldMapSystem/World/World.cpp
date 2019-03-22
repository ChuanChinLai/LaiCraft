#include "World.h"

#include <Engine/GameObject/Camera.h>
#include <Engine/Utility/Random.h>


#include <ExampleGame/CharacterSystem/Character.h>
#include <ExampleGame/WorldMapSystem/WorldConstants.h>
#include <ExampleGame/WorldMapSystem/Block/BlockType.h>
#include <ExampleGame/WorldMapSystem/Chunk/Chunk.h>
#include <ExampleGame/WorldMapSystem/Chunk/ChunkManager.h>

#include <ExampleGame/WorldMapSystem/WorldMapSystem.h>
#include <ExampleGame/WorldMapSystem/Generator/Terrain/TerrainGenerator.h>


#include <iostream>
#include <algorithm>

LaiEngine::World::World(WorldMapSystem* system) : m_pSystem(system), m_chunkManager(this)
{

}

LaiEngine::World::~World()
{

}

void LaiEngine::World::Update()
{
	int m_loadDistance = 8;

	int cameraX = static_cast<int>(Camera::Instance()->position.x) / CHUNK_SIZE;
	int cameraZ = static_cast<int>(Camera::Instance()->position.z) / CHUNK_SIZE;

	for (int i = 0; i < m_loadDistance; i++)
	{
		int minX = std::max(cameraX - i, 0);
		int minZ = std::max(cameraZ - i, 0);
		int maxX = cameraX + i;
		int maxZ = cameraZ + i;

		for (int x = minX; x < maxX; x++)
		{
			for (int z = minZ; z < maxZ; z++)
			{
				m_chunkManager.GetChunk(x, z);
			}
		}
	}
}

void LaiEngine::World::Draw()
{
	int renderDistance = 8;
	int cameraX = static_cast<int>(Camera::Instance()->position.x) / CHUNK_SIZE;
	int cameraZ = static_cast<int>(Camera::Instance()->position.z) / CHUNK_SIZE;

	int minX = cameraX - renderDistance;
	int minZ = cameraZ - renderDistance;
	int maxX = cameraX + renderDistance;
	int maxZ = cameraZ + renderDistance;

	auto& chunkMap = m_chunkManager.Get();

	for (auto itr = chunkMap.begin(); itr != chunkMap.end(); )
	{
		auto& chunk = itr->second;
		auto& location = chunk->GetLocation();

		if (minX < location.x && minZ < location.y && maxZ > location.y && maxX > location.x)
		{
			chunk->Draw();
			itr++;
		}
		else
		{
			if (chunk != nullptr)
			{
				delete chunk;
			}

			itr = chunkMap.erase(itr);
			continue;
		}
	}
}

LaiEngine::ChunkBlock* LaiEngine::World::GetBlock(int x, int y, int z)
{
	auto cp = GetChunkXZ(x, z);
	auto bp = GetBlockXZ(x, z);

	LaiEngine::Chunk* chunk = m_chunkManager.GetChunk(cp.x, cp.z);

	return chunk->GetBlock(bp.x, y, bp.z);
}

void LaiEngine::World::SetBlock(int x, int y, int z, const BlockType& type)
{
	if (y <= 0) return; 

	auto bp = GetBlockXZ(x, z);
	auto cp = GetChunkXZ(x, z);

	LaiEngine::Chunk* chunk = m_chunkManager.GetChunk(cp.x, cp.z);
	chunk->SetBlock(bp.x, y, bp.z, type);
}



LaiEngine::VectorXZ LaiEngine::World::GetBlockXZ(int x, int z)
{
	return
	{
		x % CHUNK_SIZE,
		z % CHUNK_SIZE
	};
}

LaiEngine::VectorXZ LaiEngine::World::GetChunkXZ(int x, int z)
{
	return
	{
		x / CHUNK_SIZE,
		z / CHUNK_SIZE
	};
}

bool LaiEngine::World::IsValid(const LaiEngine::VectorXZ & chunkPos) const
{
	if (chunkPos.x < 0) return false;
	if (chunkPos.z < 0) return false;
	if (chunkPos.x >= WORLD_SIZE) return false;
	if (chunkPos.z >= WORLD_SIZE) return false;

	return true;
}

void LaiEngine::World::SetSpawnPoint(Character& character)
{
	std::cout << "Searching for spawn...\n";
	int attempts = 0;
	int chunkX = -1;
	int chunkZ = -1;
	int blockX = 0;
	int blockZ = 0;
	int blockY = 0;

	const auto h = m_chunkManager.GetTerrainGenerator()->GetMinimumSpawnHeight();

	while (blockY <= h)
	{
		m_chunkManager.Unload(chunkX, chunkZ);

		chunkX = RandomSingleton::Get().intInRange(100, 200);
		chunkZ = RandomSingleton::Get().intInRange(100, 200);
		blockX = RandomSingleton::Get().intInRange(0, CHUNK_SIZE - 1);
		blockZ = RandomSingleton::Get().intInRange(0, CHUNK_SIZE - 1);

		m_chunkManager.Load(chunkX, chunkZ);
		blockY = m_chunkManager.GetChunk(chunkX, chunkZ)->GetHeightAt(blockX, blockZ);
		attempts++;
	}

	int worldX = chunkX * CHUNK_SIZE + blockX;
	int worldZ = chunkZ * CHUNK_SIZE + blockZ;

	m_playerSpawnPoint = { worldX, blockY, worldZ };

	for (int x = worldX - 1; x <= worldX + 1; ++x)
	{
		for (int z = worldZ - 1; z <= worldZ + 1; ++z)
		{
			//std::unique_lock<std::mutex> lock(m_mainMutex);
			m_chunkManager.Load(x, z);
		}
	}

	character.position = m_playerSpawnPoint;

	std::cout << m_playerSpawnPoint.x << " " << m_playerSpawnPoint.y << " " << m_playerSpawnPoint.z << std::endl;
	std::cout << "Spawn found! Attempts: " << attempts << std::endl;
}
