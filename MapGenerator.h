#pragma once
#include "template.h"
#include "surface.h"
#include "windows.h"
#include "Ninja.h"
#include "Spikes.h"
#include "Object.h"
#include "Buffs.h"
#include "Key.h"
#include "BouncingShuriken.h"
#include <vector>

namespace Tmpl8 {

	class MapGenerator
	{
	public:
		MapGenerator();
		MapGenerator(Surface* screen, Ninja* player, Spikes* spikes);

		/*METHODS*/
		void Init();
		void LoadLevel(float deltaTime);

		/*VARIABLES*/
		int level = 0;

		Spikes* spikes;
	private:

		/*VARIABLES*/
		Surface* m_screen;

		Ninja* ninja;

		Object* object;

		Key* key;

		int buffsAmmount = 20;
		std::vector<Buffs>buffs;

		int objAmmount = 20;
		std::vector<Object> obj;

		int bShurikenAmmount = 30;
		std::vector<BouncingShuriken> bShurikens;

		bool characterSpawned = false;

		/*METHODS*/

	};

};


