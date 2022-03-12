#pragma once
#include "Unit.h"

enum DamageType { DT_STANDARD, DT_FIRE, DT_AREA };

class Projectile :
    public GameObject
{
protected:

    DamageType dmgType;

    float dmg;
    Unit* owner;

    float time_left;

public:
       
    Projectile() :
        GameObject(), owner(NULL), dmg(1), dmgType(DT_STANDARD), time_left(5000) {}
    Projectile(Unit* Owner, float damage, DamageType damageType, sf::Vector2f speed, float timeleft, std::string anim_name, sf::FloatRect pos) :
        GameObject(anim_name, pos, 1, speed), owner(Owner), dmg(damage), dmgType(damageType), time_left(timeleft) {}

    ~Projectile();

    virtual void Update(sf::Time dt);
};

