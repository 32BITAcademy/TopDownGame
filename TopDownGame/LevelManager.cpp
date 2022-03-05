#include "LevelManager.h"
#include <iostream>
#include"GameManager.h"
using namespace std;
LevelManager* LevelManager::GetInstance()
{
	if (LevelManager::instance == nullptr)
	{
		LevelManager::instance = new LevelManager();
	}
	return LevelManager::instance;
}

void LevelManager::AddSpawnPoint(sf::Vector2f point)
{
	RespPoints.push_back(point);
}

void LevelManager::CreateEnemy()
{
	if (cd_of_resp.asSeconds() > 0) return;
	MSG m;
	m.type = MSG_CREATE_OBJECT;
	m.creation.who_to_create = OBJ_AI_TANK;
	int chosen_pos = rand() % RespPoints.size();
	int i = 0;
	for (auto x : RespPoints)
	{
		if (i == chosen_pos)
		{
			m.creation.pos = x;
			break;
		}
		i++;
	}
	cd_of_resp = maxcd_of_resp;
	GameManager::GetInstance()->SendMsg(m);
}

void LevelManager::Update(sf::Time dt)
{
	cd_of_resp -= dt;
}
