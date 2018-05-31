#include "Cinput.h"
#include "CWindow.h"

#include <iostream>

SVector3 CInput::mousePosition(0.0f);

bool CInput::GetKey(KeyCode key)
{
	return (glfwGetKey(CWindow::currentWindow->GetWindow(), key) == GLFW_PRESS);
}

SVector2 CInput::GetAxis()
{
	return SVector2();
}

bool CInput::MouseButton(int button)
{
	return (glfwGetMouseButton(CWindow::currentWindow->GetWindow(), button) == GLFW_PRESS);
}

bool CInput::MouseButtonUp(int button)
{
	return (glfwGetMouseButton(CWindow::currentWindow->GetWindow(), button) == GLFW_RELEASE);
}