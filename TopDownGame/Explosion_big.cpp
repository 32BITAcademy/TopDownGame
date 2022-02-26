#include "Explosion_big.h"
#include "GameManager.h"
Explosion_big::Explosion_big(sf::FloatRect pos) : Decoration("Explosion3", pos)
{
}

Explosion_big::~Explosion_big()
{
}

void Explosion_big::Update(sf::Time dt)
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