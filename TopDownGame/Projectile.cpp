#include "Projectile.h"
#include "GameManager.h"

Projectile::~Projectile()
{
	;
}

void Projectile::Update(sf::Time dt)
{
	if (time_left > 0)
		time_left -= dt.asMilliseconds();
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

	GameObject::Update(dt);
}
