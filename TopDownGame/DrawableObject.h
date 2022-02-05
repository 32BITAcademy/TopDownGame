#pragma once
#include "Animation.h"
#include "MSG.h"
#include <string>

class DrawableObject
{
private:
	Animation *animation;
	sf::Vector2f scale;
	sf::FloatRect draw_box;

	void UpdateAnim(sf::Time dt);

public:
	DrawableObject() : animation(nullptr), scale({ 1.0f, 1.0f }), draw_box({ 0, 0, 1, 1 }) {}
	DrawableObject(std::string anim_name, sf::FloatRect db);
	virtual ~DrawableObject();

	void InitAnimation(std::string anim_name, sf::FloatRect db);
	void Draw(sf::RenderWindow& win);
	virtual void Update(sf::Time dt) /*= 0*/;
	virtual void SendMsg(MSG& m) /*= 0*/;
};

