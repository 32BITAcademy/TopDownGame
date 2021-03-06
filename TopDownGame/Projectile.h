#pragma once
#include "Unit.h"

class Projectile :
    public GameObject
{
protected:

    Unit* owner;

    float time_left;

public:
       
    Projectile() :
        GameObject(), owner(NULL), time_left(5000) {}
    Projectile(Unit* Owner, std::string anim_name, sf::FloatRect pos, Direction dir) ;

    ~Projectile();

    virtual void Update(sf::Time dt);
};

