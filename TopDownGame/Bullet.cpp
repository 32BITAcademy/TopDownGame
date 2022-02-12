#include "Bullet.h"

Bullet::~Bullet()
{
	Projectile::~Projectile();
}

void Bullet::Update(sf::Time dt)
{
	Projectile::Update(dt);
}
