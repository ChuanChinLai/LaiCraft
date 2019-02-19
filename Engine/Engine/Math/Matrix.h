#pragma once

#include <glm/mat4x4.hpp>

namespace LaiEngine
{
	class GameObject;
	class Camera;

	glm::mat4 MakeModelMatrix(GameObject* object);
	glm::mat4 MakeViewMatrix(Camera* camera);
	glm::mat4 MakeProjectionMatrix();
}