#pragma once
#include<iostream>
#include "DrawableObject.h"
class Decoration : public DrawableObject
{

public:
	Decoration(std::string anim_name, sf::FloatRect pos,Direction dir=RIGHT);
	void Update(sf::Time dt);
	void SendMsg(MSG& m);
};

