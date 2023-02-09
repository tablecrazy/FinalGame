#pragma once
#include "template.h"
#include "surface.h"
#include "windows.h"
#include <string>
#include <sstream>
#include <vector>

namespace Tmpl8 {

	class Ninja 
	{
	public:		
		Ninja();
		Ninja(Surface* screen);

		/*METHODS*/
		void Update();

		void Draw(Surface* screen);

		void TakeDamage(int damageTaken);

		void SustainVelocity();

		/*VARIABLES*/

		vec2 playerPos{ 0 , 0 };
		
		int currentHealth = 100;

		int speed = 1;
		int horizontalSpeed = 5;
		float maximumAcceleration = 23;
		float jumpForce = 1.25f;

		float invinsFrames = 0;

		bool shield = false;
		bool dead = false;

		bool isGrounded = false;
		bool isColliding = false;
		
		bool rWall, lWall;

	private:

		/*VARIABLES*/
		Surface* m_screen;

		/*METHODS*/
		void Input();
		void PlayerGravity();
		void Death();
		void FrameClock();
		
		void DrawBorders(int xMin, int xMax, int yMin, int yMax);
		void DrawCollider(Surface* s, float x, float y, float r);

		void Stats(Surface* s, std::string strVal, int intVal, float numX, float yPos, int color);
		void PlayerDebug();
		
	};

};
