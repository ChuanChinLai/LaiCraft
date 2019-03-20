#include "Character.h"

#include <Engine/Math/Math.h>

#include <glm/glm.hpp>

#include <iostream>


LaiEngine::Character::Character() : m_rigidbody(this)
{
	//const int numItems = 5; 

	//for (int i = 0; i < numItems; i++)
	//{
	//	m_items.emplace_back(Material::NOTHING, 0);
	//}

	//m_rigidbody.SetUseGravity(true);

	position = { 0, 5, 10 };
}

void LaiEngine::Character::Update(float dt)
{

	//m_rigidbody.Update(dt);

	position.x += m_rigidbody.velocity.x * dt;
	//position.x = position.x < 0.0f ? 0 : position.x;
	//Collide(world, { m_rigidbody.velocity.x, 0, 0 }, dt);

	position.y += m_rigidbody.velocity.y * dt;
	//Collide(world, { 0, m_rigidbody.velocity.y, 0 }, dt);

	position.z += m_rigidbody.velocity.z * dt;
	//position.z = position.z < 0.0f ? 0 : position.z;
	//Collide(world, { 0, 0, m_rigidbody.velocity.z }, dt);

	//CollideY(world, m_rigidbody.velocity.y);
	//CollideXZ(world, m_rigidbody.velocity, dt);

	//m_collider.Update(position);


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
		//Jump();
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