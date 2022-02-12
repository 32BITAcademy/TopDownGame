#pragma once
#include "GameObject.h"

class Unit;

enum DamageType { standart, fire };

class Projectile :
    public GameObject
{
private:
    float dmg;

    DamageType dmgType;

protected:
    Unit* owner;
public:
       
    Projectile() :
        GameObject(), owner(NULL), dmg(1), dmgType(standart) {}
    Projectile(Unit* Owner, float damage, DamageType damageType) :
        GameObject(), owner(Owner), dmg(damage), dmgType(damageType) {}

    ~Projectile();

    virtual void Update(sf::Time dt);
};

