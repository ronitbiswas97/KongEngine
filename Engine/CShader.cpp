#include <glad\glad.h>

#include <fstream>
#include <sstream>
#include <iostream>

#include "CShader.h"

CShader::CShader()
{
}

CShader::CShader(const std::string& vertexSourceFileName, const std::string& fragmentFileName)
{
	unsigned int vertex = Compile(vertexSourceFileName.c_str(), ShaderType::VERTEX);
	Errors(vertex, ShaderType::VERTEX);
	unsigned int fragment = Compile(fragmentFileName.c_str(), ShaderType::FRAGMENT);
	Errors(fragment, ShaderType::FRAGMENT);

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	Errors(ID, ShaderType::PROGRAM);

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

void CShader::Use() const
{
	glUseProgram(GetID());
}

void CShader::Delete() const
{
	glDeleteProgram(GetID());
}

void CShader::operator()(const char* name, int value)
{
	glUniform1i(glGetUniformLocation(GetID(), name), value);
}

void CShader::operator()(int name, int value)
{
	glUniform1i(name, value);
}

void CShader::operator()(const char* name, float value)
{
	glUniform1f(glGetUniformLocation(GetID(), name), value);
}

void CShader::operator()(int name, float value)
{
	glUniform1f(name, value);
}

void CShader::operator()(const char* name, const SVector2& vec2)
{
	glUniform2fv(glGetUniformLocation(GetID(), name), 1, &vec2[0]);
}

void CShader::operator()(int name, const SVector2& vec2)
{
	glUniform2fv(name, 1, &vec2[0]);
}

void CShader::operator()(const char* name, const SVector3& vec3)
{
	glUniform3fv(glGetUniformLocation(GetID(), name), 1, &vec3[0]);
}

void CShader::operator()(int name, const SVector3& vec3)
{
	glUniform3fv(name, 1, &vec3[0]);
}

void CShader::operator()(const char* name, const SVector4& vec4)
{
	glUniform4fv(glGetUniformLocation(GetID(), name), 1, &vec4[0]);
}

void CShader::operator()(int name, const SVector4& vec4)
{
	glUniform4fv(name, 1, &vec4[0]);
}

void CShader::operator()(const char* name, const SMatrix4x4& mat4)
{
	glUniformMatrix4fv(glGetUniformLocation(GetID(), name), 1, false, &mat4[0][0]);
}

void CShader::operator()(int name, const SMatrix4x4& mat4)
{
	glUniformMatrix4fv(name, 1, false, &mat4[0][0]);
}

std::string CShader::ReadFile(const std::string& fileName)
{
	std::ifstream shaderFile(fileName);
	std::stringstream st;
	st << shaderFile.rdbuf();
	return st.str();
}

unsigned int CShader::Compile(const char* shaderString, ShaderType type)
{
	const char* shaderSource = shaderString;
	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &shaderSource, nullptr);
	glCompileShader(shader);
	return shader;
}

void CShader::Errors(unsigned int shader, ShaderType type)
{
	int success;
	char infoLog[512];

	if (type != ShaderType::PROGRAM)
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			std::cout << type << "_ERROR:\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shader, 512, nullptr, infoLog);
			std::cout << type << "_ERROR:\n" << infoLog << std::endl;
		}
	}
}

unsigned int CShader::GetID() const
{
	return ID;
}
