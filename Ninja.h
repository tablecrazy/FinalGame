#pragma once
#include "template.h"
#include "surface.h"
#include "windows.h"

namespace Tmpl8 {

	class Ninja 
	{
	public:		
		Ninja();
		Ninja(Surface* screen);
		void Init();
		void Update();		
		void Draw(Surface* screen);
		void TakeDamage(int damageTaken);

		vec2 playerPos{ 0 , 0 };

		int currentHealth = 100;
		bool shield = false;
		int speed = 1;
		int horizontalSpeed = 5;

		bool isGrounded = false;
		bool isColliding = false;

	private:

		/*VARIABLES*/
		Surface* m_screen;

		/*METHODS*/

		void PlayerGravity();
		void Input();
		
		void DrawBorders(int xMin, int xMax, int yMin, int yMax);
		void DrawCollider(Surface* s, float x, float y, float r);
		void PlayerDebug();
		
	};

};
