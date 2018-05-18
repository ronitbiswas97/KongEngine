#include "Cinput.h"
#include "CWindow.h"

bool CInput::GetKeyUp(KeyCode key)
{
	return (glfwGetKey(CWindow::currentWindow->GetWindow, key) == GLFW_RELEASE);
}
bool CInput::GetKey(KeyCode key)
{
	return (glfwGetKey(CWindow::currentWindow->GetWindow, key) == GLFW_PRESS);
}
SVector2 CInput::GetAxis()
{
	return CWindow::currentWindow->GetCursosPosition();
	
}
bool CInput::MouseButton(int button)
{
	return (glfwGetMouseButton(CWindow::currentWindow->GetWindow, button) == GLFW_PRESS);
}
bool CInput::MouseButtonUp(int button)
{
	return (glfwGetMouseButton(CWindow::currentWindow->GetWindow, button) == GLFW_RELEASE);
}