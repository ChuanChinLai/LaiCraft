#include "AABB.h"

void LaiEngine::AABB::Update(const glm::vec3 & location)
{
	position = location;
}

glm::vec3 LaiEngine::AABB::GetVN(const glm::vec3 & normal) const
{
	glm::vec3 res = position;

	if (normal.x < 0)
	{
		res.x += dimensions.x;
	}
	if (normal.y < 0)
	{
		res.y += dimensions.y;
	}
	if (normal.z < 0)
	{
		res.z += dimensions.z;
	}

	return res;
}

glm::vec3 LaiEngine::AABB::GetVP(const glm::vec3 & normal) const
{
	glm::vec3 res = position;

	if (normal.x > 0)
	{
		res.x += dimensions.x;
	}
	if (normal.y > 0)
	{
		res.y += dimensions.y;
	}
	if (normal.z > 0)
	{
		res.z += dimensions.z;
	}

	return res;
}
