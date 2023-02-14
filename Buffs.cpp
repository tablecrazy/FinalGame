#pragma once
#include "Ninja.h"
#include "game.h"
#include "Buffs.h"
#include "windows.h"
#include <sstream>
#include <string>

namespace Tmpl8
{
	Sprite healthSprite(new Surface("assets/HealthBuff.png"), 1);
	Sprite shieldSprite(new Surface("assets/Shield2.png"), 1);
	Sprite speedSprite(new Surface("assets/SpeedBuff.png"), 1);
	Sprite timeSlowSprite(new Surface("assets/TimeSlow.png"), 1);

	std::ostringstream oss;
	Buffs::Buffs() {}

	Buffs::Buffs(Surface* screen, Ninja* player, Spikes* spikes) :
		m_screen{ screen },
		m_ninja{ player },
		m_spikes{ spikes }
	{
	}

	void Buffs::Update(BuffType buffType, float posX, float posY, float deltatime)
	{
		if (collided == false)
		{
			if (buffType == BuffType::Health)
			{
				healthSprite.Draw(m_screen, posX - 20, posY - 20);
			}
			else if (buffType == BuffType::Speed)
			{
				speedSprite.Draw(m_screen, posX - 20, posY - 20);
			}
			else if (buffType == BuffType::Shield)
			{
				shieldSprite.Draw(m_screen, posX - 20, posY - 20);
			}
			else if (buffType == BuffType::TimeSlow)
			{
				m_time = 5;
				timeSlowSprite.Draw(m_screen, posX - 20, posY - 20);
			}
			
		}
		
		Collides(buffType, posX, posY, deltatime);
		TimeSlowBuffCheck(buffType, deltatime);
	}

	void Buffs::Draw(float posX, float posY, int color)
	{
		DrawCollider(posX, posY, 25, color);
	}

	void Buffs::DrawCollider(float x, float y, float r, int color)
	{
		for (int i = 0; i < 64; i++)
		{
			float r1 = (float)i * PI / 32, r2 = (float)(i + 1) * PI / 32;
			m_screen->Line(x - r * sinf(r1), y - r * cosf(r1),
				x - r * sinf(r2), y - r * cosf(r2), color);
		}
	}

	void Buffs::Collides(BuffType buffType, float posX, float posY, float deltatime)
	{
		if (m_ninja->playerPos.x <= posX && m_ninja->playerPos.x + 50 >= posX && m_ninja->playerPos.y <= posY && m_ninja->playerPos.y + 50 >= posY && collided == false)
		{
			
			if (buffType == BuffType::Health)
			{
				m_ninja->currentHealth += 25;
			}
			if (buffType == BuffType::Speed)
			{
				m_ninja->jumpForce += 0.15f;
				m_ninja->maximumAcceleration += 5;
			}
			else if (buffType == BuffType::Shield)
			{
				m_ninja->shield = 1;
			}
			else if (buffType == BuffType::TimeSlow)
			{
				m_spikes->speed /= 2;
			}
			collided = true;
		}
	}

	void Buffs::TimeSlowBuffCheck(BuffType buffType, float deltatime)
	{
		if (buffType == BuffType::TimeSlow)
		{
			if (m_spikes->speed != m_spikes->newSpeed)
			{
				m_time -= deltatime;
				UIStats(buffType, "Time Slow", (int)m_time, 55, 0xFFD700);
			}
			if (m_time <= 0)
			{
				m_spikes->speed = m_spikes->newSpeed;
				m_time = 5;
			}
		}
	}

	void Buffs::UIStats(BuffType buffType, std::string strVal, int intVal, float yPos, int color)
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

		if (buffType == BuffType::TimeSlow)
		{
			for (int i = 0; i < lenght; i++)
				m_screen->Print(char_array, 10, yPos, color);

			for (int i = 0; i < ilenght; i++)
				m_screen->Print(ichar_array, 68, yPos, color);
		}
	}
};
