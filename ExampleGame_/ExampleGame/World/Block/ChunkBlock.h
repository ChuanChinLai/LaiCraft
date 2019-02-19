#pragma once

#include "BlockType.h"

#include "BlockData.h"

#include <glm/vec3.hpp>

namespace LaiEngine
{
	class BlockData;

	class ChunkBlock : public NonCopyable
	{
	public:
		ChunkBlock() = default;

		ChunkBlock(BlockType id);

		const glm::vec3& GetPosition() const;
		void  SetPosition(const glm::vec3& position);

		const BlockData& GetData() const;
		const BlockType& GetType() const;

		bool IsCollidable() const;

		bool operator ==(const ChunkBlock& other);
		bool operator !=(const ChunkBlock& other);

	private:

		BlockData m_data;
		BlockType m_id;
	};

}