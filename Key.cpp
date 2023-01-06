#pragma once
#include "Ninja.h"
#include "game.h"
#include "windows.h"
#include"Key.h"

namespace Tmpl8
{

	Sprite key(new Surface("assets/ball.png"), 1);
	Key::Key() {}

	Key::Key(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Key::Update(Surface* s, Ninja* player, float posX, float posY)
	{
		Draw(s, posX, posY);
		Collides( player, posX, posY);
		if (won == true)
			printf("WIN\n");
	}

	void Key::Draw(Surface* screen, float posX, float posY)
	{
		key.Draw(screen, posX, posY);
		DrawCollider(screen, posX + 15, posY + 25, 25, 0xFFD700);
	}

	void Key::DrawCollider(Surface* s, float x, float y, float r, int color)
	{
		for (int i = 0; i < 64; i++)
		{
			float r1 = (float)i * PI / 32, r2 = (float)(i + 1) * PI / 32;
			s->Line(x - r * sinf(r1), y - r * cosf(r1),
				x - r * sinf(r2), y - r * cosf(r2), color);
		}
	}

	void Key::Collides(Ninja* player,float posX, float posY)
	{
		if (player->playerPos.x <= posX && player->playerPos.x + 50 >= posX && player->playerPos.y <= posY && player->playerPos.y + 50 >= posY)
		{
			won = true;
		}
	}

	
};
