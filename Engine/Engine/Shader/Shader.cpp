#include "Shader.h"

#include "Engine/Utility/FileReader.h"

#include <External/glm/gtc/type_ptr.hpp>

LaiEngine::Shader::Shader(const std::string & vertexFile, const std::string & fragmentFile)
{
	m_programId = Shader::Load(vertexFile, fragmentFile);
	UseProgram();
}


LaiEngine::Shader::~Shader()
{
	glDeleteProgram(m_programId);
}


void LaiEngine::Shader::UseProgram() const
{
	glUseProgram(m_programId);
}


void LaiEngine::Shader::SetUniformValue(GLuint location, int value)
{
	glUniform1i(location, value);
}


void LaiEngine::Shader::SetUniformValue(GLuint location, float value)
{
	glUniform1f(location, value);
}


void LaiEngine::Shader::SetUniformValue(GLuint location, const glm::vec2 & vec)
{
	glUniform2f(location, vec.x, vec.y);
}


void LaiEngine::Shader::SetUniformValue(GLuint location, const glm::vec3 & vec)
{
	glUniform3f(location, vec.x, vec.y, vec.z);
}


void LaiEngine::Shader::SetUniformValue(GLuint location, const glm::vec4 & vec)
{
	glUniform4f(location, vec.x, vec.y, vec.z, vec.w);
}


void LaiEngine::Shader::SetUniformValue(GLuint location, const glm::mat4 & matrix)
{
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}

void LaiEngine::Shader::GetUniforms()
{

}

GLuint LaiEngine::Shader::Load(const std::string & vertexShader, const std::string & fragmentShader)
{
	auto vertexSource = FileReader(vertexShader);
	auto fragmentSource = FileReader(fragmentShader);

	auto vertexShaderID = Shader::Compile(vertexSource.c_str(), GL_VERTEX_SHADER);
	auto fragmentShaderID = Shader::Compile(fragmentSource.c_str(), GL_FRAGMENT_SHADER);

	auto programID = Shader::Link(vertexShaderID, fragmentShaderID);

	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return programID;
}

GLuint LaiEngine::Shader::Compile(const GLchar * source, GLenum shaderType)
{
	auto shaderID = glCreateShader(shaderType);

	glShaderSource(shaderID, 1, &source, nullptr);
	glCompileShader(shaderID);

	GLint isSuccess = 0;
	GLchar infoLog[512];

	glGetShaderiv(shaderID, GL_COMPILE_STATUS, &isSuccess);
	if (!isSuccess)
	{
		glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
		throw std::runtime_error("Unable to load a shader: " + std::string(infoLog));
	}

	return shaderID;
}

GLuint LaiEngine::Shader::Link(GLuint vertexShaderID, GLuint fragmentShaderID)
{
	auto programID = glCreateProgram();

	glAttachShader(programID, vertexShaderID);
	glAttachShader(programID, fragmentShaderID);

	glLinkProgram(programID);

	return programID;
}

