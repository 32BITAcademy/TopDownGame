#include "Bullet.h"
#include "GameManager.h"
#include<iostream>
Unit* Bullet::GetOwner()
{
	return owner;
}

Bullet::~Bullet()
{
}

Bullet::Bullet(Unit* Owner, float damage, DamageType damageType, sf::Vector2f speed, sf::Vector2f pos,Direction dir) :
	time_left(5000), Projectile(Owner, damage, damageType, speed, "Bullet", {pos.x, pos.y, 10, 10},dir)
{
	switch (dir) {
	case DOWN: _set_dir_angle(0); break;
	case LEFT: _set_dir_angle(90); break;
	case UP: _set_dir_angle(180); break;
	case RIGHT: _set_dir_angle(270); break;
	}
	type = OBJ_BULLET;
	std::cout << 3<<std::endl;
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
			d.sender_type = OBJ_BULLET;
			d.dealdmg.dmg = dmg;
			d.dealdmg.dmg_type = dmgType;
			d.dealdmg.who_deals_dmg = (DrawableObject*)owner;
			d.dealdmg.who_takes_dmg = m.sender;

			GameManager::GetInstance()->SendMsg(d);

			d.type = MSG_DEATH;
			d.sender = this;
			d.sender_type = OBJ_BULLET;
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
			d.sender_type = OBJ_BULLET;
			d.dealdmg.dmg = dmg;
			d.dealdmg.dmg_type = dmgType;
			d.dealdmg.who_deals_dmg = (DrawableObject*)owner;
			d.dealdmg.who_takes_dmg = m.sender;

			GameManager::GetInstance()->SendMsg(d);

			d.type = MSG_DEATH;
			d.sender = this;
			d.sender_type = OBJ_BULLET;
			d.death.killer = this;
			d.death.who_dies = this;

			GameManager::GetInstance()->SendMsg(d);
			
			d.type = MSG_EXPLOSION;
			d.sender = this;
			d.sender_type = OBJ_BULLET;
			d.explode.pos.x = hit_box.left;
			d.explode.pos.y = hit_box.top;
			d.explode.type_of_explosion = EXP_SMALL;

			GameManager::GetInstance()->SendMsg(d);
		}
	}
}
