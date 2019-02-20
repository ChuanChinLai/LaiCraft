#pragma once

#include <glm/mat4x4.hpp>
#include "GameObject.h"


namespace LaiEngine
{
	class Camera : public GameObject
	{
	public:

		static Camera* Instance();
		static void Delete();

		void Update();
		void SetGameObject(GameObject* object);

		const glm::mat4& GetViewMatrix() const noexcept;
		const glm::mat4& GetProjectedMatrix() const noexcept;
		const glm::mat4& GetProjectedViewMatrix() const noexcept;

	private:

		Camera();

		static Camera* m_pInstance;

		const GameObject* m_pGameObject;

		glm::mat4 m_ProjectedMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ProjectedViewMatrx;
	};
}