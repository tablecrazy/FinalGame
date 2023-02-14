 #pragma once

#include "Ninja.h"
#include "Object.h"
#include "windows.h"

namespace Tmpl8
{
	Sprite ninja(new Surface("assets/ninja.png"), 1);
	Sprite ninjaL(new Surface("assets/ninjaL.png"), 1);
	Sprite ninjaR(new Surface("assets/ninjaR.png"), 1);

	

	Ninja::Ninja() {}

	Ninja::Ninja(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Ninja::Update()
	{
		PlayerGravity();

		Draw(m_screen);

		DrawBorders(0, 1860, playerPos.y, playerPos.y);

		Input();

		Death();

		FrameClock();

		Stats(m_screen, "Health: ", currentHealth, 55, 10, 0x96FF00);
		Stats(m_screen, "Speed: ", speed, 55, 25, 0xadd8e6);
		Stats(m_screen, "Shield: ", shield, 55, 40, 0x0096FF);
	}

	void Ninja::Draw(Surface* screen)
	{
		if (lWall) {
			ninjaL.Draw(screen, playerPos.x, playerPos.y);
		}
		else if (rWall) {
			ninjaR.Draw(screen, playerPos.x, playerPos.y);
		}
		else {
			ninja.Draw(screen, playerPos.x, playerPos.y);
		}
		
	}

	void Ninja::Input()
	{
		if (GetAsyncKeyState(VK_LEFT)) playerPos.x -= horizontalSpeed;
		if (GetAsyncKeyState(VK_RIGHT)) playerPos.x += horizontalSpeed;
		if (GetAsyncKeyState(VK_UP) && isColliding == true) playerPos.y -= horizontalSpeed;
		if (GetAsyncKeyState(VK_DOWN) && isColliding == true) playerPos.y += horizontalSpeed;
		if (GetAsyncKeyState(VK_SPACE) && isGrounded == true) speed *= jumpForce;
	}

	void Ninja::TakeDamage(int damageTaken)
	{
		if (invinsFrames <= 0)
		{
			if (shield == true)
			{
				shield = false;
			}
			else currentHealth -= damageTaken;
			invinsFrames = 30;
			
		}
	}

	void Ninja::FrameClock()
	{
		if (invinsFrames > 0)
		{
			invinsFrames -= 1;
		}
	}

	void Ninja::Death()
	{
		dead = (currentHealth <= 0);
	}

	void Ninja::PlayerGravity()
	{
		playerPos.y += speed;
		speed += 1.0f;

		speed = min(maximumAcceleration, max(-maximumAcceleration, speed));

	}

	void Ninja::SustainVelocity()
	{
		if (speed >= 0 && speed <= 1 && isGrounded == true && isColliding == false)
		{
			speed -= 10;
		}
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

	void Ninja::Stats(Surface* s, std::string strVal, int intVal, float numX, float yPos, int color)
	{
		std::string str = strVal;

		std::string intStr = std::to_string(intVal);

		s->Print(&(str)[0], 10, yPos, color);

		s->Print(&(intStr)[0], numX, yPos, color);
	}

	void Ninja::PlayerDebug()
	{
		printf("Speed: %d \n", speed);
		printf("x: %d ", (int)playerPos.x);
		printf("y: %d \n", (int)playerPos.y);
	}

	void Ninja::DrawBorders(int xMin, int xMax, int yMin, int yMax)
	{
		if (playerPos.y > (2000 - 50))
		{
			playerPos.y = 2000 - 50;
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
		lWall = playerPos.x < xMin;
		rWall = playerPos.x > xMax;
		playerPos.x = min(max(playerPos.x, xMin), xMax);
		playerPos.y = min(max(playerPos.y, 0), 2000 - 50);
	}
};


