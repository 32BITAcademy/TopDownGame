#pragma once
#include "DrawableObject.h"
#include "MSG.h"
#include<list>
class LevelManager
{
private:
	int count_of_enemies;
	sf::Time cd_of_resp;
	sf::Time maxcd_of_resp;
	static LevelManager* instance;
	std::list<sf::Vector2f> RespPoints;
public:
	static LevelManager* GetInstance();
	void SetEnemyCount(int i) { count_of_enemies = i; }
	void AddSpawnPoint(sf::Vector2f point);
	void CreateEnemy();

	void Update(sf::Time dt);
};

