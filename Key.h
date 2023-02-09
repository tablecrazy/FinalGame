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
		Key(Surface* screen, Ninja* player);

		void Update(int value, float posX, float posY);
		void Draw(float posX, float posY);

		vec2 position{ 300 , 700 };

		bool won = false, collided = false;
	private:

		/*VARIABLES*/
		Surface* m_screen;
		Ninja* m_player;
		
		/*METHODS*/

		void DrawCollider(float x, float y, float r, int color);

		void Collides(float posX, float posY);

	};

}
