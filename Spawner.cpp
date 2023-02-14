#pragma once
#include "Spawner.h"
#include "game.h"
#include "windows.h"
#include <list>
#include <iostream>
#include <vector>
#include <SDL.h>
using namespace std;

namespace Tmpl8
{
	vector<Projectile>projj(3);
	vector<Projectile>usedprojj(0);
	vector <float> poss(3);

	list<Projectile> projList(4);
	//Projectile p;
	//vector<Projectile> pV(4);

	Sprite sp(new Surface("assets/ball.png"), 1);
	Spawner::Spawner() {}

	Spawner::Spawner(Surface* screen) :
		m_screen{ screen }
	{
	}

	void Spawner::Update(Surface* screen, float deltatime)
	{
		Move();
		Shoot(screen, deltatime);
		sp.Draw(screen, sPos.x, sPos.y);
	}

	void Spawner::Move()
	{
		//sPos.x = 20;

	}

	void Spawner::CreateProjectiles()
	{
		Projectile entity = Projectile();

		AddProjectilesToPool(entity);
	}


	void Spawner::AddProjectilesToPool(Projectile projectile)
	{
		projj.push_back(projectile);
		//poss.push_back(0);
		//projj.insert(projj.begin(), projectile);
		//poss.insert(poss.begin(), rand() % 700 + 1);
	}

	void Spawner::DeleteProjectiles()
	{
	}

	void Spawner::Shoot(Surface* screen, float deltatime)
	{
		bool canFire = false;

		float newTime = 0;
		float newPos;
		m_time += deltatime;

		if (projj.size() <= 2)
		{
			CreateProjectiles();
		}

		for (int i = 0; i < projj.size(); i++)
		{
			if (m_time > newTime + 3)
			{
				canFire = true;
			}
			else canFire = false;

			if (canFire == true)
			{
				poss[i] = rand() % 700 + 1;

				projj[i].Update(screen, i + 3, poss[i]);

				newTime += 5;
			}

			if (projj[i].inUse == false)
			{
				//usedprojj.insert(usedprojj.end(), std::make_move_iterator(projj.begin() + i),
				//std::make_move_iterator(projj.begin() + i + 1));
				
				projj.erase(projj.begin());
				//poss.erase(poss.begin());
			}
			//if (usedprojj.size() >= 1)
			//{
			//	usedprojj.erase(usedprojj.begin());
			//}
		}
		
	}

}