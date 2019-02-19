#include "Rigidbody.h"

#include <Engine/GameObject/GameObject.h>

LaiEngine::Physics::Rigidbody::Rigidbody(GameObject* object) : m_pGameObject(object), velocity(glm::vec3(0.f))
{

}

void LaiEngine::Physics::Rigidbody::Update(float dt)
{
	if (UseGravity())
	{
		velocity.y -= 9.8f * dt;
	}


	//if (m_pGameObject != nullptr)
	//{
	//	m_pGameObject->position += velocity * dt;
	//}
}

bool LaiEngine::Physics::Rigidbody::UseGravity() const
{
	return m_useGravity;
}

void LaiEngine::Physics::Rigidbody::SetUseGravity(const bool state)
{
	m_useGravity = state;
}