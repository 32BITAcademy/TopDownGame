#pragma once
#include<SFML/Graphics.hpp>

#include<vector>
class LevelManager
{
private:
	int count_of_enemies;
	int cd_of_resp=4000;
	int maxcd_of_resp=4000;
	std::vector<sf::Vector2f> RespPoints;
	static LevelManager* instance;
	LevelManager() :RespPoints(),count_of_enemies(0) { ; }
	LevelManager(const LevelManager& lm) { ; }
public:
	static LevelManager* GetInstance();
	void SetEnemyCount(int i) { count_of_enemies = i; }
	void AddSpawnPoint(sf::Vector2f point);
	void CreateEnemy();

	void Update(sf::Time dt);
};

