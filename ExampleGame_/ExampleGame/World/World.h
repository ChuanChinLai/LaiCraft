#pragma once

#include <Engine/Math/VectorXZ.h>

#include <ExampleGame/World/Chunk/Chunk.h>
#include <ExampleGame/World/Chunk/ChunkManager.h>
#include <ExampleGame/World/Block/ChunkBlock.h>

#include <vector>
#include <mutex>
#include <unordered_map>

namespace LaiEngine
{
	class Player;
	class Chunk;
	class MainRenderer; 

	class World : IChunk
	{
	public:

		World(Player* player);
		~World();

		void Update() override;
		void SubmitDataToBeRendered(MainRenderer* renderer) override;

		ChunkBlock*  GetBlock(int x, int y, int z) override;
		void         SetBlock(int x, int y, int z, BlockType type) override;

		static VectorXZ GetBlockXZ(int x, int z);
		static VectorXZ GetChunkXZ(int x, int z);

	private:

		bool IsValid(const LaiEngine::VectorXZ& chunkPos) const;

		void SetSpawnPoint();

		std::vector<Chunk*> m_changedChunks;
		ChunkManager        m_chunkManager;
		glm::vec3           m_playerSpawnPoint;
	};

}
