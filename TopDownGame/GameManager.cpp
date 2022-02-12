#include "GameManager.h"
#include "Bullet.h"

GameManager* GameManager::instance = nullptr;

GameManager::~GameManager()
{
	msgs.clear();

	for (auto x : objects)
		delete x;
	objects.clear();

	GameManager::instance = nullptr;
}

GameManager* GameManager::GetInstance()
{
	if (GameManager::instance == nullptr)
	{
		GameManager::instance = new GameManager();
	}
	return GameManager::instance;
}

void GameManager::Update(sf::Time dt)
{
	for (auto x : objects)
		x->Update(dt);
}

void GameManager::ReadMsgs()
{
	MSG m;
	while (!msgs.empty())
	{
		m = msgs.front();
		msgs.pop_front();

		if (m.type == MSG_SHOOT)
		{
			AddObject(new Bullet());
			continue;
		}

		for (auto x : objects)
			x->SendMsg(m);
	}
}

void GameManager::SendMsg(MSG m)
{
	msgs.push_back(m);
}

void GameManager::AddObject(DrawableObject* obj)
{
	objects.push_back(obj);
}

void GameManager::Draw(sf::RenderWindow& window)
{
	for (auto x : objects)
		x->Draw(window);
}
