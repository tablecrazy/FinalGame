#pragma once
#include "template.h"
#include "surface.h"
namespace Tmpl8 {

	enum class Side
	{
		LEFT,
		RIGHT
	};

	class Projectile
	{
	public:
		Projectile();
		Projectile(Surface* screen);
		void Update(Surface* s, float speed, float yPos);
		void Draw(Surface* screen, float yPos);

		vec2 projPos{ 0, 0 };
		float newYPos;

		int bouncesLeft = 2;
		bool inUse, isDrawn;
	private:

		/*VARIABLES*/
		Surface* m_screen;
		Side side{ Side::LEFT };
		float speed;
		
		//optional float damage;


		/*METHODS*/
		void Init();
		void Move(float speed);
		void Bounce();
		void BounceSpan();
		void DealDamage();
	};

}
