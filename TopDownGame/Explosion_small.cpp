#include "Explosion_small.h"
#include "GameManager.h"
Explosion_small::Explosion_small(sf::FloatRect pos): Decoration("Explosion1",pos)
{
}

Explosion_small::~Explosion_small()
{
}

void Explosion_small::Update(sf::Time dt)
{
	if (GetAnimationIteration() > 0)
	{
		MSG m;
		m.type = MSG_DEATH;
		m.sender = this;
		m.death.who_dies = this;
		m.death.killer = this;
		m.sender_type = OBJ_EXPLOSION;
		GameManager::GetInstance()->SendMsg(m);
	}
	else
		Decoration::Update(dt);
}
