#pragma once
#include "Ninja.h"
#include "Projectile.h"
#include "Object.h"
#include "Spawner.h"
#include "Buffs.h"
#include "Spikes.h"
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

class Surface;
class Game
{
public:
	void SetTarget( Surface* surface ) { screen = surface; }
	void Init();
	
	void Shutdown();
	void Tick( float deltaTime );
	void MouseUp( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseDown( int button ) { /* implement if you want to detect mouse button presses */ }
	void MouseMove( int x, int y ) { /* implement if you want to detect mouse movement */ }
	void KeyUp( int key ) { /* implement if you want to handle keys */ }
	void KeyDown( int key ) { /* implement if you want to handle keys */ }

	DifficultyLevel diffLevel{ DifficultyLevel::EASY };

	Ninja* ninja;
	Spikes* spikes;
	Projectile* projectile;
	Spawner spawner;

	float m_time;

private:
	

	Surface* screen;

	Object* object;
	//Buffs* buffs;
	int buffsAmmount = 5;
	std::vector<Buffs>buffs;

	void DifficultyProgression();

	void TimePassed(float time);

	
};

}; // namespace Tmpl8