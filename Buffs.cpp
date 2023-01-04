#pragma once
#include "Ninja.h"
#include "game.h"
#include "Buffs.h"
#include "windows.h"
#include <sstream>
#include <string>

namespace Tmpl8
{
	std::ostringstream oss;
	Buffs::Buffs() {}

	Buffs::Buffs(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Buffs::Update(Surface* s, BuffType buffType, Ninja* player, Spikes* spikes, float posX, float posY)
	{
		if (collided == false)
		{
			if (buffType == BuffType::Health)
			{
				s->Print("health", posX, posY, 0x96FF00);
				Draw(s, posX, posY, 0x96FF00);
			}
			else if (buffType == BuffType::Speed)
			{
				s->Print("Shadow Step", posX, posY, 0xadd8e6);
				Draw(s, posX, posY, 0xadd8e6);
			}
			else if (buffType == BuffType::Shield)
			{
				s->Print("Shield", posX, posY, 0x00008b);
				Draw(s, posX, posY, 0x00008b);
			}
			else if (buffType == BuffType::TimeSlow)
			{
				s->Print("TimeSlow", posX, posY, 0xFFD700);
				Draw(s, posX, posY, 0xFFD700);
			}
			
		}
		
		Collides(s, buffType, player, spikes, posX, posY);
		UIStats(s, player, buffType);
	}

	void Buffs::Draw(Surface* screen, float posX, float posY, int color)
	{
		DrawCollider(screen, posX, posY, 25, color);
	}

	void Buffs::DrawCollider(Surface* s, float x, float y, float r, int color)
	{
		for (int i = 0; i < 64; i++)
		{
			float r1 = (float)i * PI / 32, r2 = (float)(i + 1) * PI / 32;
			s->Line(x - r * sinf(r1), y - r * cosf(r1),
				x - r * sinf(r2), y - r * cosf(r2), color);
		}
	}

	void Buffs::Collides(Surface* s, BuffType buffType, Ninja* player, Spikes* spikes, float posX, float posY)
	{
		if (player->playerPos.x <= posX && player->playerPos.x + 50 >= posX && player->playerPos.y <= posY && player->playerPos.y + 50 >= posY && collided == false)
		{
			if (buffType == BuffType::Health)
			{
				player->currentHealth += 25;

			}
			if (buffType == BuffType::Speed)
			{
				player->speed += player->speed / 10;
				player->horizontalSpeed += 5;
			}
			else if (buffType == BuffType::Shield)
			{
				player->shield = 1;
				printf("I HATE NIGGERS\n");
				//s->Print("Shiled", 50, 50, 0x00008b);
			}
			else if (buffType == BuffType::TimeSlow)
			{
				spikes->speed /= 2;
				//s->Print("TimeSlow", 50, 50, 0xFFD700);
			}
			collided = true;
		}
	}

	void Buffs::UIStats(Surface* s,Ninja* player, BuffType buffType)
	{
		int sVal = 10;
		std::string newString;
		std::stringstream stream;
		stream << sVal;
		stream >> newString;

		int lenght = newString.length();
		char* char_array = new char(lenght + 1);
		strcpy(char_array, newString.c_str());
		for (int i = 0; i < lenght; i++)
		{
			s->Print(char_array, 50, 50, 0x00008b);
		}
	}
};
