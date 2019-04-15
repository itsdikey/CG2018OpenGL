#include "../Headers/ShaderProgram.h"

ShaderProgram::ShaderProgram()
{
	programId = glCreateProgram();
}

int ShaderProgram::getShaderProgramId()
{
	return programId;
}

void ShaderProgram::initFromFile(string vertexPath, string fragmentPath)
{
	initFromSourceCode(ParseShader(vertexPath), ParseShader(fragmentPath));
}

void ShaderProgram::initFromSourceCode(string vertexSource, string fragmentSource)
{
	CreateShader(this, vertexSource, fragmentSource);
}

void ShaderProgram::useShader()
{
	glUseProgram(programId);
}

void ShaderProgram::deleteShader()
{
	glDeleteProgram(programId);
}

void ShaderProgram::SetVec4(const std::string &name, float x, float y, float z, float w)
{
	glUniform4f(glGetUniformLocation(programId, name.c_str()), x, y, z, w);
}

void ShaderProgram::SetVec4(const std::string &name, const glm::vec4 &value)
{
	glUniform4fv(glGetUniformLocation(programId, name.c_str()), 1, &value[0]);
}

void ShaderProgram::SetVec3(const std::string &name, float x, float y, float z)
{
	glUniform3f(glGetUniformLocation(programId, name.c_str()), x, y, z);
}

void ShaderProgram::SetFloat(const std::string &name, float value)
{
	glUniform1f(glGetUniformLocation(programId, name.c_str()), value);
}

void ShaderProgram::SetMat3(const std::string &name, const glm::mat3 &mat)
{
	glUniformMatrix3fv(glGetUniformLocation(programId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
// ------------------------------------------------------------------------
void ShaderProgram::SetMat4(const std::string &name, const glm::mat4 &mat)
{
	glUniformMatrix4fv(glGetUniformLocation(programId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}