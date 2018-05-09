#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW\glfw3.h>
#include "maths\CVector4.h"

class CWindow
{
public:

    GLFWwindow* m_window;
    static GLFWwindow* currentWindow;
    const char* m_name;
    SVector2 frameBufferSize;
    SVector2 mousePosition;

public:
    cWindow(int width, int height, const char* name);

private:
    void CursorPosition(double xPos, double yPos);
    static FrameBufferSize(int width, int height);
    static FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
    static CursosPosCallBack(GLFWwindow* window, double xPos, double yPos);
};

#endif
