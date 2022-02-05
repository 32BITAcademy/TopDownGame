#pragma once
#include <list>
#include "DrawableObject.h"
#include "MSG.h"

class GameManager
{
private:
	std::list<DrawableObject*> objects;
	std::list<MSG> msgs;

	static GameManager* instance;
	GameManager() : objects(), msgs() {}
	GameManager(const GameManager& gm) { ; }
public:
	~GameManager();
	static GameManager* GetInstance();

	void Update(sf::Time dt);
	void ReadMsgs();
	void SendMsg(MSG m);
	void AddObject(DrawableObject* obj);
	void Draw(sf::RenderWindow& window);
};

