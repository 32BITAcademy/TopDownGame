#include "Explosion.h"
#include "GameManager.h"
Explosion::Explosion(sf::FloatRect pos): Decoration("Explosion1",pos)
{
	expose_type = EXP_1;
}

Explosion::~Explosion()
{
}

void Explosion::Update(sf::Time dt)
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
