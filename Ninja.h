#pragma once
#include "template.h"
#include "surface.h"
#include "windows.h"
#include <string>
#include <sstream>

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
		void Death();
		void Input();
		

		vec2 playerPos{ 0 , 0 };

		int currentHealth = 100;
		bool shield = false;
		int speed = 1;
		int horizontalSpeed = 5;

		bool isGrounded = false;
		bool isColliding = false;
		bool shadowMode = false;

	private:

		/*VARIABLES*/
		Surface* m_screen;

		/*METHODS*/

		void PlayerGravity();
		
		
		void DrawBorders(int xMin, int xMax, int yMin, int yMax);
		void DrawCollider(Surface* s, float x, float y, float r);
		void Stats(Surface* s, std::string strVal, int intVal, float yPos, int color);
		void PlayerDebug();
		
	};

};
