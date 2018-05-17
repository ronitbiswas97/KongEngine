#include <glad\glad.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "CWindow.h"
#include "CMaterial.h"
#include "CMesh.h"
#include "CResources.h"
#include "CVertexBuffer.h"

CMaterial material;
CMesh mesh;

unsigned int VAO;
CVertexBuffer* vB;

void init()
{
	glEnable(GL_DEPTH_TEST);

	mesh = CResources::Loader("C:/Users/UserHp/Desktop/torus.obj");
	material.shader = CShader(CShader::ReadFile("src/myVertexShader.vert"), CShader::ReadFile("src/SimpleFrag.frag"));

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	vB = new CVertexBuffer(mesh.GetVertices().size() * sizeof(mesh.GetVertices()[0]), &mesh.GetVertices()[0]);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	glEnableVertexAttribArray(0);
}

void loop(float time)
{
	glViewport(0, 0, CWindow::currentWindow->GetFrameBuffer().x, CWindow::currentWindow->GetFrameBuffer().y);
	glClearColor(0.1f, 0.3f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	material.shader.Use();

	SMatrix4x4 M;
	M = SMatrix4x4::Scale(M, SVector3(0.5));
	M = SMatrix4x4::Rotate(M, glfwGetTime(), SVector3(1, 1, 1));

	material.SetVector2(0, CWindow::currentWindow->GetFrameBuffer());
	SVector2 mousePos(CWindow::currentWindow->GetCursosPosition().x, CWindow::currentWindow->GetFrameBuffer().y - CWindow::currentWindow->GetCursosPosition().y);
	material.SetVector2(1, mousePos);
	material.SetFloat(2, time);

	material.SetMatrix4x4(6, M);

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, mesh.GetVertices().size());
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void end()
{
	material.shader.Delete();
	vB->Destroy();
	glDeleteVertexArrays(1, &VAO);
}

int main()
{
	CWindow window(800, 600, "Window");

	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

	init();

	while (!CWindow::currentWindow->Close())
	{
		loop(glfwGetTime());

		glfwSwapBuffers(CWindow::currentWindow->GetWindow());
		glfwPollEvents();
	}

	end();

	return 0;
}