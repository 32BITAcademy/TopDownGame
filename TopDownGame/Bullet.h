#pragma once
#include "Projectile.h"
class Bullet :
    public Projectile
{
private:
    float time_left;

public:
    Bullet() : time_left(5000.f), Projectile(){}
    Bullet(float time_left, Unit* Owner, float damage, DamageType damageType) : Projectile(Owner, damage, damageType) {}

    ~Bullet();

    void Update(sf::Time dt);
    void SendMsg(MSG& m);
};

