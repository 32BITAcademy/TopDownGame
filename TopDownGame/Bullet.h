#pragma once
#include "Projectile.h"

enum BulletDirections {RIGHT, DOWN, LEFT, UP };

class Bullet :
    public Projectile
{
private:
    float time_left;
    BulletDirections direction;

public:
    Bullet() : direction(DOWN), time_left(5000.f), Projectile() {}
    Bullet::Bullet(Unit* Owner, float damage, DamageType damageType, BulletDirections dir, sf::FloatRect pos);

    ~Bullet();

    void Update(sf::Time dt);
    void SendMsg(MSG& m);
};

