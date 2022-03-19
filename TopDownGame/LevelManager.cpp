#include "LevelManager.h"
#include <iostream>
#include"GameManager.h"
using namespace std;

LevelManager* LevelManager::instance = nullptr;

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
	if (cd_of_resp > 0) return;
	if (count_of_enemies <= 0) return;
	MSG m;
	m.type = MSG_CREATE_OBJECT;
	m.creation.who_to_create = OBJ_AI_TANK;
	int chosen_pos = rand() % RespPoints.size();
	m.creation.pos = RespPoints[chosen_pos];
	cd_of_resp = maxcd_of_resp;
	count_of_enemies -= 1;
	GameManager::GetInstance()->SendMsg(m);
}

void LevelManager::Update(sf::Time dt)
{
	cd_of_resp -= dt.asMilliseconds();
	if (cd_of_resp <= 0)
	{
		LevelManager::GetInstance()->CreateEnemy();
	}
}
