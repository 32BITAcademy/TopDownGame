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

Bullet::Bullet(Unit* Owner,  sf::Vector2f pos, Direction dir):
	Projectile(Owner, "Bullet", {pos.x, pos.y, 10, 10}, dir)
{
	type = OBJ_BULLET;
	time_left = 5000;
	maxspeed = 500;
	sf::Vector2f sp;

	switch (direction) {
	case UP: sp = { 0, -maxspeed }; break;
	case RIGHT: sp = { maxspeed, 0 }; break;
	case DOWN: sp = { 0, maxspeed }; break;
	case LEFT: sp = { -maxspeed, 0 }; break;
	}

	switch (direction) {
	case UP: Rotate(UP); break;
	case RIGHT: Rotate(RIGHT); break;
	case DOWN: Rotate(DOWN); break;
	case LEFT: Rotate(LEFT); break;
	}

	speed = sp;
}

void Bullet::Update(sf::Time dt)
{
	Projectile::Update(dt);
}

bool Bullet::SendMsg(MSG& m)
{
	if (m.sender == this) return false;
	if (m.type == MSG_MOVEMENT)
	{
		if (CheckCollision((GameObject*)m.sender) && m.sender != owner)
		{
			MSG d;

			d.type = MSG_DEALDMG;
			d.sender = this;
			d.sender_type = OBJ_BULLET;
			d.dealdmg.dmg = 10;
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
	if (m.type == MSG_COLLIDE)
	{
		if (m.sender != owner)
		{
			MSG d;

			d.type = MSG_DEALDMG;
			d.sender = this;
			d.sender_type = OBJ_BULLET;
			d.dealdmg.dmg = 10;
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
	return false;
}
