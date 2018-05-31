#include <glad\glad.h>
#include "CWindow.h"

CWindow* CWindow::currentWindow{ nullptr };

CWindow::CWindow(int width, int height, const char * name) 
	: frameBufferSize( static_cast<float>(width), static_cast<float>(height) ), m_name{ name }
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	m_window = glfwCreateWindow(static_cast<int>(frameBufferSize.x), static_cast<int>(frameBufferSize.y), m_name, nullptr, nullptr);

	glfwMakeContextCurrent(m_window);
	glfwSetFramebufferSizeCallback(m_window, FrameBufferSizeCallBack);
	glfwSetCursorPosCallback(m_window, CursorPosCallBack);
	currentWindow = this;
}

CWindow::~CWindow()
{
	glfwDestroyWindow(m_window);
	glfwTerminate();
}

SVector2 CWindow::GetFrameBuffer() const
{
	return frameBufferSize;
}

GLFWwindow* CWindow::GetWindow() const
{
	return m_window;
}

void CWindow::CursorPosition(double xPos, double yPos)
{
	CInput::mousePosition.x = static_cast<float>(xPos);
	CInput::mousePosition.y = static_cast<float>(yPos);
	CInput::mousePosition.z = 0.0f;
}

void CWindow::FrameBufferSize(int width, int height)
{
	frameBufferSize.x = static_cast<float>(width);
	frameBufferSize.y = static_cast<float>(height);
}

bool CWindow::Close()
{
	return glfwWindowShouldClose(GetWindow());
}

void CWindow::EnableTests()
{
	glEnable(GL_DEPTH_TEST);
}

void CWindow::ClearBuffers()
{
	glViewport(0, 0, static_cast<int>(CWindow::currentWindow->GetFrameBuffer().x), static_cast<int>(CWindow::currentWindow->GetFrameBuffer().y));
	glClearColor(m_color.x, m_color.y, m_color.z, m_color.w);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void CWindow::SetColor(const SVector4& color)
{
	m_color = color;
}

void CWindow::FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
	currentWindow->FrameBufferSize(width, height);
}

void CWindow::CursorPosCallBack(GLFWwindow* window, double xPos, double yPos)
{
	currentWindow->CursorPosition(xPos, yPos);
}