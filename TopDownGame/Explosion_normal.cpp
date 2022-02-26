#include "Explosion_normal.h"
#include"GameManager.h"
Explosion_normal::Explosion_normal(sf::FloatRect pos) : Decoration("Explosion2", pos)
{
}

Explosion_normal::~Explosion_normal()
{
}

void Explosion_normal::Update(sf::Time dt)
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
