#include "Bullet.h"

enum Directions { RIGHT, DOWN, LEFT, UP };

Bullet::~Bullet()
{
}

void Bullet::Update(sf::Time dt)
{

	if (time_left > 0)
	{
		Directions dir = DOWN;
		speed = { 1.f, 0 };
		time_left -= dt.asMilliseconds();
	}


	Projectile::Update(dt);
}

void Bullet::SendMsg(MSG& m)
{
	if (m.sender == this) return;
	if (m.type == MSG_MOVEMENT)
	{
		if (CheckCollision((GameObject*)m.sender))
		{
			m.dealdmg.dmg = 10.f;
			m.dealdmg.who_deals_dmg = (DrawableObject*)owner;
			m.dealdmg.who_takes_dmg = m.sender;
		}
	}
}
