#pragma once

#include <Engine/Shader/Shader.h>
#include <glm/mat4x4.hpp>

namespace LaiEngine
{
	class FontShader : public Shader
	{
	public:
		FontShader(const std::string& vertexFile = "Assets/Shaders/text.vs",
			const std::string& fragmentFile = "Assets/Shaders/text.fs");

		void SetColor(const glm::vec3& color);
		void SetProjectedMat(const glm::mat4& matrix);

	private:
		virtual void GetUniforms() override;

		GLuint m_locationTextColor;
		GLuint m_locationProjectedMat;
	};
}