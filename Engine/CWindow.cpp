#include <glad\glad.h>

#include <iostream>
#include "CWindow.h"

CWindow* CWindow::currentWindow{ nullptr };

CWindow::CWindow(int width, int height, const char * name) 
	: frameBufferSize( width, height ), m_name{ name }
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_window = glfwCreateWindow(frameBufferSize.x, frameBufferSize.y, m_name, nullptr, nullptr);

	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, FrameBufferSizeCallBack);
	glfwSetCursorPosCallback(m_window, CursorPosCallBack);
	currentWindow = this;
}

SVector2 CWindow::GetCursosPosition() const
{
	return mousePosition;
}

SVector2 CWindow::GetFrameBuffer() const
{
	return frameBufferSize;
}

GLFWwindow* CWindow::getWindow() const
{
	return m_window;
}

void CWindow::CursorPosition(double xPos, double yPos)
{
	mousePosition.x = xPos;
	mousePosition.y = yPos;
}

bool CWindow::Close()
{
	return glfwWindowShouldClose(getWindow());
}

void CWindow::FrameBufferSize(int width, int height)
{
	frameBufferSize.x = width;
	frameBufferSize.y = height;
}

void CWindow::FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	currentWindow->FrameBufferSize(width, height);
}

void CWindow::CursorPosCallBack(GLFWwindow* window, double xPos, double yPos)
{
	currentWindow->CursorPosition(xPos, yPos);
}
