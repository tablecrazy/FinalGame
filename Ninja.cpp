 #pragma once
#include "Ninja.h"
#include "Object.h"
#include "windows.h"

namespace Tmpl8
{
	Sprite ninja(new Surface("assets/ninja.png"), 1);
	Sprite ninjaS(new Surface("assets/ninjaS.png"), 1);

	Ninja::Ninja() {}

	Ninja::Ninja(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Ninja::Init()
	{
		
	}

	void Ninja::Update()
	{

		PlayerGravity();

		Draw(m_screen);

		DrawBorders(0, 750, playerPos.y, playerPos.y);

		Input();

		//PlayerDebug();
		//printf("isGrounds: %d \n", isGrounded);
	}

	void Ninja::Draw(Surface* screen)
	{
		if (isGrounded == false)
		{
			ninja.Draw(screen, playerPos.x, playerPos.y);
		}
		else
		{
			ninjaS.Draw(screen, playerPos.x, playerPos.y);
		}

		DrawCollider(screen, playerPos.x + 25, playerPos.y + 25, 25);
		Stats(screen, "Health: ", currentHealth, 10, 0x96FF00);
		Stats(screen, "Speed: ", horizontalSpeed, 25, 0xadd8e6);
	}

	void Ninja::Input()
	{
		if (GetAsyncKeyState(VK_LEFT)) playerPos.x -= horizontalSpeed;
		if (GetAsyncKeyState(VK_RIGHT)) playerPos.x += horizontalSpeed;
		if (GetAsyncKeyState(VK_UP) && isColliding == true) playerPos.y -= horizontalSpeed;
		if (GetAsyncKeyState(VK_DOWN) && isColliding == true) playerPos.y += horizontalSpeed;
		if (GetAsyncKeyState(VK_SPACE) && isGrounded == true) speed *= 1.25f;
	}

	void Ninja::TakeDamage(int damageTaken)
	{
		if (shield == true)
		{
			shield = false;
		}
		else currentHealth -= damageTaken;
	}

	void Ninja::Death()
	{
		if (currentHealth <= 0)
		{
			printf("DEAD\n");
		}
			
	}

	void Ninja::PlayerGravity()
	{
		playerPos.y += speed;
		speed += 1.0f;
	}

	void Ninja::DrawCollider(Surface* s, float x, float y, float r)
	{
		for (int i = 0; i < 64; i++)
		{
			float r1 = (float)i * PI / 32, r2 = (float)(i + 1) * PI / 32;
			s->Line(x - r * sinf(r1), y - r * cosf(r1),
				x - r * sinf(r2), y - r * cosf(r2), 0xff0000);
		}
	}

	void Ninja::Stats(Surface* s, std::string strVal, int intVal, float yPos, int color)
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

		for (int i = 0; i < lenght; i++)
			s->Print(char_array, 720, yPos, color);
		for (int i = 0; i < ilenght; i++)
			s->Print(ichar_array, 760, yPos, color);
	}

	void Ninja::PlayerDebug()
	{
		printf("Speed: %d \n", speed);
		printf("x: %d ", (int)playerPos.x);
		printf("y: %d \n", (int)playerPos.y);
	}

	void Ninja::DrawBorders(int xMin, int xMax, int yMin, int yMax)
	{
		if (playerPos.x < (xMin))
		{
			playerPos.x = xMin;

		}
		if (playerPos.x > (xMax))
		{
			playerPos.x = xMax;

		}
		if (playerPos.y > (700 - 50))
		{
			playerPos.y = 700 - 50;
			speed = -speed * 0.8f;
			isGrounded = true;
		}
		else
		{
			isGrounded = false;
		}
		if (playerPos.y < (0))
		{
			playerPos.y = 0;
		}
	}
};


