#pragma once

#include <glad/glad.h>

#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <cyCodeBase/cyTriMesh.h>

#include <vector>

namespace LaiEngine
{
	struct sVertex
	{
		glm::vec3 Position;
		glm::vec3 Normal;
		glm::vec2 UV;
	};

	class Mesh
	{
	public:
		std::vector<sVertex> vertices;
		std::vector<GLuint>  indices;
	};
}
