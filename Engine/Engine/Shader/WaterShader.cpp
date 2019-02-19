#include "WaterShader.h"

LaiEngine::WaterShader::WaterShader(const std::string & vertexFile, const std::string & fragmentFile) : Shader(vertexFile, fragmentFile)
{
	GetUniforms();
}

void LaiEngine::WaterShader::SetViewMat(const glm::mat4 & matrix)
{
	SetUniformValue(m_locationViewMat, matrix);
}

void LaiEngine::WaterShader::SetProjectedMat(const glm::mat4 & matrix)
{
	SetUniformValue(m_locationProjectedMat, matrix);
}

void LaiEngine::WaterShader::SetTime(const float & time)
{
	SetUniformValue(m_time, time);
}

void LaiEngine::WaterShader::GetUniforms()
{
	UseProgram();

	m_locationViewMat      = glGetUniformLocation(m_programId, "viewMat");
	m_locationProjectedMat = glGetUniformLocation(m_programId, "projectedMat");

	m_time                 = glGetUniformLocation(m_programId, "globalTime");
}

