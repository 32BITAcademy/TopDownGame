#pragma once
#include "DrawableObject.h"
class GameObject : public DrawableObject
{
private:
    sf::FloatRect hit_box;
    sf::Vector2f speed;
    float hp, maxhp;

public:
    GameObject() : hit_box({ 0,0,1,1 }), speed({ 0,0 }), hp(0), maxhp(0) { }
    GameObject(sf::FloatRect hb, float mhp, sf::Vector2f sp = {0, 0}) : hit_box(hb), speed(sp), hp(mhp), maxhp(mhp) { }
    virtual ~GameObject();

    bool CheckCollision(GameObject* go);
};