#pragma once
#include "GameObject.h"
class Unit : public GameObject
{
public:
    Unit() : GameObject() {}
    Unit(std::string anim_name,float msp, sf::FloatRect hb, Direction dir, float mhp, sf::Vector2f sp = { 0, 0 }) : 
        GameObject(anim_name, hb, dir, mhp, msp, sp) { }
  
    virtual ~Unit();
    virtual void Update(sf::Time dt);
};

