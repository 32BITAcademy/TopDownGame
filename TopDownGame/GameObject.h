#pragma once
#include "DrawableObject.h"
class GameObject : public DrawableObject
{
protected:
    sf::FloatRect hit_box;
    sf::Vector2f speed;
    float hp, maxhp;
    float maxspeed;
    
public:
    GameObject() : DrawableObject(), hit_box({ 0,0,1,1 }), speed({ 0,0 }), hp(0), maxhp(0), maxspeed(0) { }
    GameObject(std::string anim_name, sf::FloatRect hb, float mhp, float msp = 0, sf::Vector2f sp = {0, 0}) : DrawableObject(anim_name,hb), speed(sp), hp(mhp), maxhp(mhp), maxspeed(msp)
    {
        hit_box = hb;
        hit_box.left -= hb.width / 2;
        hit_box.top -= hb.height / 2;
    }
    virtual ~GameObject();

    void Rotate(bool cw);
    void Rotate(Direction d);
    virtual void Update(sf::Time dt);
    bool CheckCollision(GameObject* go);

    void DebugDrawHitBox(sf::RenderWindow& win);
};