#include "Projectile.h"

Projectile::~Projectile()
{
	delete owner;
	GameObject::~GameObject();
}

void Projectile::Update(sf::Time dt)
{
	GameObject::Update(dt);
}
