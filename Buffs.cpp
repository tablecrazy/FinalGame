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

	void Buffs::Update(Surface* s, BuffType buffType, Ninja* player, Spikes* spikes, float posX, float posY, float deltatime)
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
				
				m_time = 3;
				s->Print("Shadow Step", posX, posY, 0xadd8e6);
				Draw(s, posX, posY, 0xadd8e6);
			}
			else if (buffType == BuffType::Shield)
			{
				m_time = 5;
				s->Print("Shield", posX, posY, 0x0096FF);
				Draw(s, posX, posY, 0x0096FF);
			}
			else if (buffType == BuffType::TimeSlow)
			{
				m_time = 4;
				s->Print("TimeSlow", posX, posY, 0xFFD700);
				Draw(s, posX, posY, 0xFFD700);
			}
			
		}
		
		Collides(s, buffType, player, spikes, posX, posY, deltatime);

		SpeedBuffCheck(s, buffType, player, deltatime);
		ShieldBuffCheck(s, buffType, player, deltatime);
		TimeSlowBuffCheck(s, buffType, spikes, deltatime);
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

	void Buffs::Collides(Surface* s, BuffType buffType, Ninja* player, Spikes* spikes, float posX, float posY, float deltatime)
	{
		if (player->playerPos.x <= posX && player->playerPos.x + 50 >= posX && player->playerPos.y <= posY && player->playerPos.y + 50 >= posY && collided == false)
		{
			if (buffType == BuffType::Health)
			{
				player->currentHealth += 25;
			}
			if (buffType == BuffType::Speed)
			{
				player->horizontalSpeed += 2;
			}
			else if (buffType == BuffType::Shield)
			{
				player->shield = 1;
			}
			else if (buffType == BuffType::TimeSlow)
			{
				spikes->speed /= 2;
			}
			collided = true;

			
		}
	}
	
	void Buffs::SpeedBuffCheck(Surface* s, BuffType buffType, Ninja* player, float deltatime)
	{
		if (buffType == BuffType::Speed)
		{
			if (player->horizontalSpeed > 5)
			{
				m_time -= deltatime;
				printf("%d\n", (int)m_time + 1);
				UIStats(s, player, buffType, "Speed", (int)m_time, 20, 0xadd8e6);
			}
			if (m_time <= 0)
			{
				player->horizontalSpeed = 5;
			}
		}
	}

	void Buffs::ShieldBuffCheck(Surface* s, BuffType buffType, Ninja* player, float deltatime)
	{
		if (buffType == BuffType::Shield)
		{
			if (player->shield == true)
			{
				m_time -= deltatime;
				printf("%d\n", (int)m_time + 1);
				UIStats(s, player, buffType, "Shield", (int)m_time, 35, 0x0096FF);
			}
			if (m_time <= 0)
			{
				player->shield = false;
			}
		}
		
	}

	void Buffs::TimeSlowBuffCheck(Surface* s, BuffType buffType, Spikes* spikes, float deltatime)
	{
		if (buffType == BuffType::TimeSlow)
		{
			if (spikes->speed != spikes->newSpeed)
			{
				m_time -= deltatime;
				printf("%d\n", (int)m_time + 1);
				UIStats(s, ninja, buffType, "Time Slow", (int)m_time, 50, 0xFFD700);
			}
			if (m_time <= 0)
			{
				spikes->speed = spikes->newSpeed;
			}
		}
	}

	void Buffs::UIStats(Surface* s, Ninja* player, BuffType buffType, std::string strVal, int intVal, float yPos, int color)
	{
		int sVal = intVal;
		std::string str = strVal, intStr;
		std::stringstream stream;
		stream << sVal;
		stream >> intStr;

		int ilenght = intStr.length();
		char* ichar_array = new char(ilenght + 1);
		strcpy(ichar_array, intStr.c_str());

		int lenght = str.length();
		char* char_array = new char(lenght + 1);
		strcpy(char_array, str.c_str());
		

		if (buffType == BuffType::Speed)
		{
			for (int i = 0; i < lenght; i++)
				s->Print(char_array, 730, yPos, color);

			for (int i = 0; i < ilenght; i++)
				s->Print(ichar_array, 765, yPos, color);
		}
		else if (buffType == BuffType::Shield)
		{
			for (int i = 0; i < lenght; i++)
				s->Print(char_array, 730, yPos, color);

			for (int i = 0; i < ilenght; i++)
				s->Print(ichar_array, 770, yPos, color);
		}
		else if (buffType == BuffType::TimeSlow)
		{
			for (int i = 0; i < lenght; i++)
				s->Print(char_array, 730, yPos, color);

			for (int i = 0; i < ilenght; i++)
				s->Print(ichar_array, 788, yPos, color);
		}
	}
};
