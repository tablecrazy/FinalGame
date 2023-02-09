#pragma once
#include "Button.h"
#include "game.h"
#include "windows.h"

namespace Tmpl8
{
	Sprite startButton(new Surface("assets/StartButton.png"), 1);
	Sprite continueButton(new Surface("assets/ContinueButton.png"), 1);
	Sprite resetButton(new Surface("assets/ResetButton.png"), 1);
	Sprite quitButton(new Surface("assets/QuitButton.png"), 1);

	Button::Button() {}

	Button::Button(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Button::Update(ButtonType buttonType, float xPos, float yPos, float init1, float init2)
	{
		buttonPos.x = xPos;
		buttonPos.y = yPos;

		initVal1 = init1;
		initVal2 = init2;

		Draw(buttonType, xPos, yPos, init1, init2);
		
	}

	void Button::InRange(float x, float y)
	{
		if (x <= buttonPos.x + initVal2 && x >= buttonPos.x - initVal1 && y <= buttonPos.y + initVal1 && y >= buttonPos.y - initVal1)
		{
			clickable = true;
			printf("can be clicked : %d \n", clickable);
		}
		else
		{
			clickable = false;
		}
	}

	void Button::Draw(ButtonType buttonType, float xPos, float yPos, float init1, float init2)
	{
		m_screen->Line(xPos - init1, yPos - init1, xPos - init1, yPos + init1, 0x000000);//left
		m_screen->Line(xPos - init1, yPos + init1, xPos + init2, yPos + init1, 0x000000);//down
		m_screen->Line(xPos + init2, yPos - init1, xPos + init2, yPos + init1, 0x000000);//right
		m_screen->Line(xPos - init1, yPos - init1, xPos + init2, yPos - init1, 0x000000);//top

		switch (buttonType)
		{
		case ButtonType::StartGame:
			startButton.Draw(m_screen, xPos - 65, yPos - 30);
			break;
		case ButtonType::Reset:
			resetButton.Draw(m_screen, xPos - 65, yPos - 30);
			break;
		case ButtonType::Continue:
			continueButton.Draw(m_screen, xPos - 65, yPos - 30);
			break;
		case ButtonType::Quit:
			quitButton.Draw(m_screen, xPos - 65, yPos - 30);
			break;
		default:
			break;
		}
		
	}
};
