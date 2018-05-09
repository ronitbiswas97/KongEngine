#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW\glfw3.h>
#include "maths\CVector4.h"

class CWindow
{
public:
    static CWindow* currentWindow;
    GLFWwindow* m_window;
private:
    const char* m_name;
    SVector2 frameBufferSize;
    SVector2 mousePosition;
public:
    CWindow(int width, int height, const char* name);
    void GetCursosPosition()const;
    void GetFrameBuffer()const;
private:
    void CursorPosition(double xPos, double yPos);
    void FrameBufferSize(int width, int height);
    static void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
    static void CursorPosCallBack(GLFWwindow* window, double xPos, double yPos);
};

#endif
