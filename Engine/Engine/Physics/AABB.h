#pragma once

#include <glm/vec3.hpp>

namespace LaiEngine
{
	class AABB
	{
	public:
		AABB(const glm::vec3& dim) : dimensions(dim)
		{

		}

		void Update(const glm::vec3& location);

		glm::vec3 GetVN(const glm::vec3& normal) const;
		glm::vec3 GetVP(const glm::vec3& normal) const;


		const glm::vec3 dimensions;

	private:
		glm::vec3       position;
	};
}