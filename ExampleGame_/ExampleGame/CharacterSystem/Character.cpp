#include "Character.h"

#include <Engine/Math/Math.h>
#include <ExampleGame/CharacterSystem/CharacterSystem.h>
#include <ExampleGame/BaseClass/IGameSystem.h>
#include <ExampleGame/WorldMapSystem/Block/ChunkBlock.h>
#include <ExampleGame/WorldMapSystem/World/World.h>

#include <glm/glm.hpp>

#include <iostream>


LaiEngine::Character::Character(CharacterSystem* system) : m_pSystem(system), m_rigidbody(this), m_collider({ 0.5f, 2.0f, 0.5f })
{
	//const int numItems = 5; 

	//for (int i = 0; i < numItems; i++)
	//{
	//	m_items.emplace_back(Material::NOTHING, 0);
	//}

	//m_rigidbody.SetUseGravity(true);

	position = { 0, 10, 10 };
}

void LaiEngine::Character::Update(World * world, float dt)
{
	m_rigidbody.Update(dt);

	position.x += m_rigidbody.velocity.x * dt;
	position.x = position.x < 0.0f ? 0 : position.x;
	Collide(world, { m_rigidbody.velocity.x, 0, 0 }, dt);

	position.y += m_rigidbody.velocity.y * dt;
	Collide(world, { 0, m_rigidbody.velocity.y, 0 }, dt);

	position.z += m_rigidbody.velocity.z * dt;
	position.z = position.z < 0.0f ? 0 : position.z;
	Collide(world, { 0, 0, m_rigidbody.velocity.z }, dt);

	m_collider.Update(position);

	m_rigidbody.velocity.x *= 0.95f;
	m_rigidbody.velocity.x = abs(m_rigidbody.velocity.x) < Math::EPSILON ? 0 : m_rigidbody.velocity.x;

	m_rigidbody.velocity.z *= 0.95f;
	m_rigidbody.velocity.z = abs(m_rigidbody.velocity.z) < Math::EPSILON ? 0 : m_rigidbody.velocity.z;
}

void LaiEngine::Character::HandleInput(sf::RenderWindow* window)
{
	KeyboardInput();
	MouseInput(window);
}

void LaiEngine::Character::KeyboardInput()
{
	glm::vec3 dv;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dv.x = glm::cos(glm::radians(rotation.y + 90)) * m_speed;
		dv.z = glm::sin(glm::radians(rotation.y + 90)) * m_speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		dv.x = -glm::cos(glm::radians(rotation.y + 90)) * m_speed;
		dv.z = -glm::sin(glm::radians(rotation.y + 90)) * m_speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		dv.x = glm::cos(glm::radians(rotation.y)) * m_speed;
		dv.z = glm::sin(glm::radians(rotation.y)) * m_speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		dv.x = -glm::cos(glm::radians(rotation.y)) * m_speed;
		dv.z = -glm::sin(glm::radians(rotation.y)) * m_speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Jump();
	}

	m_rigidbody.velocity += dv;
}

void LaiEngine::Character::MouseInput(sf::RenderWindow* window)
{
	static auto const BOUND = 80;
	static auto lastMousePosition = sf::Mouse::getPosition(*window);
	auto change = sf::Mouse::getPosition() - lastMousePosition;

	rotation.y += static_cast<float>(change.x * 0.05);
	rotation.x += static_cast<float>(change.y * 0.05);

	if (rotation.x > BOUND) rotation.x = BOUND;
	else if (rotation.x < -BOUND) rotation.x = -BOUND;

	if (rotation.y > 360) rotation.y = 0;
	else if (rotation.y < 0)    rotation.y = 360;

	auto cx = static_cast<int>(window->getSize().x / 2);
	auto cy = static_cast<int>(window->getSize().y / 2);

	sf::Mouse::setPosition({ cx, cy }, *window);

	lastMousePosition = sf::Mouse::getPosition();
}

void LaiEngine::Character::Collide(World* world, const glm::vec3 & vel, float dt)
{
	for (int x = Math::Floor(position.x - m_collider.dimensions.x); x < Math::Ceil(position.x + m_collider.dimensions.x); x++)
	{
		for (int y = Math::Floor(position.y - m_collider.dimensions.y); y < Math::Ceil(position.y + 0.7f); y++)
		{
			for (int z = Math::Floor(position.z - m_collider.dimensions.z); z < Math::Ceil(position.z + m_collider.dimensions.z); z++)
			{
				auto block = world->GetBlock(x, y, z);

				if (block != nullptr && block->GetData().IsCollidable())
				{
					if (vel.y > 0)
					{
						position.y = y - m_collider.dimensions.y;
						m_rigidbody.velocity.y = 0;
					}
					else if (vel.y < 0)
					{
						m_isOnGround = true;
						position.y = y + m_collider.dimensions.y + 1;
						m_rigidbody.velocity.y = 0;
					}

					if (vel.x > 0)
					{
						position.x = x - m_collider.dimensions.x;
					}
					else if (vel.x < 0)
					{
						position.x = x + m_collider.dimensions.x + 1;
					}

					if (vel.z > 0)
					{
						position.z = z - m_collider.dimensions.z;
					}
					else if (vel.z < 0)
					{
						position.z = z + m_collider.dimensions.z + 1;
					}
				}
			}
		}
	}
}

void LaiEngine::Character::Jump()
{
	if (m_isOnGround)
	{
		m_isOnGround = false;
		glm::vec3 dv = { 0, 5.0f, 0 };
		m_rigidbody.velocity += dv;
	}
}
