#pragma once
#include "template.h"
#include "surface.h"
#include "windows.h"
#include "Spikes.h"
#include <vector>
#include "Ninja.h"
#include "Buffs.h"


namespace Tmpl8 {

	class MapCreate
	{
	public:
		MapCreate();
		MapCreate(Surface* screen);
		void Init();
		void Update();

		Ninja* ninja;
		Spikes* spikes;

		float m_time;
	private:

		/*VARIABLES*/
		Surface* m_screen;

		/*METHODS*/
		Surface* screen;

		Object* object;
		int buffsAmmount = 5;
		std::vector<Buffs>buffs;

	};

};
