#pragma once
#include "template.h"
#include "surface.h"
#include "Ninja.h"
#include "Spikes.h"

namespace Tmpl8 {

	class Key
	{
	public:
		Key();
		Key(Surface* screen);
		void Update(Surface* s, Ninja* player, float posX, float posY);
		void Draw(Surface* screen, float posX, float posY);

		vec2 position{ 300 , 700 };
		bool won = false;
	private:

		/*VARIABLES*/
		Ninja* ninja;

		Surface* m_screen;

		
		/*METHODS*/

		void DrawCollider(Surface* s, float x, float y, float r, int color);

		void Collides(Ninja* player, float posX, float posY);

	};

}
