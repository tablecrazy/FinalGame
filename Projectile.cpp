#pragma once
#include "Projectile.h"
#include "game.h"
#include "windows.h"

namespace Tmpl8
{
	Sprite proj(new Surface("assets/ball.png"), 1);
	Projectile::Projectile() {}

	Projectile::Projectile(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Projectile::Init()
	{
		switch (side) {
		case Side::LEFT:
			projPos.x = 745;
			break;
		case Side::RIGHT:
			projPos.x = 5;
			break;
		}
	}

	void Projectile::Update(Surface* s,float speed, float yPos)
	{
		Draw(s, yPos);
		Move(speed);
		//printf("%d\n", (int)projPos.x);
		////printf("%d\n", side);
		//printf("Bounces Left: %d\n", bouncesLeft);
	}

	void Projectile::Move(float speed)
	{
		if (isDrawn == true)
		{
			switch (side) {
			case Side::LEFT:
				projPos.x -= speed;
				break;
			case Side::RIGHT:
				projPos.x += speed;
				break;
			}
			Bounce();
		}
		
	}

	void Projectile::Draw(Surface* screen, float yPos)
	{
		proj.Draw(screen, projPos.x, yPos);
		isDrawn = true;
	}

	void Projectile::Bounce()
	{
		if (bouncesLeft > 0)
		{
			if (projPos.x < (0))
			{
				projPos.x = 0;
				bouncesLeft--;
				printf("RIGHT");
				side = Side::RIGHT;

			}
			if (projPos.x >= (750))
			{
				projPos.x = 750;
				bouncesLeft--;
				printf("LEFT");
				side = Side::LEFT;

			}
		}

		if (projPos.x < -1 || projPos.x > 751)
		{
			inUse = false;
		}
		
	}

}