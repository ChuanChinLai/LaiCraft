#pragma once

#include "BlockType.h"

#include <Engine/GameObject/GameObject.h>
#include <Engine/Utility/NonCopyable.h>
#include <glm/vec3.hpp>

#include <string>

namespace LaiEngine
{
	class IBlock;

	class BlockData : public NonCopyable
	{
	public:

		BlockData();
		~BlockData();

		const glm::vec3& GetPosition() const;
		void SetPosition(const glm::vec3& position);

		void SetBlock(const BlockType type);

		bool IsCollidable() const;

	private:

		GameObject m_GameObject; 
		IBlock*    m_pBlock; 
	};
}