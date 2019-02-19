#pragma once

#include "Engine/Utility/NonCopyable.h"

#include <glad/glad.h>
#include <glm/matrix.hpp>

#include <string>

namespace LaiEngine
{
	class Shader : NonCopyable
	{
	public:
		Shader(const std::string& vertexFile, const std::string& fragmentFile);
		~Shader();

		void UseProgram() const;

		void SetUniformValue(GLuint location, int value);
		void SetUniformValue(GLuint location, float value);

		void SetUniformValue(GLuint location, const glm::vec2& vec);
		void SetUniformValue(GLuint location, const glm::vec3& vec);
		void SetUniformValue(GLuint location, const glm::vec4& vec);
		void SetUniformValue(GLuint location, const glm::mat4& matrix);


	protected:
		virtual void GetUniforms() = 0;
		GLuint m_programId;

	private:
		static GLuint Load(const std::string& vertexShader, const std::string& fragmentShader);
		static GLuint Compile(const GLchar* source, GLenum shaderType);
		static GLuint Link(GLuint vertexShaderID, GLuint fragmentShaderID);
	};
}