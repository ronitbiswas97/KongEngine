#ifndef CWINDOW_H
#define CWINDOW_H

#include <GLFW\glfw3.h>
#include "SVector2.h"

class CWindow
{
public:
	static CWindow* currentWindow;
private:
	const char* m_name;
	SVector2 frameBufferSize;
	SVector2 mousePosition;
	GLFWwindow* m_window;

public:
	CWindow(int width, int height, const char* name);
	~CWindow();
	bool Close();
	SVector2 GetCursosPosition()const;
	SVector2 GetFrameBuffer()const;
	GLFWwindow* GetWindow() const;

private:
	void CursorPosition(double xPos, double yPos);
	void FrameBufferSize(int width, int height);
	static void FrameBufferSizeCallBack(GLFWwindow* window, int width, int height);
	static void CursorPosCallBack(GLFWwindow* window, double xPos, double yPos);
};

#endif