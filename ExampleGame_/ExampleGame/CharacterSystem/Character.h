#pragma once

#include <Engine/GameObject/GameObject.h>
#include <Engine/Physics/Rigidbody.h>

#include <glm/vec3.hpp>
#include <SFML/Graphics.hpp>

namespace LaiEngine
{
	class World;

	class Character : public GameObject
	{
	public:
		Character();

		void Update(float dt);
		void HandleInput(sf::RenderWindow* window);

	private:
		void KeyboardInput();
		void MouseInput(sf::RenderWindow* window);

		Physics::Rigidbody m_rigidbody;

		float m_speed     = 0.5f;
	};
}