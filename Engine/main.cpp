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
#include "CVertexArray.h"

CMaterial material;
CMesh mesh;

CVertexArray* vA;
CVertexBuffer* vB;

void init()
{
	glEnable(GL_DEPTH_TEST);

	mesh = CResources::Loader("C:/Users/UserHp/Desktop/torus.obj");
	material.shader = CShader(CShader::ReadFile("src/myVertexShader.vert"), CShader::ReadFile("src/SimpleFrag.frag"));

	vA = new CVertexArray;
	vB = new CVertexBuffer(mesh.GetVertices().size() * sizeof(mesh.GetVertices()[0]), &mesh.GetVertices()[0]);
	vA->AddAttribute(0, 3, 0, nullptr);
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
	SMatrix4x4 V;
	V = SMatrix4x4::LookAt(SVector3(0, 0, 3), SVector3(0, 0, 0), SVector3(0, 1, 0));
	SMatrix4x4 P;
	P = SMatrix4x4::Ortho(-6, 6, -6, 6, -10, 10);

	material.SetMatrix4x4(6, M);
	material.SetMatrix4x4(7, V);
	material.SetMatrix4x4(8, P);

	vA->Bind();
	glDrawArrays(GL_TRIANGLES, 0, mesh.GetVertices().size());
}

void end()
{
	material.shader.Delete();
	vB->Destroy();
	vA->Destroy();
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