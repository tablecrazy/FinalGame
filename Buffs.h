#pragma once
#include "template.h"
#include "surface.h"
#include "Ninja.h"

namespace Tmpl8 {

	enum class BuffType
	{
		Health,
		Speed,
		Shield,
		TimeSlow
	};

	class Buffs
	{
	public:
		Buffs();
		Buffs(Surface* screen);
		void Update(Surface* s, BuffType type, Ninja* player, float posX, float posY);
		void Draw(Surface* screen, float posX, float posY, int color);
		vec2 position{ 300 , 700 };

	private:

		/*VARIABLES*/
		Ninja* ninja;
		Surface* m_screen;
		bool collided = false;

		BuffType buffType;

		/*METHODS*/

		void DrawCollider(Surface* s, float x, float y, float r, int color);

		void Collides(BuffType buffType, Ninja* player, float posX, float posY);

	};

}
