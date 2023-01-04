#include "game.h"
#include "surface.h"
#include <cstdio> //printf
#include <array>
#include <iostream>
#include <string>
#include <SDL.h>
#include <vector>

using namespace std;

namespace Tmpl8
{
	
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	Object obj[3];
	//vector<Buffs*>buffs(3);
	//Spawner sp;
	
	bool objBool[3];
	int objVal;

	void Game::Init()
	{
		
		this->ninja = new Ninja(screen);
		this->spikes = new Spikes(screen);

		for (int i = 0; i < buffsAmmount; i++)
		{
			buffs.push_back(Buffs{});
		}
	}
	
	// -----------------------------------------------------------
	// Close down application
	// -----------------------------------------------------------
	void Game::Shutdown()
	{
		
	}

	// -----------------------------------------------------------
	// Main application tick function
	// -----------------------------------------------------------
	void Game::Tick(float deltaTime)
	{
		srand(getpid());
		deltaTime /= 1000;

		screen->Clear(0);
		ninja->Update();
		spikes->Update(ninja);
		obj[0].Spawn(screen, 500, 200, 75, 75, ninja, Type::RECTANGLE);
		obj[1].Spawn(screen, 200, 200, 75, 75, ninja, Type::RECTANGLE);

		buffs[0].Update(screen, BuffType::Health, ninja, spikes, 150, 400);
		buffs[1].Update(screen, BuffType::Speed, ninja, spikes, 300, 400);
		buffs[2].Update(screen, BuffType::Shield, ninja, spikes, 450, 400);
		buffs[3].Update(screen, BuffType::TimeSlow, ninja, spikes, 600, 400);
		//sp.Update(screen, deltaTime);
		
		m_time += deltaTime;
		DifficultyProgression();
		
	}

	void Game::DifficultyProgression()
	{

		if (m_time >= 5 && m_time <= 10)
		{
			diffLevel = DifficultyLevel::NORMAL;
		}
		else if (m_time >= 10 && m_time <= 15)
		{
			diffLevel = DifficultyLevel::HARD;
		}
		else if (m_time >= 15)
		{
			diffLevel = DifficultyLevel::BALLIN;
		}

		switch (diffLevel) {
		case DifficultyLevel::EASY:
			//default difficulty defining variables
			screen->Print("Just bounced", 10, 40, 0x96FF00);
			break;
		case DifficultyLevel::NORMAL:
			//increase spawn rate, projectile speed, dmg(only if character has health)
			screen->Print("Bouncer", 10, 40, 0xFDC526);
			break;
		case DifficultyLevel::HARD:
			//increase spawn rate, projectile speed, dmg(only if character has health)
			screen->Print("Bounce me plenty", 10, 40, 0xFDC526);
			break;
		case DifficultyLevel::BALLIN:
			//increase spawn rate, projectile speed, dmg(only if character has health), spawn projectiles everywhere(in other difficulties the spawn will be a safe place)
			screen->Print("BALLIN!!!", 10, 40, 0xF12F25);
			break;
		}

		
	}
};