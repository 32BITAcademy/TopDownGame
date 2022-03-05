#include "Rocket.h"
#include "GameManager.h"

Rocket::~Rocket()
{
}

void Rocket::Update(sf::Time dt)
{
	Projectile::Update(dt);
}

void Rocket::SendMsg(MSG& m)
{
	if (m.sender == this) return;
	if (m.type == MSG_MOVEMENT ||
		m.type == MSG_MOVEBACK)
		if (CheckCollision((GameObject*)m.sender) && m.sender != owner)
		{
			MSG d;

			d.type = MSG_AREADMG;
			d.sender = this;
			d.sender_type = OBJ_ROCKET;
			d.areadmg.pos = { hit_box.left - area.x / 2 + hit_box.width / 2, hit_box.top - area.y / 2 + hit_box.height / 2,
				area.x, area.y };
			d.areadmg.dmg = dmg;

			GameManager::GetInstance()->SendMsg(d);

			d.type = MSG_DEATH;
			d.sender = this;
			d.sender_type = OBJ_ROCKET;
			d.death.killer = this;
			d.death.who_dies = this;
			
			GameManager::GetInstance()->SendMsg(d);
		}
}
