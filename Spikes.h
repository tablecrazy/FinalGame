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
		void Update(Ninja* player);
		void Draw(Surface* screen);

		vec2 spikesPos{ 0 , 900 };
		float speed = 0.2;
		float newSpeed = speed;

	private:

		/*VARIABLES*/
		Surface* m_screen;
		Ninja* ninja;

		int damage = 25;

		/*METHODS*/
		void DrawCollider(Surface* s);
		void Move();
		void Collider(Ninja* player);
	};

};
