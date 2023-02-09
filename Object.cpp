#pragma once
#include "Ninja.h"
#include "game.h"
#include "Object.h"
#include "windows.h"

namespace Tmpl8
{

	Object::Object() {}

	Object::Object(Surface* screen, Ninja* player) :
		m_screen{ screen },
		m_player{player}
	{
	}

	

	void Object::Spawn(int x, int y, int init1, int init2, Type type)
	{
		if (type == Type::RECTANGLE)
		{
			Object::SpawnRectangle(x, y, init1, init2);
		}
		else if (type == Type::TUNNEL)
		{
			Object::SpawnTunnel(x, y, init1, init2);
		}
		m_player->SustainVelocity();
	}

	void Object::SpawnRectangle(int x, int y, int init1, int init2)
	{
		//m_screen->Line(x - init1, y - init1, x - init1, y + init1, 0xffffff);//left
		//m_screen->Line(x - init1, y + init1, x + init2, y + init1, 0xffffff);//down
		//m_screen->Line(x + init2, y - init1, x + init2, y + init1, 0xffffff);//right
		//m_screen->Line(x - init1, y - init1, x + init2, y - init1, 0xffffff);//top

		bool colliding = (m_player->playerPos.x <= x + init2 && m_player->playerPos.x + 50 >= x - init1 && m_player->playerPos.y <= y + init1 && m_player->playerPos.y + 50 >= y - init1);
		if (colliding) {
			m_player->isGrounded = true;
			m_player->speed = -m_player->speed * 0.9f;
			if (GetAsyncKeyState(VK_SPACE) && m_player->isGrounded) {
				m_player->speed *= 1.25f;
			}
		}
		if (colliding && m_player->playerPos.y == y + init1) {
			m_player->playerPos.y = y + init1 + 5;
		}
		if (colliding && m_player->playerPos.x == x - (init1 + 50)) {
			m_player->playerPos.x = x - (init1 + 55);
			m_player->isColliding = true;
			m_player->lWall = true;
		}
		if (colliding && m_player->playerPos.x == x + init2) {
			m_player->playerPos.x = x + init2 + 5;
			m_player->isColliding = true;
			m_player->rWall = true;
		}
		
	}

	void Object::SpawnTunnel(int x, int y, int init1, int init2)
	{
		//m_screen->Line(x - init1, y + init1, x + init2, y + init1, 0xffffff);//top
		//m_screen->Line(x - init1, y - init1, x + init2, y - init1, 0xffffff);//down

		bool colliding = (m_player->playerPos.x <= x + init2 && m_player->playerPos.x + 50 >= x - init1 && m_player->playerPos.y <= y + init1 && m_player->playerPos.y + 50 >= y - init1);
		if (colliding) {
			m_player->isGrounded = true;
			m_player->isColliding = true;
			m_player->speed = -m_player->speed * 0.9f;
			if (GetAsyncKeyState(VK_SPACE) && m_player->isGrounded) {
				m_player->speed *= 1.25f;
			}
		}
		if (colliding && m_player->playerPos.y == y + init1) {
			m_player->playerPos.y = y + init1 + 5;
		}
	}
};
