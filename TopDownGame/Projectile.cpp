#include "Projectile.h"
#include "GameManager.h"
#include "GameObject.h"

Projectile::Projectile(Unit* Owner, float msp, float timeleft, std::string anim_name, sf::FloatRect pos, Direction dir) :
	GameObject(anim_name, pos, 1.f, msp), owner(Owner), time_left(timeleft)
{
	sf::Vector2f sp;

	switch (direction) {
	case UP: sp = { 0, -msp };
	case RIGHT: sp = { msp, 0 };
	case DOWN: sp = { 0, msp };
	case LEFT: sp = { -msp, 0 };
	}

	speed = sp;
}

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
