#include "Bullet.h"

Bullet::~Bullet()
{
}

Bullet::Bullet() 
{
}

Bullet::Bullet(Unit* Owner, float damage, DamageType damageType, BulletDirections dir, sf::FloatRect pos) :
	direction(dir), Projectile(Owner, damage, damageType, 1000, "Bullet", pos)
{
}

void Bullet::Update(sf::Time dt)
{
	if (time_left > 0)
	{
		switch (direction) {
		case RIGHT: speed = { maxspeed, 0 }; break;
		case DOWN: speed = { 0, maxspeed }; break;
		case LEFT: speed = { -maxspeed, 0 }; break;
		case UP: speed = { 0, -maxspeed }; break;
		}
		time_left -= dt.asMilliseconds();
	}

	Projectile::Update(dt);
}

void Bullet::SendMsg(MSG& m)
{
	if (m.sender == this) return;
	if (m.type == MSG_MOVEMENT)
	{
		if (CheckCollision((GameObject*)m.sender) && m.sender != owner)
		{
			m.dealdmg.dmg = dmg;
			m.dealdmg.dmg_type = dmgType;
			m.dealdmg.who_deals_dmg = (DrawableObject*)owner;
			m.dealdmg.who_takes_dmg = m.sender;
		}
	}
}
