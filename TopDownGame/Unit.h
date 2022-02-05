#pragma once
#include "GameObject.h"
class Unit : public GameObject
{
protected:
    float maxspeed;

public:
    Unit() : maxspeed(1.f), GameObject() {}
    Unit(float maxsp, sf::FloatRect hb, float mhp, sf::Vector2f sp = { 0, 0 }) : 
        maxspeed(maxsp), GameObject(hb, mhp, sp) { }
    virtual ~Unit();

    virtual void Update(sf::Time dt);
};

