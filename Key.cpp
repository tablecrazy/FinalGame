#pragma once
#include "Ninja.h"
#include "game.h"
#include "windows.h"
#include "Key.h"

namespace Tmpl8
{

	Sprite key(new Surface("assets/key.png"), 1);
	Key::Key() {}

	Key::Key(Surface* screen, Ninja* player) :
		m_screen{ screen },
		m_player{ player }
	{
	}

	void Key::Update(int value, float posX, float posY)
	{
		Draw(posX, posY);
		Collides(posX, posY);
			
	}

	void Key::Draw(float posX, float posY)
	{
		key.Draw(m_screen, posX, posY);
		DrawCollider(posX + 15, posY + 25, 25, 0xFFD700);
	}

	void Key::DrawCollider(float x, float y, float r, int color)
	{
		for (int i = 0; i < 64; i++)
		{
			float r1 = (float)i * PI / 32, r2 = (float)(i + 1) * PI / 32;
			m_screen->Line(x - r * sinf(r1), y - r * cosf(r1),
				x - r * sinf(r2), y - r * cosf(r2), color);
		}
	}

	void Key::Collides(float posX, float posY)
	{
		if (m_player->playerPos.x <= posX && m_player->playerPos.x + 50 >= posX && m_player->playerPos.y <= posY && m_player->playerPos.y + 50 >= posY)
		{
			collided = true;
		}
	}

	
};
