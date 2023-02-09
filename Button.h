#pragma once
#include "template.h"
#include "surface.h"

namespace Tmpl8 {

	enum class ButtonType
	{
		StartGame,
		Reset,
		Continue,
		Quit
	};

	class Button
	{
	public:
		Button();
		Button(Surface* screen);
		void Update(ButtonType buttonType, float xPos, float yPos, float init1, float init2);

		void InRange(float x, float y);

		vec2 buttonPos;

		float initVal1, initVal2;

		bool clickable = false;

		bool pressed = false;

	private:

		/*VARIABLES*/
		Surface* m_screen;

		ButtonType buttonType;

		/*METHODS*/
		void Draw(ButtonType buttonType, float xPos, float yPos, float init1, float init2);
		
	};

}
