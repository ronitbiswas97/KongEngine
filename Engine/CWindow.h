#ifndef CWINDOW_H
#define CWINDOW_H

#include <GLFW\glfw3.h>
#include "SVector2.h"
#include "SVector4.h"

class CWindow
{
public:
	static CWindow* currentWindow;
private:
	const char* m_name;
	SVector2 frameBufferSize;
	SVector2 mousePosition;
	GLFWwindow* m_window;
	SVector4 m_color;

public:
	CWindow(int width, int height, const char* name);
	~CWindow();
	bool Close();
	void EnableTests();
	void ClearBuffers();
	void SetColor(const SVector4& color);
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