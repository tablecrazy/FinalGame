#pragma once
#include "Ninja.h"
#include "game.h"
#include "BouncingShuriken.h"
#include "windows.h"
#include <sstream>
#include <string>

namespace Tmpl8
{
	Sprite bshuriken(new Surface("assets/BSHURIKEN2.tga"), 9);

	BouncingShuriken::BouncingShuriken() {}

	BouncingShuriken::BouncingShuriken(Surface* screen, Ninja* player) :
		m_screen{ screen },
		m_ninja{ player }
	{
	}

	void BouncingShuriken::Update(SnSide snSide, float posX, float posY, float size, float speed, float deltatime)
	{
		
		if (collided == false)
		{
			Bounce(snSide, posX, posY, size, speed);

			Collides();
		}
		
	}

	void BouncingShuriken::Bounce(SnSide snSide, float posX, float posY, float size, float speed)
	{
		if (shurikenPositioned == false)
		{
			shurikenPos.x = posX;
			shurikenPos.y = posY;
			shurikenPositioned = true;
		}
		if (snSide == SnSide::Vectical) {
			if (shurikenPos.y >= posY + size || shurikenPos.y <= posY - size) {
				pointReached = !pointReached;
			}

			shurikenPos.y += pointReached ? -speed : speed;
		}
		else if (snSide == SnSide::Horizontal) {
			if (shurikenPos.x >= posX + size || shurikenPos.x <= posX - size) {
				pointReached = !pointReached;
			}

			shurikenPos.x += pointReached ? -speed : speed;
		}
		
		bshuriken.SetFrame(frame);
		bshuriken.Draw(m_screen, shurikenPos.x - 25, shurikenPos.y - 20);
		if (++frame == 9) frame = 0;
	}

	void BouncingShuriken::Draw(SnSide snSide, float posX, float posY, int color, float size)
	{
		if (snSide == SnSide::Vectical)
		{
			m_screen->Line(posX, posY - size, posX, posY + size, 0xFFA500);
		}
		else if (snSide == SnSide::Horizontal)
		{
			m_screen->Line(posX - size, posY, posX + size, posY, 0xFFA500);
		}
		
	}

	void BouncingShuriken::Collides()
	{
		if (m_ninja->playerPos.x <= shurikenPos.x && m_ninja->playerPos.x + 50 >= shurikenPos.x && m_ninja->playerPos.y <= shurikenPos.y && m_ninja->playerPos.y + 50 >= shurikenPos.y)
		{
			m_ninja->TakeDamage(30);
			collided = true;
		}
	}

	void BouncingShuriken::DrawCollider(float x, float y, float r, int color)
	{
		for (int i = 0; i < 64; i++)
		{
			float r1 = (float)i * PI / 32, r2 = (float)(i + 1) * PI / 32;
			m_screen->Line(x - r * sinf(r1), y - r * cosf(r1),
				x - r * sinf(r2), y - r * cosf(r2), color);
		}
	}

};
