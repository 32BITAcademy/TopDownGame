#pragma once
#include "DrawableObject.h"
#include<iostream>
class GameObject : public DrawableObject
{
protected:
    sf::FloatRect hit_box;
    sf::Vector2f speed;
    float hp, maxhp;
    float maxspeed;
    bool alive;

public:
    GameObject() : DrawableObject(), hit_box({ 0,0,1,1 }), speed({ 0,0 }), hp(0), maxhp(0), maxspeed(0), alive(true) { }
    GameObject(std::string anim_name, sf::FloatRect hb, Direction dir, float mhp, sf::Vector2f sp = {0, 0}) : DrawableObject(anim_name,hb, dir), speed(sp), hp(mhp), maxhp(mhp), maxspeed(0)
    {
        hit_box = hb;
        hit_box.left -= hb.width / 2;
        hit_box.top -= hb.height / 2;
       // std::cout << type << std::endl;
        
    }
    virtual ~GameObject();

    void Rotate(bool cw);
    void Rotate(Direction d);
    virtual void Update(sf::Time dt);
    bool CheckCollision(GameObject* go);

    void FinishMovement(MSG m);
    void DebugDrawHitBox(sf::RenderWindow& win);
};