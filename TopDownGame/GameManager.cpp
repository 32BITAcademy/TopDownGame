#include "GameManager.h"
#include "Bullet.h"
#include "Rocket.h"
#include "Explosion_small.h"
#include"AI_Tank.h"
#include"Unit.h"
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

void GameManager::SetDebugMode(bool on)
{
	_debug_drawing_ = on;
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
				sf::Vector2f speed;
				switch (m.sender->GetCurrentDir())
				{
				case RIGHT: speed = { 10.f, 0.f }; break;
				case DOWN: speed = { 0.f, 10.f }; break;
				case LEFT: speed = { -10.f, 0.f }; break;
				case UP: speed = { 0.f, -10.f }; break;
				}
			switch (m.shoot.who_to_create)
			{
			case OBJ_BULLET:
				AddObject(new Bullet((Unit*)m.sender, 10, DT_STANDARD, 100, speed, 5000, m.shoot.pos));
				break;
			case OBJ_ROCKET:
				AddObject(new Rocket({100,100}, (Unit*)m.sender, 10, DT_STANDARD, 100,speed,5000, m.shoot.pos));
				break;
			}
			continue;
		}

		if (m.type == MSG_EXPLOSION)
		{
			AddObject(new Explosion_small({ m.explode.pos.x,m.explode.pos.y,20,20}));
			continue;
		}

		if (m.type == MSG_DEATH)
		{
			deathnote.push_back(m.death.who_dies);
			continue;
		}

		if (m.type==MSG_CREATE_OBJECT)
		{
			AddObject(new AI_Tank(m.creation.pos));
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

	if (_debug_drawing_)
	{
		for (auto x : objects)
		{
			x->DebugDrawSpriteBox(window);
			x->DebugDrawHitBox(window);
		}
	}
}
