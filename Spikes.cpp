#pragma once
#include "Ninja.h"
#include "Spikes.h"
#include "Object.h"
#include "windows.h"

namespace Tmpl8
{
	Sprite spikes(new Surface("assets/at2.png"), 1);

	Spikes::Spikes() {}

	Spikes::Spikes(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Spikes::Update()
	{
		Draw(m_screen);
	}

	void Spikes::Draw(Surface* screen)
	{
		spikes.Draw(screen, spikesPos.x, spikesPos.y);

		DrawCollider(screen, spikesPos.y);
	}

	void Spikes::DrawCollider(Surface* s, float y)
	{
		s->Line(0, y - 100, 800, y - 100, 0xffffff);//top
	}

	void Spikes::Collider(Ninja* player, float yPos)
	{
		
		if (player->playerPos.y + 50 >= yPos - 100)
		{
			player->speed = -player->speed * 0.9f;
		}
	}
};


