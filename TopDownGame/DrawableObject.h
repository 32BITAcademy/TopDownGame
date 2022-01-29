#pragma once
#include "Animation.h"
#include <string>

class DrawableObject
{
	Animation *animation;
	sf::Vector2f scale;
	sf::FloatRect draw_box;

private:
	void UpdateAnim(sf::Time dt);

public:
	DrawableObject() { ; }
	DrawableObject(std::string anim_name, sf::FloatRect db);
	~DrawableObject();

	void Init(std::string anim_name, sf::FloatRect db);
	void Draw(sf::RenderWindow& win);
	/*virtual*/ void Update(sf::Time dt) /*= 0*/;
};

