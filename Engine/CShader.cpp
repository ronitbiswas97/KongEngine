#include "CShader.h"

CShader::CShader(const std::string& vertexSourceFileName, const std::string& fragmentFileName)
{
	unsigned int vertex = Compile(vertexSourceFileName.c_str(), GL_VERTEX_SHADER);
	Errors(vertex, "VERTEX");
	unsigned int fragment = Compile(fragmentFileName.c_str(), GL_FRAGMENT_SHADER);
	Errors(fragment, "FRAGMENT");

	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	glLinkProgram(ID);
	Errors(ID, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);
}

CShader::~CShader()
{
    glDeleteProgram(ID);
    glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}
static std::string CShader::ReadFile(const std::string& fileName)
{
    std::ifstream shaderFile(fileName);
	std::stringstream st;
	st << shaderFile.rdbuf();
	return st.str();
}

unsigned int CShader::Compile(const char* shaderString, GLenum type)
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

	if (type != "PROGRAM")
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
