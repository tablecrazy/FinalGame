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
		void Update(Surface* s, BuffType type, Ninja* player, Spikes* spikes, float posX, float posY, float deltatime);
		void Draw(Surface* screen, float posX, float posY, int color);
		vec2 position{ 300 , 700 };

	private:

		/*VARIABLES*/
		Ninja* ninja;
		Spikes* spikes;
		Surface* m_screen;

		float m_time = 1;

		bool collided = false;
		bool speedCheck, shiledCheck, timeSlowCheck;
		

		BuffType buffType;

		/*METHODS*/

		void DrawCollider(Surface* s, float x, float y, float r, int color);

		void Collides(Surface* s, BuffType buffType, Ninja* player, Spikes* spikes, float posX, float posY, float deltatime);

		void UIStats(Surface* s, Ninja* player, BuffType buffType, std::string strVal, int intVal, float yPos, int color);

		void SpeedBuffCheck(Surface* s, BuffType buffType, Ninja* player, float deltatime);

		void ShieldBuffCheck(Surface* s, BuffType buffType, Ninja* player, float deltatime);

		void TimeSlowBuffCheck(Surface* s, BuffType buffType, Spikes* spikes, float deltatime);

	};

}
