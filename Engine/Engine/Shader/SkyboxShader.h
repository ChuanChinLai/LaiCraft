#pragma once

#include <Engine/Shader/Shader.h>
#include <glm/mat4x4.hpp>

namespace LaiEngine
{
	class SkyboxShader : public Shader
	{
	public:
		SkyboxShader(const std::string& vertexFile = "Assets/Shaders/skybox.vs",
			const std::string& fragmentFile = "Assets/Shaders/skybox.fs");

		void SetViewMat(glm::mat4 matrix);
		void SetProjectedMat(const glm::mat4& matrix);

	private:
		virtual void GetUniforms() override;

		GLuint m_locationViewMat;
		GLuint m_locationProjectedMat;
	};
}