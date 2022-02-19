#include "GameManager.h"
#include "Bullet.h"
#include "Explosion.h"

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
	std::list<DrawableObject*> deathnote;

	while (!msgs.empty())
	{
		m = msgs.front();
		msgs.pop_front();

		if (m.type == MSG_SHOOT)
		{
			switch (m.shoot.who_to_create)
			{
			case OBJ_BULLET:
				AddObject(new Bullet((Unit*)m.sender, 10, DT_STANDARD, m.shoot.dir, m.shoot.pos));
				break;
			}
			continue;
		}

		if (m.type == MSG_EXPLOSION)
		{
			AddObject(new Explosion({ m.explode.pos.x,m.explode.pos.y,20,20}));
			continue;
		}

		if (m.type == MSG_DEATH)
		{
			deathnote.push_back(m.death.who_dies);
			continue;
		}

		for (auto x : objects)
			x->SendMsg(m);
	}

	deathnote.unique();
	while (!deathnote.empty())
	{
		objects.remove(deathnote.front());
		delete deathnote.front();
		deathnote.pop_front();
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
