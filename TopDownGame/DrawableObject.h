#pragma once
#include "Animation.h"
#include "BasicStructs.h"
#include <string>

class DrawableObject
{
	Animation animation;
	sf::FloatRect position;
	sf::Vector2f scale;

public:
	DrawableObject(std::string anim_name);
	~DrawableObject();

	
};

