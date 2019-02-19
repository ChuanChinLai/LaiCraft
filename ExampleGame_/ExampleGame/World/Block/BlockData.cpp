#include "BlockData.h"
#include "BlockDatabase.h"

#include <Engine/GameObject/GameObject.h>
#include <ExampleGame/World/Block/IBlock.h>

LaiEngine::BlockData::BlockData() : m_pBlock(nullptr)
{

}


LaiEngine::BlockData::~BlockData()
{
	m_pBlock = nullptr;
}

const glm::vec3& LaiEngine::BlockData::GetPosition() const
{
	return m_GameObject.position;
}

void LaiEngine::BlockData::SetPosition(const glm::vec3 & position)
{
	m_GameObject.position = position;
}

void LaiEngine::BlockData::SetBlock(const BlockType type)
{
	m_pBlock = BlockDatabase::GetBlock(type);
}

bool LaiEngine::BlockData::IsCollidable() const
{
	if (m_pBlock != nullptr)
	{
		return m_pBlock->IsCollidable();
	}

	return false;
}