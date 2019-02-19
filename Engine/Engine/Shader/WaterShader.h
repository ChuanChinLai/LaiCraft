#pragma once


#include <Engine/Shader/Shader.h>
#include <glm/mat4x4.hpp>

namespace LaiEngine
{
	class WaterShader : public Shader
	{
	public:
		WaterShader(const std::string& vertexFile = "Assets/Shaders/water.vs",
			const std::string& fragmentFile = "Assets/Shaders/water.fs");

		void SetViewMat(const glm::mat4& matrix);
		void SetProjectedMat(const glm::mat4& matrix);

		void SetTime(const float& time);

	private:
		virtual void GetUniforms() override;

		GLuint m_time;
		GLuint m_locationViewMat;
		GLuint m_locationProjectedMat;
	};
}