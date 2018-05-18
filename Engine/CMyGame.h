#pragma once

#include "CGame.h"

class CMyGame
	: public CGame
{
public:
	CMyGame(int width, int height, const char* name);
	void Start() override;
	void Update() override;
};