#pragma once
#include "template.h"
#include "surface.h"
#include "Ninja.h"
#include "Spikes.h"

namespace Tmpl8 {

	enum class SnSide
	{
		Vectical,
		Horizontal
	};

	class BouncingShuriken
	{
	public:
		BouncingShuriken();
		BouncingShuriken(Surface* screen, Ninja* player);

		void Update(SnSide snSide, float posX, float posY, float size, float speed, float deltatime);
		void Draw(SnSide snSide, float posX, float posY, int color, float size);

		vec2 position;
		float m_speed = 0;

	private:

		/*VARIABLES*/
		Ninja* m_ninja;
		Surface* m_screen;

		vec2 shurikenPos;

		int frame = 0;

		bool pointReached;
		bool collided = false;
		bool shurikenPositioned = false;

		SnSide snSide;

		/*METHODS*/
		void DrawCollider(float x, float y, float r, int color);
		void Bounce(SnSide snSide, float posX, float posY, float size, float speed);
		void Collides();

	};

}
