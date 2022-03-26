#include "Mine.h"
#include "GameManager.h"

void Mine::Update(sf::Time dt)
{
	Unit::Update(dt);
}

bool Mine::SendMsg(MSG& m)
{
	if (!alive) return false;
	if (m.sender == this) return false;
	if (m.sender_type != OBJ_PLAYER) return false;
	if (m.type == MSG_MOVEMENT)
	{
		if (CheckCollision((GameObject*)m.sender))
		{
			MSG d;

			d.type = MSG_DEALDMG;
			d.sender = this;
			d.sender_type = OBJ_MINE;
			d.dealdmg.dmg = 30;
			d.dealdmg.who_deals_dmg = this;
			d.dealdmg.who_takes_dmg = m.sender;

			GameManager::GetInstance()->SendMsg(d);

			d.type = MSG_DEATH;
			d.sender = this;
			d.sender_type = OBJ_MINE;
			d.death.killer = this;
			d.death.who_dies = this;
			alive = false;

			GameManager::GetInstance()->SendMsg(d);

			d.type = MSG_EXPLOSION;
			d.sender = this;
			d.sender_type = OBJ_MINE;
			d.explode.pos.x = hit_box.left + hit_box.width / 2;
			d.explode.pos.y = hit_box.top + hit_box.height / 2;
			d.explode.type_of_explosion = EXP_BIG;

			GameManager::GetInstance()->SendMsg(d);
		}
	}
	return false;
}
