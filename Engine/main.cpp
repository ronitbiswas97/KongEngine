#include <glad\glad.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "CWindow.h"

unsigned int program;
unsigned int VAO;
unsigned int VBO;

std::string readShaderFile(const char* name)
{
	std::ifstream shaderFile(name);

	std::stringstream ss;
	ss << shaderFile.rdbuf();

	return ss.str();
}

unsigned int compileShader(const char* shaderString, GLenum type)
{
	const char* shaderSource = shaderString;
	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &shaderSource, nullptr);
	glCompileShader(shader);
	return shader;
}

void shaderErrors(unsigned int shader, const char* type)
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

unsigned int initShader(const std::string& vertexFileSource, const std::string& fragmentFileSource)
{
	unsigned int vertex = compileShader(vertexFileSource.c_str(), GL_VERTEX_SHADER);
	shaderErrors(vertex, "VERTEX");
	unsigned int fragment = compileShader(fragmentFileSource.c_str(), GL_FRAGMENT_SHADER);
	shaderErrors(fragment, "FRAGMENT");

	unsigned int program = glCreateProgram();
	glAttachShader(program, vertex);
	glAttachShader(program, fragment);
	glLinkProgram(program);
	shaderErrors(program, "PROGRAM");

	glDeleteShader(vertex);
	glDeleteShader(fragment);

	return program;
}

void init()
{
	program = initShader(readShaderFile("src/myVertexShader.vert"), readShaderFile("src/DuskToDawn.frag"));
	
	float vertices[]
	{
		-1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 0.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f
	};

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void loop(float time)
{
	glViewport(0, 0, CWindow::currentWindow->GetFrameBuffer().x, CWindow::currentWindow->GetFrameBuffer().y);
	glClearColor(0.1f, 0.3f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glUseProgram(program);

	glUniform2fv(0, 1, &CWindow::currentWindow->GetFrameBuffer()[0]);
	SVector2 mousePos(CWindow::currentWindow->GetCursosPosition().x, CWindow::currentWindow->GetFrameBuffer().y - CWindow::currentWindow->GetCursosPosition().y);
	glUniform2fv(1, 1, &mousePos[0]);
	glUniform1f(2, time);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void end()
{
	glDeleteProgram(program);
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

int main()
{
	CWindow window(800, 600, "Window");

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	init();

	while (!glfwWindowShouldClose(CWindow::currentWindow->getWindow()))
	{
		loop(glfwGetTime());

		glfwSwapBuffers(CWindow::currentWindow->getWindow());
		glfwPollEvents();
	}

	end();

	return 0;
}
