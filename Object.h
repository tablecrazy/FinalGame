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
		Object(Surface* screen, Ninja* player);

		void Spawn(int x, int y, int init1, int init2, Type type);

		bool collides;
		bool collidesWith;

		Type type{ Type::RECTANGLE };
	private:

		/*VARIABLES*/
		Surface* m_screen;

		Ninja* m_player;
		
		int init1 = 0, init2 = 0;

		/*METHODS*/

		void SpawnRectangle(int x, int y, int init1, int init2);

		void SpawnTunnel(int x, int y, int init1, int init2);
	};

};
