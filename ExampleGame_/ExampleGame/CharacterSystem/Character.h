#pragma once

#include <Engine/GameObject/GameObject.h>
#include <Engine/Physics/Rigidbody.h>
#include <Engine/Physics/AABB.h>

#include <glm/vec3.hpp>
#include <SFML/Graphics.hpp>

namespace LaiEngine
{
	class CharacterSystem;
	class World;

	class Character : public GameObject
	{
	public:
		Character(CharacterSystem* system);

		void Update(World * world, float dt);
		void HandleInput(sf::RenderWindow* window, sf::Event& event);

	private:

		void KeyboardInput(sf::RenderWindow* window, sf::Event& event);
		void MouseInput(sf::RenderWindow* window);

		void Collide(World* world, const glm::vec3& vel, float dt);

		void Jump();

		Physics::Rigidbody m_rigidbody;
		AABB               m_collider;

		CharacterSystem*   m_pSystem;


		float m_speed      = 0.5f;
		bool  m_isOnGround = false;
		bool  m_isFlying = false;
	};
}