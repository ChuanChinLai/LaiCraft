#pragma once

#include <Engine/Math/VectorXZ.h>

#include <ExampleGame/WorldMapSystem/Block/BlockType.h>
#include <ExampleGame/WorldMapSystem/Chunk/ChunkManager.h>

#include <glm/vec3.hpp>

#include <vector>
#include <mutex>
#include <unordered_map>

namespace LaiEngine
{
	class Character;
	class ChunkBlock;
	class Chunk;
	class Player;
	class WorldMapSystem;

	class World
	{
	public:

		World(WorldMapSystem* system);
		~World();

		void Update();
		void Draw();

		ChunkBlock*  GetBlock(int x, int y, int z);
		void         SetBlock(int x, int y, int z, const BlockType& type);

		static VectorXZ GetBlockXZ(int x, int z);
		static VectorXZ GetChunkXZ(int x, int z);

		void SetSpawnPoint(Character& character);

	private:

		bool IsValid(const LaiEngine::VectorXZ& chunkPos) const;

		ChunkManager        m_chunkManager;
		glm::vec3           m_playerSpawnPoint;

		WorldMapSystem* m_pSystem;
	};

}
