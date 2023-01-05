#pragma once
#include "MapCreate.h"
#include "Object.h"
#include "windows.h"

namespace Tmpl8
{

	MapCreate::MapCreate() {}

	MapCreate::MapCreate(Surface* screen) :
		m_screen{ screen }
	{
	}

	void MapCreate::Init()
	{
		this->ninja = new Ninja(screen);
		this->spikes = new Spikes(screen);

		for (int i = 0; i < buffsAmmount; i++)
		{
			buffs.push_back(Buffs{});
		}
	}

	void MapCreate::Update()
	{
		buffs[0].Update(screen, BuffType::Health, ninja, spikes, 150, 400, deltaTime);
		buffs[1].Update(screen, BuffType::Speed, ninja, spikes, 300, 400, deltaTime);
		buffs[2].Update(screen, BuffType::Shield, ninja, spikes, 450, 400, deltaTime);
		buffs[3].Update(screen, BuffType::TimeSlow, ninja, spikes, 600, 400, deltaTime);
	}

};


