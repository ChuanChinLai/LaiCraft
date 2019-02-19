#include "ChunkBlock.h"

#include "BlockDatabase.h"


LaiEngine::ChunkBlock::ChunkBlock(BlockType id) : m_id(id)
{
	m_data.SetBlock(id);
}

const glm::vec3& LaiEngine::ChunkBlock::GetPosition() const
{
	return m_data.GetPosition();
}

void LaiEngine::ChunkBlock::SetPosition(const glm::vec3 & position)
{
	m_data.SetPosition(position);
}

const LaiEngine::BlockData & LaiEngine::ChunkBlock::GetData() const
{
	return m_data;
}

const LaiEngine::BlockType & LaiEngine::ChunkBlock::GetType() const
{
	return m_id;
}

bool LaiEngine::ChunkBlock::IsCollidable() const
{
	return m_data.IsCollidable();
}

bool LaiEngine::ChunkBlock::operator==(const ChunkBlock & other)
{
	return m_id == other.m_id;
}

bool LaiEngine::ChunkBlock::operator!=(const ChunkBlock & other)
{
	return m_id != other.m_id;
}

