#pragma once
#include "DrawableObject.h"
class GameObject : public DrawableObject
{
protected:
    sf::FloatRect hit_box;
    sf::Vector2f speed;
    float hp, maxhp;

public:
    GameObject() : DrawableObject(), hit_box({ 0,0,1,1 }), speed({ 0,0 }), hp(0), maxhp(0) { }
    GameObject(std::string anim_name, sf::FloatRect hb, float mhp, sf::Vector2f sp = {0, 0}) : DrawableObject(anim_name,hb), hit_box(hb), speed(sp), hp(mhp), maxhp(mhp) { }
    virtual ~GameObject();

    virtual void Update(sf::Time dt);
    bool CheckCollision(GameObject* go);
};