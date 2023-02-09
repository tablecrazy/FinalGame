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
		Buffs(Surface* screen, Ninja* player, Spikes* spikes);

		void Update(BuffType type, float posX, float posY, float deltatime);
		void Draw(float posX, float posY, int color);

		vec2 position{ 300 , 700 };

	private:

		/*VARIABLES*/
		Ninja* m_ninja;
		Spikes* m_spikes;
		Surface* m_screen;

		float m_time = 1;

		bool collided = false;
		

		BuffType buffType;

		std::vector<Sprite>buffSprites[4];

		/*METHODS*/

		void DrawCollider(float x, float y, float r, int color);

		void Collides(BuffType buffType, float posX, float posY, float deltatime);

		void UIStats(BuffType buffType, std::string strVal, int intVal, float yPos, int color);

		void TimeSlowBuffCheck( BuffType buffType, float deltatime);

	};

}
