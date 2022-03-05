#pragma once
#include "Projectile.h"

class Rocket : public Projectile
{
private:
	sf::Vector2f area;

public:
	Rocket(sf::Vector2f Area, Unit* Owner, float damage, DamageType damageType, sf::Vector2f speed, sf::Vector2f pos) :
		area(Area), Projectile(Owner, damage, damageType, speed, "Rocket", {pos.x, pos.y, 30, 20}) {}
	~Rocket();

	void Update(sf::Time dt);
	void SendMsg(MSG& m);
};

