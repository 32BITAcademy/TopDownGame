#include "Bullet.h"
#include "GameManager.h"

Unit* Bullet::GetOwner()
{
	return owner;
}

Bullet::~Bullet()
{
}

Bullet::Bullet(Unit* Owner, float damage, DamageType damageType, float msp, float timeleft, sf::Vector2f pos) :
	Projectile(Owner, damage, damageType, msp, timeleft, "Bullet", {pos.x, pos.y, 10, 10})
{

}

void Bullet::Update(sf::Time dt)
{
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
