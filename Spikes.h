#pragma once
#include "template.h"
#include "surface.h"
#include "windows.h"
#include "Ninja.h"
namespace Tmpl8 {

	class Spikes
	{
	public:
		Spikes();
		Spikes(Surface* screen);
		void Update();
		void Draw(Surface* screen);

		vec2 spikesPos{ 0 , 300 };
		int speed = 1;

	private:

		/*VARIABLES*/
		Surface* m_screen;
		Ninja* ninja;

		/*METHODS*/
		void DrawCollider(Surface* s, float y);
		void Collider(Ninja* player, float yPos);
	};

};
