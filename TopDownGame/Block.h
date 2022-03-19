#pragma once
#include<iostream>
#include "GameObject.h"
#include"MSG.h"
class Block :
    public GameObject
{

public:
    Block(std::string anim_name,sf::FloatRect pos);
    ~Block();
    bool SendMsg(MSG& m);
    void Update(sf::Time dt);
};

