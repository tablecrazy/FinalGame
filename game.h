#pragma once
#include "Ninja.h"
#include "Object.h"
#include "Buffs.h"
#include "Spikes.h"
#include "MapGenerator.h"
#include "Button.h"
#include "SDL_events.h"
#include "SDL_audio.h"
#include <string>
#include <vector>

namespace Tmpl8 {

	enum class DifficultyLevel // State the ball is in.
	{
		EASY = 0,//name idea: newly bounced
		NORMAL = 1,// name idea: bouncer
		HARD = 2,//name idea: Bounce me plenty
		BALLIN = 3//name idea: BALLIN
	};

	enum class GameState
	{
		mainMenu,
		game,
		paused,
		death,
		win
	};

class Surface;
class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown(int button);
	void MouseMove(int x, int y);
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }

	DifficultyLevel diffLevel{ DifficultyLevel::EASY };

	Ninja* ninja;

	Spikes* spikes;

	MapGenerator* mapGenerator;

private:
	
	Surface* screen;

	float m_time;

	int introDialogue;

	float introNinjaFrame = 0;

	float fakeNinjaPosition = -1000;
	float fakeNinjaSpeed = 0;
	bool fakeNinjaGround = false;

	bool pressed = false;

	int buffsAmmount = 5;
	std::vector<Buffs>buffs;

	int objAmmount = 20;
	std::vector<Object> obj;

	int buttonAmmount = 10;
	std::vector<Button> button;

	vec2 mousePos;

	GameState gameState = GameState::mainMenu;

	void DifficultyProgression();

	void TimePassed(float time);
};

}; // namespace Tmpl8