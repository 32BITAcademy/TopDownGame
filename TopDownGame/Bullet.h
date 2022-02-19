#pragma once
#include "Projectile.h"

class Bullet :
    public Projectile
{
private:
    float time_left;
    
public:
    Bullet() : time_left(5000.f), Projectile() {}
    Bullet(Unit* Owner, float damage, DamageType damageType, sf::Vector2f speed, sf::Vector2f pos);

    ~Bullet();

    void Update(sf::Time dt);
    void SendMsg(MSG& m);
};

