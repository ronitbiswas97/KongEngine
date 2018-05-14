#include <glad\glad.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "CWindow.h"
#include "CShader.h"

CShader shader;
unsigned int VAO;
unsigned int VBO;

void init()
{
	float vertices[]
	{
		-1.0f, -1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, 0.0f, 1.0f,
		-1.0f, 1.0f, 0.0f, 1.0f,
		1.0f, 1.0f, 0.0f, 1.0f
	};

	shader = CShader(CShader::ReadFile("src/myVertexShader.vert"), CShader::ReadFile("src/DuskToDawn.frag"));

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

	shader.Use();
	
	shader(0, CWindow::currentWindow->GetFrameBuffer());
	SVector2 mousePos(CWindow::currentWindow->GetCursosPosition().x, CWindow::currentWindow->GetFrameBuffer().y - CWindow::currentWindow->GetCursosPosition().y);
	shader(1, mousePos);
	shader(2, time);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
}

void end()
{
	shader.Delete();
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
