#include <glad\glad.h>
#include "CGame.h"
#include "CTime.h"

CGame::CGame(int width, int height, const char * name)
	: window(width, height, name)
{
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
}

void CGame::Run()
{
	CWindow::currentWindow->EnableTests();
	Start();
	float lastFrame{ 0.0f };

	while (!CWindow::currentWindow->Close())
	{
		float currentFrame{ static_cast<float>(glfwGetTime()) };
		CTime::deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		CWindow::currentWindow->ClearBuffers();

		Update();

		glfwSwapBuffers(CWindow::currentWindow->GetWindow());
		glfwPollEvents();
	}
}