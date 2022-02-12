#pragma once
#include "Unit.h"

enum DamageType { standart, fire };

class Projectile :
    public Unit
{
protected:

    DamageType dmgType;

    float dmg;
    Unit* owner;

public:
       
    Projectile() :
        Unit(), owner(NULL), dmg(1), dmgType(standart) {}
    Projectile(Unit* Owner, float damage, DamageType damageType) :
        Unit(), owner(Owner), dmg(damage), dmgType(damageType) {}

    ~Projectile();

    virtual void Update(sf::Time dt);
};

