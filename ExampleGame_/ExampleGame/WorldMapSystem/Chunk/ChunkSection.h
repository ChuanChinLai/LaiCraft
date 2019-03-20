#pragma once

#include <ExampleGame/WorldMapSystem/Block/BlockType.h>

#include <glm/gtx/hash.hpp>

#include <unordered_map>

namespace LaiEngine
{
	class ChunkBlock;
	class World; 

	class ChunkSection
	{
		friend class Chunk;
	public:

		ChunkSection(World* world, const glm::ivec3& location);
		~ChunkSection();

	
		void Update();
		void Draw();

		ChunkBlock* GetBlock(int x, int y, int z);
		void        SetBlock(int x, int y, int z, const BlockType& type);


		const glm::ivec3& GetPosition() const noexcept;

	private:
		glm::ivec3 ToWorldPosition(int x, int y, int z) const;
		int  GetIndex(int x, int y, int z) const;
		bool IsValid(int value) const;

		World*     m_pWorld;
		glm::ivec3 m_position;
		std::vector<ChunkBlock*> m_chunkBlocks;
	};
}