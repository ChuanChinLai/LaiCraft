#pragma once

#include "IChunk.h"
#include <ExampleGame/World/WorldConstants.h>

#include <ExampleGame/World/Block/ChunkBlock.h>

#include <glm/gtx/hash.hpp>

#include <unordered_map>

namespace LaiEngine
{
	class RenderMaster;
	class World; 

	class ChunkSection : public IChunk
	{
		friend class Chunk;
	public:

		ChunkSection(World* world, const glm::ivec3& position);
		~ChunkSection();

	
		void Update() override;
		void SubmitDataToBeRendered(MainRenderer* renderer) override;

		ChunkBlock* GetBlock(int x, int y, int z) override;
		void        SetBlock(int x, int y, int z, BlockType type) override;


		const glm::ivec3 GetPosition() const noexcept;

	private:
		glm::ivec3 ToWorldPosition(int x, int y, int z) const;
		int  GetIndex(int x, int y, int z) const;
		bool IsValid(int value) const;

		World*     m_pWorld;
		glm::ivec3 m_position;
		std::vector<ChunkBlock*> m_chunkBlocks;

	};
}