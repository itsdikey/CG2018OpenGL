#pragma once

#include <GL/glew.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "../../glm/glm.hpp"

using namespace std;
class ShaderProgram
{

private:
	int programId;
	static string ParseShader(string filepath) {
		ifstream stream(filepath);
		string line;
		stringstream stringStream;

		while (getline(stream, line))
		{
			stringStream << line << '\n';
		}

		return stringStream.str();
	}

	static unsigned int CompileShader(unsigned int type, const string& source) {
		unsigned int id = glCreateShader(type);
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr); // shader id, count of source codes, a pointer to the array that holds the strings
		glCompileShader(id);

		int result;
		glGetShaderiv(id, GL_COMPILE_STATUS, &result);
		if (result == GL_FALSE) {
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char* message = (char*)alloca(length * sizeof(char));
			glGetShaderInfoLog(id, length, &length, message);
			cout << message << endl;
			glDeleteShader(id);
			return 0;
		}
		return id;
	}

	// takes the shader as a string parameters 
	static unsigned int CreateShader(ShaderProgram* shaderProgram,const string& vertexShader, const string& fragmentShader)
	{
		GLuint program = shaderProgram->getShaderProgramId();
		unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);


		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glValidateProgram(program); // validate if the program is valid and can be run in the current state of opengl

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}
public :
	ShaderProgram();
	void initFromSourceCode(string vertexSource, string fragmentSource);
	void initFromFile(string vertexPath, string framentPath);
	void useShader();
	void deleteShader();
	void SetVec4(const std::string &name, float x, float y, float z, float w);
	void SetVec4(const std::string &name, const glm::vec4 &value);
	void SetVec3(const std::string &name, float x, float y, float z);
	void SetMat3(const std::string &name, const glm::mat3 &mat);
	void SetMat4(const std::string &name, const glm::mat4 &mat);
	void SetFloat(const std::string &name, float value);
	int getShaderProgramId();
};
