#include <iostream>
#include "CWindow.h"

int main()
{
	CWindow window(800, 600, "Window");

	while (!glfwWindowShouldClose(CWindow::currentWindow->getWindow()))
	{
		std::cout << CWindow::currentWindow->GetFrameBuffer() << std::endl;
		//std::cout << CWindow::currentWindow->GetCursosPosition() << std::endl;

		glfwSwapBuffers(CWindow::currentWindow->getWindow());
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}