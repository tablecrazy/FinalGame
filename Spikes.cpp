#pragma once
#include "Ninja.h"
#include "Spikes.h"
#include "Object.h"
#include "windows.h"

namespace Tmpl8
{
	Sprite spikes(new Surface("assets/spikes.png"), 1);

	Spikes::Spikes() {}

	Spikes::Spikes(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Spikes::Update(Ninja* player)
	{
		Draw(m_screen);
		Collider(player);
	}

	void Spikes::Draw(Surface* screen)
	{
		spikes.Draw(screen, spikesPos.x, spikesPos.y);

		DrawCollider(screen);
	}

	void Spikes::DrawCollider(Surface* s)
	{
		//s->Line(0, spikesPos.y, 1920, spikesPos.y, 0xF12F25);
		Move();
	}

	void Spikes::Move()
	{
		spikesPos.y -= speed;
	}

	void Spikes::Collider(Ninja* player)
	{
		if (player->playerPos.y > (spikesPos.y - 50))
		{
			player->playerPos.y = spikesPos.y - 50;
			player->speed = -25;

			player->TakeDamage(damage);
		}
	}
};


