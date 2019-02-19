#pragma once

#include <Engine/Utility/NonCopyable.h>

#include <glm/vec3.hpp>

namespace LaiEngine
{
	class GameObject;

	namespace Physics
	{
		class Rigidbody : NonCopyable
		{
		public:

			Rigidbody(GameObject* object);
	
			void Update(float dt);

			bool UseGravity() const;
			void SetUseGravity(const bool state);

			glm::vec3 velocity;

		private:

			GameObject* m_pGameObject;
			bool        m_useGravity = true;
		};
	}
}