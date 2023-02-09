#pragma once
#include "Mouse.h"
#include "game.h"
#include "windows.h"

namespace Tmpl8
{
	Sprite ball(new Surface("assets/ball.png"), 1);

	Mouse::Mouse() {}

	Mouse::Mouse(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Mouse::Update()
	{
		
	}

	void Mouse::MouseMove(int x, int y)
	{
		ball.Draw(m_screen, x - 20, y - 20);
	}
	
	void Mouse::MouseDown(int button)
	{

	}
};
