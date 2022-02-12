#pragma once
#include "Projectile.h"
class Bullet :
    public Projectile
{
private:


public:
    Bullet() : Projectile(){}
    Bullet(Unit* Owner, float damage, DamageType damageType) : Projectile(Owner, damage, damageType) {}

    ~Bullet();

    void Update(sf::Time dt);
};

