#pragma once
#include "template.h"
#include "surface.h"
#include "Ninja.h"

namespace Tmpl8 {

	enum class Type
	{
		RECTANGLE,
		TUNNEL,
		WALL
	};

	class Object
	{
	public:
		Object();
		Object(Surface* screen);
		void Spawn(Surface* s, int x, int y, int init1, int init2, Ninja* player, Type type);
		void IsColliding(bool isColliding, Ninja* player);

		bool collides;
		bool IsAnywhereOnTheGround;
		
	private:

		/*VARIABLES*/
		Surface* m_screen;

		
		bool insideObj;

		int init1 = 0, init2 = 0;

		Type type{ Type::RECTANGLE };

		/*METHODS*/

		void SpawnRectangle(Surface* s, int x, int y, int init1, int init2, Ninja* player);

		void SpawnTunnel(Surface* s, int x, int y, int init1, int init2, Ninja* player);
	};

};
