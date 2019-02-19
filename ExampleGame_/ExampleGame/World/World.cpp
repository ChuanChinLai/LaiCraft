#include "World.h"
#include "WorldConstants.h"

#include <Engine/Math/VectorXZ.h>
#include <Engine/GameObject/Camera.h>
#include <Engine/Utility/Random.h>

#include <ExampleGame/LaiCraft/Player.h>
#include <ExampleGame/World/Block/ChunkBlock.h>
#include <ExampleGame/World/Generation/Terrain/TerrainGenerator.h>

#include <iostream>
#include <algorithm>

LaiEngine::World::World(Player* player) : m_chunkManager(this)
{
	SetSpawnPoint();

	if (player != nullptr)
	{
		player->position = m_playerSpawnPoint; 
		player->position.y += 15;
	}

	//player->position = { 50, 100, 50 };
}

LaiEngine::World::~World()
{

}

void LaiEngine::World::Update()
{
	int m_loadDistance = 5;

	int cameraX = static_cast<int>(Camera::Get()->position.x) / CHUNK_SIZE;
	int cameraZ = static_cast<int>(Camera::Get()->position.z) / CHUNK_SIZE;

	auto& chunkManager = m_chunkManager.Get();

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

void LaiEngine::World::SubmitDataToBeRendered(MainRenderer * renderer)
{
	int renderDistance = 5;
	int cameraX = static_cast<int>(Camera::Get()->position.x) / CHUNK_SIZE;
	int cameraZ = static_cast<int>(Camera::Get()->position.z) / CHUNK_SIZE;

	int minX = cameraX - renderDistance;
	int minZ = cameraZ - renderDistance;
	int maxX = cameraX + renderDistance;
	int maxZ = cameraZ + renderDistance;

	auto& chunkManager = m_chunkManager.Get();

	//std::cout << "SIZE: " << chunkManager.size() << std::endl;

	for (auto itr = chunkManager.begin(); itr != chunkManager.end(); )
	{
		auto& chunk = itr->second;
		auto& location = chunk->GetLocation();

		if (minX < location.x && minZ < location.y && maxZ > location.y && maxX > location.x)
		{
			chunk->SubmitDataToBeRendered(renderer);
			itr++;
		}
		else
		{
			itr = chunkManager.erase(itr);
			continue;
		}
	}


	//for (auto& chunk : chunkManager)
	//{
	//	auto& location = chunk.second->GetLocation();

	//	if (minX < location.x && minZ < location.y &&
	//		maxZ > location.y && maxX > location.x)
	//	{
	//		chunk.second->SubmitDataToBeRendered(renderer);
	//	}
	//	else
	//	{
	//		//chunkManager.erase(location);
	//	}
	//}
}

LaiEngine::ChunkBlock* LaiEngine::World::GetBlock(int x, int y, int z)
{
	auto bp = GetBlockXZ(x, z);
	auto cp = GetChunkXZ(x, z);

	return m_chunkManager.GetChunk(cp.x, cp.z)->GetBlock(bp.x, y, bp.z);
}

void LaiEngine::World::SetBlock(int x, int y, int z, BlockType type)
{
	if (y <= 0) return; 

	auto bp = GetBlockXZ(x, z);
	auto cp = GetChunkXZ(x, z);

	m_chunkManager.GetChunk(cp.x, cp.z)->SetBlock(bp.x, y, bp.z, type);
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

void LaiEngine::World::SetSpawnPoint()
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
		m_chunkManager.UnloadChunk(chunkX, chunkZ);

		chunkX = RandomSingleton::Get().intInRange(100, 200);
		chunkZ = RandomSingleton::Get().intInRange(100, 200);
		blockX = RandomSingleton::Get().intInRange(0, CHUNK_SIZE - 1);
		blockZ = RandomSingleton::Get().intInRange(0, CHUNK_SIZE - 1);

		m_chunkManager.LoadChunk(chunkX, chunkZ);
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
			m_chunkManager.LoadChunk(x, z);
		}
	}

	std::cout << m_playerSpawnPoint.x << " " << m_playerSpawnPoint.y << " " << m_playerSpawnPoint.z << std::endl;
	std::cout << "Spawn found! Attempts: " << attempts << std::endl;
}
