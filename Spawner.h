#pragma once
#include "template.h"
#include "Projectile.h"
#include "surface.h"
#include <list>
#include <iostream>
namespace Tmpl8 {

	class Spawner
	{
	public:
		Spawner();
		Spawner(Surface* screen);

		void Update(Surface* screen, float deltatime);
		void Move();
		void CreateProjectiles();
		void AddProjectilesToPool(Projectile projectile);

		void DeleteProjectiles();
		
	private:

		/*VARIABLES*/
		Surface* m_screen;
		vec2 sPos{0, 0};
		float m_time;

		/*METHODS*/
		void Shoot(Surface* screen, float deltatime);
	};

}
