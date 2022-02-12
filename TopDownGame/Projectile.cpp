#include "Projectile.h"

Projectile::~Projectile()
{
	;
}

void Projectile::Update(sf::Time dt)
{
	Unit::Update(dt);
}
