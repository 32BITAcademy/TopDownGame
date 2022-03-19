#include "Projectile.h"
#include "GameManager.h"
#include "GameObject.h"

Projectile::Projectile(Unit* Owner, std::string anim_name, sf::FloatRect pos, Direction dir) :
	GameObject(anim_name, pos, dir,1.f), owner(Owner)
{
	sf::Vector2f sp;

	switch (direction) {
	case UP: sp = { 0, -maxspeed };
	case RIGHT: sp = { maxspeed, 0 };
	case DOWN: sp = { 0, maxspeed };
	case LEFT: sp = { -maxspeed, 0 };
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
