#include "Camera.h"

#include <Engine/Math/Matrix.h>

#include <memory>

LaiEngine::Camera* LaiEngine::Camera::s_pInstance = nullptr;

LaiEngine::Camera::Camera() : m_pGameObject(nullptr)
{
	position = { 0, 0, 3.5 };
}

LaiEngine::Camera * LaiEngine::Camera::Instance()
{
	if (s_pInstance == nullptr)
	{
		s_pInstance = new Camera;
	}

	return s_pInstance;
}

void LaiEngine::Camera::Delete()
{
	if (s_pInstance != nullptr)
	{
		delete s_pInstance;
	}
}

void LaiEngine::Camera::Update()
{
	position = m_pGameObject->position;
	rotation = m_pGameObject->rotation;

	m_ViewMatrix = MakeViewMatrix(this);
	m_ProjectedMatrix = MakeProjectionMatrix();
}

void LaiEngine::Camera::SetGameObject(GameObject* object)
{
	m_pGameObject = object;
}

const glm::mat4& LaiEngine::Camera::GetViewMatrix() const noexcept
{
	return m_ViewMatrix;
}

const glm::mat4& LaiEngine::Camera::GetProjectedMatrix() const noexcept
{
	return m_ProjectedMatrix;
}

const glm::mat4& LaiEngine::Camera::GetProjectedViewMatrix() const noexcept
{
	return m_ProjectedViewMatrx;
}
