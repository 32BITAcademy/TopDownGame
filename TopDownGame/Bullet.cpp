#include "Bullet.h"
#include "GameManager.h"

Bullet::~Bullet()
{
}

Bullet::Bullet(Unit* Owner, float damage, DamageType damageType, sf::Vector2f speed, sf::Vector2f pos) :
	time_left(5000), Projectile(Owner, damage, damageType, speed, "Bullet", {pos.x, pos.y, 10, 10})
{
}

void Bullet::Update(sf::Time dt)
{
	if (time_left > 0)
	{
		time_left -= dt.asMilliseconds();
	}
	else
	{
		MSG m;
		m.type = MSG_DEATH;
		m.sender = this;
		m.sender_type = OBJ_BULLET;
		m.death.killer = this;
		m.death.who_dies = this;
		GameManager::GetInstance()->SendMsg(m);
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
			MSG d;

			d.type = MSG_DEALDMG;
			d.sender = this;
			d.dealdmg.dmg = dmg;
			d.dealdmg.dmg_type = dmgType;
			d.dealdmg.who_deals_dmg = (DrawableObject*)owner;
			d.dealdmg.who_takes_dmg = m.sender;

			GameManager::GetInstance()->SendMsg(d);

			d.type = MSG_DEATH;
			d.sender = this;
			d.death.killer = this;
			d.death.who_dies = this;

			GameManager::GetInstance()->SendMsg(d);
		}
	}
	if (m.type == MSG_MOVEBACK)
	{
		if (CheckCollision((GameObject*)m.sender) && m.sender != owner)
		{
			MSG d;

			d.type = MSG_DEALDMG;
			d.sender = this;
			d.dealdmg.dmg = dmg;
			d.dealdmg.dmg_type = dmgType;
			d.dealdmg.who_deals_dmg = (DrawableObject*)owner;
			d.dealdmg.who_takes_dmg = m.sender;

			GameManager::GetInstance()->SendMsg(d);

			d.type = MSG_DEATH;
			d.sender = this;
			d.death.killer = this;
			d.death.who_dies = this;

			GameManager::GetInstance()->SendMsg(d);
			
		}
	}
}
