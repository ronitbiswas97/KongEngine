#include "CMyGame.h"
#include "CoreEngine.h"

CMaterial material;
CMesh mesh;
CVertexArray* vA;
CVertexBuffer* vB;

SVector3 eye(0, 0, 3);
SVector3 target(0, 0, -1);
SVector3 up(0, 1, 0);

CMyGame::CMyGame(int width, int height, const char * name)
	: CGame(width, height, name)
{
}

void CMyGame::Start()
{
	CWindow::currentWindow->SetColor(SVector4(0.5f));

	mesh = CResources::Loader("C:/Users/UserHp/Desktop/torus.obj");
	material.shader = CShader(CShader::ReadFile("src/myVertexShader.vert"), CShader::ReadFile("src/SimpleFrag.frag"));

	vA = new CVertexArray;
	vB = new CVertexBuffer(mesh.GetVertices().size() * sizeof(mesh.GetVertices()[0]), &mesh.GetVertices()[0]);
	vA->AddAttribute(0, 3, 0, nullptr);
}

void CMyGame::Update()
{
	material.shader.Use();

	SMatrix4x4 M;
	M = SMatrix4x4::Translate(M, SVector3(0.0f, 0.0f, -3.0f));
	M = SMatrix4x4::Scale(M, SVector3(0.25f));
	M = SMatrix4x4::Rotate(M, static_cast<float>(glfwGetTime()), SVector3(1.0f, 1.0f, 1.0f));

	SMatrix4x4 V;
	V = SMatrix4x4::LookAt(eye, eye + target, up);
	SMatrix4x4 P;
	P = SMatrix4x4::Perspective((30.0f * 3.1416f / 180.0f), CWindow::currentWindow->GetFrameBuffer().x / CWindow::currentWindow->GetFrameBuffer().y, 0.1f, 100.0f);

	material.SetMatrix4x4(6, M);
	material.SetMatrix4x4(7, V);
	material.SetMatrix4x4(8, P);

	vA->Bind();
	glDrawArrays(GL_TRIANGLES, 0, mesh.GetVertices().size());
}