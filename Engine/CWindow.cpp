#include <glad\glad.h>
#include <iostream>
#include "CWindow.h"

GLFWwindow* CWindow::currentWindow{ nullptr };

CWindow::CWindow(int width, int height, const char * name): m_width{ width },m_height{ height },m_name{ name }
{
    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    m_window = glfwCreateWindow(m_width, m_height, m_name, nullptr, nullptr);
    if(!m_window)
    {
        std::cout<<"Error en linea 18"<<std::endl;
    }
    glfwMakeContextCurrent(m_window);
    glfwSetFrameBufferSizeCallback(m_window, FrameBufferSizeCallBack);
    glfwSetCursorPosCallback(m_window,CursorPosCallBack);
    currentWindow = this;
}

CWindow::CursorPosition(double xPos, double yPos)
{
    mouse.x=xPos;
    mouse.y=yPos;
}

CWindow::FrameBufferSize(int width, int height)
{
    frameBufferSize.x=width;
    frameBufferSize.y=height;
}
CWindow::FrameBufferSizeCallBack(GLFWwindow* window, int width, int height)
{
    std::cout<<width<<std::endl;
	std::cout<<height<<std::endl;

    FrameBufferSize(width, height);
}
CWindow::CursorPosCallBack(GLFWwindow* window, double xPos, double yPos)
{
    std::cout<<xPos<<std::endl;
	std::cout<<yPos<<std::endl;
    CursorPosition(xPos,yPos);
}
