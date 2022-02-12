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
    Projectile(Unit* Owner, float damage, DamageType damageType, float maxsp, std::string anim_name, sf::FloatRect pos) :
        Unit(anim_name, maxsp, pos, 1), owner(Owner), dmg(damage), dmgType(damageType) {}

    ~Projectile();

    virtual void Update(sf::Time dt);
};

