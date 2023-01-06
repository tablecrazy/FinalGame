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
		//printf("shield: %d \n", shield);
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
	}

	void Ninja::Input()
	{
		if (GetAsyncKeyState(VK_LEFT)) playerPos.x -= horizontalSpeed;
		if (GetAsyncKeyState(VK_RIGHT)) playerPos.x += horizontalSpeed;
		if (GetAsyncKeyState(VK_UP) && isColliding == true) playerPos.y -= horizontalSpeed;
		if (GetAsyncKeyState(VK_DOWN) && isColliding == true) playerPos.y += horizontalSpeed;
		if (GetAsyncKeyState(VK_SPACE) && isGrounded == true) speed *= 1.25f;//printf("isGrounds: %d \n", isGrounded);
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


