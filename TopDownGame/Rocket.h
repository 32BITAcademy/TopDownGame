#pragma once
#include "Projectile.h"

class Rocket : public Projectile
{
private:
	sf::Vector2f area;

public:
	Rocket(sf::Vector2f Area, Unit* Owner, sf::Vector2f pos, Direction dir) :
		area(Area), Projectile(Owner, "Rocket", {pos.x, pos.y, 30, 20}, dir) {
		maxspeed = 350;
		time_left = 5000;
		sf::Vector2f sp;

		switch (direction) {
		case UP: sp = { 0, -maxspeed };
		case RIGHT: sp = { maxspeed, 0 };
		case DOWN: sp = { 0, maxspeed };
		case LEFT: sp = { -maxspeed, 0 };
		}

		speed = sp;
	}
	~Rocket();

	void Update(sf::Time dt);
	bool SendMsg(MSG& m);
};

