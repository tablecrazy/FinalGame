#pragma once
#include "template.h"
#include "surface.h"

namespace Tmpl8 {

	class Mouse
	{
	public:
		Mouse();
		Mouse(Surface* screen);
		void Update();
		void MouseMove(int x, int y);
		void MouseDown(int button);

		vec2 mousePos;
	private:

		/*VARIABLES*/
		Surface* m_screen;

		
		/*METHODS*/
	};

}
