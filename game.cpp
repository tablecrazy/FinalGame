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
	//mouse sprite
	Sprite shuriken(new Surface("assets/cursor1.png"), 1);

	//backgroundSprite
	Sprite introBc(new Surface("assets/IntroBC.png"), 1);
	Sprite bc(new Surface("assets/backgroundOr.png"), 1);
	Sprite bcD(new Surface("assets/background.png"), 1);
	Sprite bcBnW(new Surface("assets/backgroundBnW.png"), 1);

	//intro sprites
	Sprite bigNinjaEyes(new Surface("assets/bigNinjaEyes.tga"), 6);

	//ending sprites
	Sprite bigNinja(new Surface("assets/bigNinja.png"), 1);
	Sprite bigNinjaS(new Surface("assets/bigNinjaS.png"), 1);

	Sprite youLost(new Surface("assets/YouLost.png"), 1);
	
	
	// -----------------------------------------------------------
	// Initialize the application
	// -----------------------------------------------------------
	vec2 mousePos = {0, 0};

	void Game::Init()
	{
		ShowCursor(false);
		this->ninja = new Ninja(screen);

		this->mapGenerator = new MapGenerator(screen, ninja, spikes);

		for (int i = 0; i < buttonAmmount; i++)
		{
			button.push_back(Button{screen});
		}

		mapGenerator->Init();
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
		printf("Health: %d \n", ninja->currentHealth);
		switch (gameState)
		{
		case GameState::game:

			printf("IGRAAAAAA");
			
			
			if (mapGenerator->level == 0)
			{
				introBc.Draw(screen, 0, 0);
			}
			else
			{
				bc.Draw(screen, 0, 0);
			}

			ninja->Update();

			mapGenerator->LoadLevel(deltaTime);

			if (mapGenerator->level == 5)
			{
				button[5].Update(ButtonType::Quit, 800, 500, 75, 300);
			}

			m_time += deltaTime;

			if (ninja->dead == true)
			{
				gameState = GameState::death;
			}

			if (GetAsyncKeyState(VK_ESCAPE)) gameState = GameState::paused;
			break;
		case GameState::mainMenu:
			bcD.Draw(screen, 0, 0);
			button[0].Update(ButtonType::StartGame, 800, 400, 75, 300);
			button[1].Update(ButtonType::Quit, 800, 600, 75, 300);
			break;
		case GameState::paused:
			
			bcBnW.Draw(screen, 0, 0);
			button[2].Update(ButtonType::Continue, 800, 400, 75, 300);
			button[3].Update(ButtonType::Quit, 800, 600, 75, 300);
			break;
		case GameState::death:
			fakeNinjaSpeed = 10; 
			fakeNinjaPosition += fakeNinjaSpeed;
			if (fakeNinjaPosition > 1100 - 600)
			{
				fakeNinjaPosition = 1100 - 600;

				button[4].Update(ButtonType::Quit, 800, 500, 75, 300);

				youLost.Draw(screen, 740, 100);
				bigNinjaS.Draw(screen, 500, fakeNinjaPosition + 350);

			}else bigNinja.Draw(screen, 650, fakeNinjaPosition);
			break;
		}
		
	}

	void Game::MouseMove(int x, int y)
	{
		mousePos.x = x;
		mousePos.y = y;

		shuriken.Draw(screen, mousePos.x - 20, mousePos.y -20);
		switch (gameState)
		{
		case GameState::game:
			button[5].InRange(mousePos.x, mousePos.y);
			break;

		case GameState::mainMenu:
			button[0].InRange(mousePos.x, mousePos.y);
			button[1].InRange(mousePos.x, mousePos.y);
			break;

		case GameState::paused:

			button[2].InRange(mousePos.x, mousePos.y);
			button[3].InRange(mousePos.x, mousePos.y);
			//pause stuff menu
			break;

		case GameState::death:
			button[4].InRange(mousePos.x, mousePos.y);
			break;
		}
	
	}

	void Game::MouseDown(int buttons)
	{
		if (button[0].clickable == true)
		{
			ninja->currentHealth = 100;
			ninja->jumpForce = 1.25f;
			ninja->maximumAcceleration = 23;

			gameState = GameState::game;
			button[0].clickable = false;
		}
		if (button[1].clickable)
		{
			SDL_Quit();
			return;
		}
		if (button[2].clickable)
		{
			gameState = GameState::game;
		}
		if (button[3].clickable)
		{
			SDL_Quit();
			
		}
		if (button[4].clickable)
		{
			SDL_Quit();
			
		}
		if (button[5].clickable)
		{
			SDL_Quit();

		}
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