#pragma once
#include "Projectile.h"

class Bullet :
    public Projectile
{
private:
public:
    Bullet() : Projectile() {}
    Bullet(Unit* Owner, sf::Vector2f pos, Direction dir);

    Unit* GetOwner();

    ~Bullet();

    void Update(sf::Time dt);
    void SendMsg(MSG& m);
};

