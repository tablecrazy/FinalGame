#pragma once
#include "Ninja.h"
#include "game.h"
#include "Object.h"
#include "windows.h"

namespace Tmpl8
{

	Object::Object() {}

	Object::Object(Surface* screen) :
		m_screen{ screen }
	{
	}

	

	void Object::Spawn(Surface* s, int x, int y, int init1, int init2, Ninja* player, Type type)
	{
		if (type == Type::RECTANGLE)
		{
			Object::SpawnRectangle(s, x, y, init1, init2, player);
		}
		else if (type == Type::TUNNEL)
		{
			Object::SpawnTunnel(s, x, y, init1, init2, player);
		}

		SustainVelocity(player);
	}

	void Object::SpawnRectangle(Surface* s, int x, int y, int init1, int init2, Ninja* player)
	{
		s->Line(x - init1, y - init1, x - init1, y + init1, 0xffffff);//left
		s->Line(x - init1, y + init1, x + init2, y + init1, 0xffffff);//down
		s->Line(x + init2, y - init1, x + init2, y + init1, 0xffffff);//right
		s->Line(x - init1, y - init1, x + init2, y - init1, 0xffffff);//top

		if (player->playerPos.x <= x + init2 && player->playerPos.x + 50 >= x - init1 && player->playerPos.y <= y + init1 && player->playerPos.y + 50 >= y - init1)
		{
			player->isGrounded = true;
			player->speed = -player->speed * 0.9f;

			if (GetAsyncKeyState(VK_SPACE) && player->isGrounded == true) player->speed *= 1.25f;
		}
		if (player->playerPos.x <= x + init2 && player->playerPos.x + 50 >= x - init1 && player->playerPos.y == y + init1)
		{
			player->playerPos.y = y + init1 + 5;
		}
		if (player->playerPos.x == x - (init1 + 50) && player->playerPos.y <= y + init1 && player->playerPos.y + 50 >= y - init1)
		{
			player->playerPos.x = x - (init1 + 55);
			player->isColliding = true;
		}
		else player->isColliding = false;
		if (player->playerPos.x == x + init2 && player->playerPos.y <= y + init1 && player->playerPos.y + 50 >= y - init1)
		{
			player->playerPos.x = x + init2 + 5;
			player->isColliding = true;
		}
		else player->isColliding = false;

	}

	void Object::SpawnTunnel(Surface* s, int x, int y, int init1, int init2, Ninja* player)
	{
		s->Line(x - init1, y + init1, x + init2, y + init1, 0xffffff);//top
		s->Line(x - init1, y - init1, x + init2, y - init1, 0xffffff);//down

		if (player->playerPos.x <= x + init2 && player->playerPos.x + 50 >= x - init1 && player->playerPos.y <= y + init1 && player->playerPos.y + 50 >= y - init1)
		{
			player->isGrounded = true;

			player->isColliding = true;

			player->speed = -player->speed * 0.9f;

			if (GetAsyncKeyState(VK_SPACE) && player->isGrounded == true) player->speed *= 1.25f;

		}
		if (player->playerPos.x <= x + init2 && player->playerPos.x + 50 >= x - init1 && player->playerPos.y == y + init1)
		{
			player->playerPos.y = y + init1 + 5;
			
		}
	}

	void Object::SustainVelocity(Ninja* player)
	{
		if (player->speed == 0 && player->isGrounded == true && player->isColliding == false)
		{
			player->speed -= 10;
		}
	}
};
