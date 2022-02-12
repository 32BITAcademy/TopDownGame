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
    Bullet(Unit* Owner, float damage, DamageType damageType, float timeleft, BulletDirections dir) :
        time_left(timeleft), direction(dir), Projectile(Owner, damage, damageType) {}

    ~Bullet();

    void Update(sf::Time dt);
    void SendMsg(MSG& m);
};

