
#pragma once
#include "Ninja.h"
#include "Object.h"
#include "windows.h"
#include "MapGenerator.h"

namespace Tmpl8
{
	
	Sprite map1Overlay(new Surface("assets/map1Overlay.png"), 1);
	Sprite map2Overlay(new Surface("assets/map2Overlay.png"), 1);
	Sprite map3Overlay(new Surface("assets/map3Overlay.png"), 1);
	Sprite map4Overlay(new Surface("assets/map4Overlay.png"), 1);

	

	Sprite winScreen(new Surface("assets/YouWon.png"), 1);

	MapGenerator::MapGenerator() {}

	MapGenerator::MapGenerator(Surface* screen, Ninja* player, Spikes* spikes) :
		m_screen{ screen },
		ninja { player },
		spikes{ spikes }
	{
	}

	void MapGenerator::Init()
	{
		if (characterSpawned == false)
		{
			this->spikes = new Spikes(m_screen);

			switch (level)
			{
			case 0:
				spikes->speed = 0;
				ninja->playerPos = { 150, 0 };
				printf("hate nig");
				break;
			case 1:
				spikes->spikesPos = { 0, 1080 };
				ninja->playerPos = { 150, 840 };
				break;
			case 2:
				spikes->spikesPos = { 0, 1300 };
				ninja->playerPos = { 150, 840 };
				break;
			case 3:
				spikes->spikesPos = { 0, 1080 };
				ninja->playerPos = { 150, 840 };
				break;
			case 4:
				spikes->spikesPos = { 0, 1280 };
				ninja->playerPos = { 150, 840 };
				break;
			case 5:
				spikes->speed = 0;
				break;
			default:
				break;
			}

			
			ninja->jumpForce = 1.25f;
			ninja->shield = false;

			characterSpawned = true;

			
		}

		//call the pos of the spikes here in a switch case HAWWY

		this->key = new Key(m_screen, ninja);

		for (int i = 0; i < buffsAmmount; i++)
		{
			buffs.push_back(Buffs{ m_screen, ninja, spikes});
		}

		for (int i = 0; i < objAmmount; i++)
		{
			obj.push_back(Object{ m_screen, ninja });
		}

		for (int i = 0; i < bShurikenAmmount; i++)
		{
			bShurikens.push_back(BouncingShuriken{ m_screen, ninja });
		}
	}

	void MapGenerator::LoadLevel(float deltaTime)
	{
		spikes->Update(ninja);
		switch (level)
		{
		case 0:
			//tutorial level
			Init();
			key->Update(level, 1870, 500);
			
			//OBJECTS
			obj[2].Spawn(0, 600, 60, 1980, Type::RECTANGLE);

			//BUFFS
			break;
		case 1:
			//map1
			map1Overlay.Draw(m_screen, 0, 0);
			Init();
			key->Update(level, 50, 60);

			//OBJECTS
			obj[2].Spawn(0, 1000, 60, 1980, Type::RECTANGLE);
			obj[3].Spawn(400, 860, 80, 100, Type::RECTANGLE);
			obj[4].Spawn(650, 800, 140, 100, Type::RECTANGLE);
			obj[5].Spawn(1000, 840, 100, 800, Type::RECTANGLE);
			obj[6].Spawn(1700, 600, 140, 100, Type::RECTANGLE);
			obj[7].Spawn(1350, 300, 250, 100, Type::RECTANGLE);
			obj[8].Spawn(0, 420, 30, 1100, Type::RECTANGLE);
			obj[9].Spawn(970, 270, 120, 75, Type::RECTANGLE);
			obj[10].Spawn(650, 305, 85, 75, Type::RECTANGLE);
			obj[11].Spawn(0, 355, 20, 400, Type::RECTANGLE);
			obj[12].Spawn(0, 255, 20, 300, Type::RECTANGLE);
			obj[13].Spawn(0, 155, 20, 200, Type::RECTANGLE);

			//BUFFS
			buffs[4].Update(BuffType::Shield, 1500, 700, deltaTime);
			buffs[5].Update(BuffType::Speed, 1700, 430, deltaTime);
			buffs[6].Update(BuffType::TimeSlow, 790, 350, deltaTime);

			//Shurikens
			bShurikens[3].Update(SnSide::Vectical, 830, 695, 243, 6, deltaTime);
			bShurikens[4].Update(SnSide::Horizontal, 965, 505, 135, 2, deltaTime);
			bShurikens[5].Update(SnSide::Horizontal, 1505, 465, 52, 0.7f, deltaTime);
			bShurikens[6].Update(SnSide::Horizontal, 786, 260, 60, 0.7f, deltaTime);
			break;
		case 2:
			//map3
			Init();
			key->Update(level, 930, 330);
			map2Overlay.Draw(m_screen, 0, 0);

			//OBJECTS
			obj[2].Spawn(0, 1000, 60, 1980, Type::RECTANGLE);
			obj[3].Spawn(1200, 520, 420, -300, Type::RECTANGLE);
			obj[4].Spawn(170, 120, 30, 730, Type::RECTANGLE);
			obj[5].Spawn(400, 800, 30, 200, Type::RECTANGLE);
			obj[6].Spawn(100, 300, 30, 100, Type::RECTANGLE);
			obj[7].Spawn(500, 460, 200, -200, Type::RECTANGLE);
			obj[8].Spawn(330, 330, 30, 100, Type::RECTANGLE);
			obj[9].Spawn(530, 390, 30, 100, Type::RECTANGLE);
			obj[10].Spawn(630, 550, 30, 100, Type::RECTANGLE);
			obj[11].Spawn(0, 600, 30, 300, Type::RECTANGLE);
			obj[12].Spawn(930, 270, 30, 900, Type::RECTANGLE);
			obj[13].Spawn(1300, 50, 50, 30, Type::RECTANGLE);
			obj[14].Spawn(1270, 220, 20, 60, Type::RECTANGLE);
			obj[15].Spawn(920, 400, 20, 80, Type::RECTANGLE);
			obj[16].Spawn(1035, 470, 30, 880, Type::RECTANGLE);

			//BUFFS
			buffs[7].Update(BuffType::Speed, 550, 900, deltaTime);
			buffs[8].Update(BuffType::TimeSlow, 240, 530, deltaTime);
			buffs[9].Update(BuffType::TimeSlow, 1890, 30, deltaTime);
			buffs[10].Update(BuffType::Shield, 1290, 150, deltaTime);

			//Shurikens
			bShurikens[7].Update(SnSide::Horizontal, 250, 295, 48, 1, deltaTime);
			bShurikens[8].Update(SnSide::Vectical, 1155, 370, 67, 2.5, deltaTime);
			bShurikens[9].Update(SnSide::Vectical, 1355, 370, 67, 2.3, deltaTime);
			bShurikens[10].Update(SnSide::Vectical, 1555, 370, 67, 2.7, deltaTime);
			bShurikens[11].Update(SnSide::Vectical, 1755, 370, 67, 1.9, deltaTime);
			break;
		case 3:
			//map4
			Init();
			key->Update(level, 30, 60);
			map3Overlay.Draw(m_screen, 0, 0);

			//OBJECTS
			obj[2].Spawn(0, 1000, 60, 1980, Type::RECTANGLE);
			obj[3].Spawn(300, 890, 50, 100, Type::RECTANGLE);
			obj[4].Spawn(550, 830, 110, 70, Type::RECTANGLE);
			obj[5].Spawn(840, 769, 170, 30, Type::RECTANGLE);
			obj[6].Spawn(1090, 620, 70, 285, Type::TUNNEL);
			obj[7].Spawn(1500, 870, 70, 100, Type::RECTANGLE);
			obj[8].Spawn(1800, 620, 70, 130, Type::RECTANGLE);
			obj[9].Spawn(1380, 320, 70, 255, Type::TUNNEL);
			obj[10].Spawn(1780, 90, 0, 170, Type::RECTANGLE);
			obj[11].Spawn(1020, 220, 40, 140, Type::RECTANGLE);
			obj[12].Spawn(550, 130, 0, 300, Type::RECTANGLE);
			obj[13].Spawn(365, 350, 50, 120, Type::RECTANGLE);
			obj[14].Spawn(0, 130, 0, 100, Type::RECTANGLE);
			obj[15].Spawn(0, 180, 0, 100, Type::RECTANGLE);

			//BUFFS
			buffs[11].Update(BuffType::Health, 1100, 650, deltaTime);
			buffs[12].Update(BuffType::TimeSlow, 780, 100, deltaTime);
			buffs[13].Update(BuffType::Speed, 1890, 520, deltaTime);
			buffs[14].Update(BuffType::Shield, 1850, 50, deltaTime);

			//Shurikens
			bShurikens[12].Update(SnSide::Horizontal, 420, 500, 420, 5, deltaTime);
			bShurikens[13].Update(SnSide::Vectical, 900, 400, 500, 5, deltaTime);
			bShurikens[14].Update(SnSide::Vectical, 1250, 300, 250, 3, deltaTime);
			bShurikens[15].Update(SnSide::Horizontal, 1750, 500, 150, 1.5, deltaTime);
			break;
		case 4:
			//map5
			Init();
			key->Update(level, 15, 55);
			map4Overlay.Draw(m_screen, 0, 0);

			//OBJECTS
			obj[2].Spawn(0, 1000, 60, 1980, Type::RECTANGLE);
			obj[3].Spawn(0, 300, 20, 1700, Type::RECTANGLE);
			obj[4].Spawn(600, 470, 150, -130, Type::RECTANGLE);
			obj[5].Spawn(600, 900, 150, -130, Type::RECTANGLE);
			obj[6].Spawn(770, 370, 70, -50, Type::RECTANGLE);
			obj[7].Spawn(905, 735, 205, -185, Type::RECTANGLE);
			obj[8].Spawn(1200, 470, 150, -130, Type::RECTANGLE);
			obj[9].Spawn(1200, 900, 150, -130, Type::RECTANGLE);
			obj[10].Spawn(1850, 850, 90, 70, Type::RECTANGLE);
			obj[11].Spawn(820, 70, 40, 220, Type::TUNNEL);
			obj[12].Spawn(650, 170, 110, 120, Type::RECTANGLE);
			obj[13].Spawn(1300, 70, 150, 90, Type::RECTANGLE);
			obj[14].Spawn(1100, 195, 85, -65, Type::RECTANGLE);
			obj[15].Spawn(180, 245, 15, 165, Type::RECTANGLE);
			obj[16].Spawn(90, 185, 15, 165, Type::RECTANGLE);
			obj[17].Spawn(0, 125, 15, 135, Type::RECTANGLE);

			//BUFFS
			buffs[15].Update(BuffType::Speed, 50, 900, deltaTime);
			buffs[16].Update(BuffType::Speed, 50, 850, deltaTime);
			buffs[17].Update(BuffType::Speed, 50, 800, deltaTime);
			buffs[18].Update(BuffType::TimeSlow, 1890, 720, deltaTime);
			buffs[19].Update(BuffType::Shield, 1280, 240, deltaTime);
			
			//Shurikens
			bShurikens[16].Update(SnSide::Vectical, 1150, 635, 310, 5, deltaTime);
			bShurikens[17].Update(SnSide::Vectical, 1220, 635, 310, 4.9f, deltaTime);
			bShurikens[18].Update(SnSide::Vectical, 1290, 635, 310, 4.8f, deltaTime);
			bShurikens[19].Update(SnSide::Vectical, 1360, 635, 310, 4.7f, deltaTime);
			bShurikens[20].Update(SnSide::Vectical, 1430, 635, 310, 4.6f, deltaTime);
			bShurikens[21].Update(SnSide::Vectical, 1500, 635, 310, 4.5f, deltaTime);
			bShurikens[22].Update(SnSide::Vectical, 1570, 635, 310, 4.4f, deltaTime);
			bShurikens[23].Update(SnSide::Vectical, 1640, 635, 310, 4.3f, deltaTime);
			
			break;
		case 5:
			Init();
			winScreen.Draw(m_screen, 50, 20);

			//OBJECTS
			obj[2].Spawn(0, 1000, 60, 1980, Type::RECTANGLE);
			break;

		}

		if (key->collided == true)
		{
			level += 1;
		
			key->collided = false;
			characterSpawned = false;
		}
	}

};


