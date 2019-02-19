#pragma once

#include <Engine/GameObject/GameObject.h>
#include <Engine/Physics/AABB.h>
#include <Engine/Physics/Rigidbody.h>

#include <ExampleGame/Item/ItemStack.h>

#include <glm/vec3.hpp>
#include <SFML/Graphics.hpp>

namespace LaiEngine
{
	class World;


	class Player : public GameObject
	{
	public:
		Player();

		void Update(World* world, float dt);
		void HandleInput(sf::RenderWindow* window);

		void AddItem(const Material& material);

		ItemStack& GetHeldItems();

	private:
		void KeyboardInput();
		void MouseInput(sf::RenderWindow* window);

		void ItemInput();

		void CollideY(World* world, const float vy);
		void CollideXZ(World* world, const glm::vec3& vel, const float dt);
		void Collide(World* world, const glm::vec3& vel, float dt);

		void Jump();

		std::vector<ItemStack> m_items;

		Physics::Rigidbody m_rigidbody;
		AABB               m_collider;

		float m_speed     = 0.5f;

		bool m_isOnGround = false;
		bool m_isFlying   = false;

		int m_heldItem = 0;
	};
}