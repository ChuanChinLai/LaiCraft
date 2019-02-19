#pragma once

#include <Engine/Utility/NonCopyable.h>

#include <glm/vec3.hpp>

namespace LaiEngine
{
	class GameObject : public NonCopyable
	{
	public:

		GameObject() : position(glm::vec3(0.f)), rotation(glm::vec3(0.f))
		{ 

		}

		~GameObject()
		{

		}

		glm::vec3 position;
		glm::vec3 rotation;
	};
}