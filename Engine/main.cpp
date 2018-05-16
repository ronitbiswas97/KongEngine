#include <glad\glad.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "CWindow.h"
#include "CMaterial.h"
#include "CMesh.h"
#include "CResources.h"

CMaterial material;
CMesh mesh;

unsigned int VAO;
unsigned int VBO;

void init()
{
#if 0
	std::vector<SVector3> vertices
	{
		SVector3(-1.0f, -1.0f, 0.0f),
		SVector3(1.0f, -1.0f, 0.0f),
		SVector3(-1.0f, 1.0f, 0.0f),
		SVector3(1.0f, 1.0f, 0.0f)
	};

	mesh.SetVertices(vertices);
#endif

	mesh = CResources::Loader("C:/Users/UserHp/Desktop/cube.obj");
	material.shader = CShader(CShader::ReadFile("src/myVertexShader.vert"), CShader::ReadFile("src/DuskToDawn.frag"));

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, mesh.GetVertices().size() * sizeof(mesh.GetVertices()[0]), &mesh.GetVertices()[0], GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void loop(float time)
{
	glViewport(0, 0, CWindow::currentWindow->GetFrameBuffer().x, CWindow::currentWindow->GetFrameBuffer().y);
	glClearColor(0.1f, 0.3f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	material.shader.Use();

	SMatrix4x4 M;
	M = SMatrix4x4::Rotate(M, glfwGetTime(), SVector3(1, 1, 0));

	material.SetVector2(0, CWindow::currentWindow->GetFrameBuffer());
	SVector2 mousePos(CWindow::currentWindow->GetCursosPosition().x, CWindow::currentWindow->GetFrameBuffer().y - CWindow::currentWindow->GetCursosPosition().y);
	material.SetVector2(1, mousePos);
	material.SetFloat(2, time);

	material.SetMatrix4x4(6, M);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, mesh.GetVertices().size());
}

void end()
{
	material.shader.Delete();
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
