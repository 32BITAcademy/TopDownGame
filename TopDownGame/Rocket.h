#pragma once
#include "Projectile.h"

class Rocket : public Projectile
{
private:
	sf::Vector2f area;

public:
	Rocket(sf::Vector2f Area, Unit* Owner, float msp, float timeleft, sf::Vector2f pos, Direction dir) :
		area(Area), Projectile(Owner, msp, timeleft, "Rocket", {pos.x, pos.y, 30, 20}, dir) {}
	~Rocket();

	void Update(sf::Time dt);
	void SendMsg(MSG& m);
};

