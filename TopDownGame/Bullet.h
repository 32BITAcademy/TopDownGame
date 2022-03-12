#pragma once
#include "Projectile.h"

class Bullet :
    public Projectile
{
private:
public:
    Bullet() : Projectile() {}
    Bullet(Unit* Owner, float damage, DamageType damageType, sf::Vector2f speed, float timeleft, sf::Vector2f pos);

    Unit* GetOwner();

    ~Bullet();

    void Update(sf::Time dt);
    void SendMsg(MSG& m);
};

