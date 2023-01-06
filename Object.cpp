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
	}

	void Object::SpawnRectangle(Surface* s, int x, int y, int init1, int init2, Ninja* player)
	{
		s->Line(x - init1, y - init1, x - init1, y + init1, 0xffffff);//left
		s->Line(x - init1, y + init1, x + init2, y + init1, 0xffffff);//down
		s->Line(x + init2, y - init1, x + init2, y + init1, 0xffffff);//right
		s->Line(x - init1, y - init1, x + init2, y - init1, 0xffffff);//top

		if (collides == true)
		{	
		    s->Line(x - init1, y - init1, x - init1, y + init1, 0xF12F25);//left
		    s->Line(x + init2, y - init1, x + init2, y + init1, 0xF12F25);//right
		}

		if (player->playerPos.x <= x + init2 && player->playerPos.x + 50 >= x - init1 && player->playerPos.y <= y + init1 && player->playerPos.y + 50 >= y - init1)
		{
			player->speed = -player->speed * 0.9f;
			player->isGrounded = true;
			printf("isGr: %d \n", player->isGrounded);

			//IsAnywhereOnTheGround = true;
			//if (IsAnywhereOnTheGround == true)
			//{
			//	player->isGrounded = true;
			//	printf("ocol: %d \n", IsAnywhereOnTheGround);
			//
			//}
			//else if(IsAnywhereOnTheGround == false)
			//{
			//	player->isGrounded = false;
			//}
		}
		else
		{
			player->isGrounded = false;
			printf("isGr: %d \n", player->isGrounded);
			//IsAnywhereOnTheGround = false;
			//printf("ocol: %d \n", IsAnywhereOnTheGround);
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
		if (player->playerPos.x == x + init2 && player->playerPos.y <= y + init1 && player->playerPos.y + 50 >= y - init1)
		{
			player->playerPos.x = x + init2 + 5;
			player->isColliding = true;
		}
	}

	void Object::SpawnTunnel(Surface* s, int x, int y, int init1, int init2, Ninja* player)
	{
		s->Line(x - init1, y + init1, x + init2, y + init1, 0xffffff);//top
		s->Line(x - init1, y - init1, x + init2, y - init1, 0xffffff);//down

		if (player->playerPos.x <= x + init2 && player->playerPos.x + 50 >= x - init1 && player->playerPos.y <= y + init1 && player->playerPos.y + 50 >= y - init1)
		{
			player->playerPos.y = y - init1 - 50;
			player->speed = -player->speed * 0.8f;
			player->isGrounded = true;
			collides = true;

		} else collides = false;
		if (player->playerPos.x <= x + init2 && player->playerPos.x + 50 >= x - init1 && player->playerPos.y == y + init1)
		{
			player->playerPos.y = y + init1 + 5;
		}
		IsColliding(collides, player);
	}

	void Object::IsColliding(bool isColliding, Ninja* player)
	{
		if (isColliding == true)
		{
			player->isColliding = true;
		}
	}
};
