#pragma once
#include "GameObject.h"
class Unit : public GameObject
{
protected:
    float maxspeed;

public:
    Unit() : maxspeed(1.f), GameObject() {}
    Unit(std::string anim_name,float maxsp, sf::FloatRect hb,Direction dir, float mhp, sf::Vector2f sp = { 0, 0 }) : 
        maxspeed(maxsp), GameObject(anim_name, hb,dir, mhp, sp) { }
    virtual ~Unit();

    virtual void Update(sf::Time dt);
};

