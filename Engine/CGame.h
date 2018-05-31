#pragma once

#include "CWindow.h"
#include "CTime.h"

class CGame
{
private:
	CWindow window;
public:
	CGame(int width, int height, const char* name);
	void Run();
	virtual void Start() = 0;
	virtual void Update() = 0;
};