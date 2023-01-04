#pragma once
#include "template.h"
#include "surface.h"
#include "Ninja.h"
#include "Spikes.h"

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
		void Update(Surface* s, BuffType type, Ninja* player, Spikes* spikes, float posX, float posY);
		void Draw(Surface* screen, float posX, float posY, int color);
		vec2 position{ 300 , 700 };

	private:

		/*VARIABLES*/
		Ninja* ninja;
		Spikes* spikes;
		Surface* m_screen;

		bool collided = false;
		

		BuffType buffType;

		/*METHODS*/

		void DrawCollider(Surface* s, float x, float y, float r, int color);

		void Collides(Surface* s, BuffType buffType, Ninja* player, Spikes* spikes, float posX, float posY);

		void UIStats(Surface* s,Ninja* player, BuffType buffType);

	};

}
