#pragma once
#include "Projectile.h"

class Rocket : public Projectile
{
private:
	sf::Vector2f area;

public:
	Rocket(sf::Vector2f Area, Unit* Owner, float damage, DamageType damageType, float msp, float timeleft, sf::Vector2f pos) :
		area(Area), Projectile(Owner, damage, damageType, msp, timeleft, "Rocket", {pos.x, pos.y, 30, 20}) {}
	~Rocket();

	void Update(sf::Time dt);
	void SendMsg(MSG& m);
};

