#pragma once
#include "Animation.h"
#include "MSG.h"
#include <string>

class DrawableObject
{
private:
	Animation *animation;
	sf::Vector2f scale;
	void UpdateAnim(sf::Time dt);

protected:
	sf::FloatRect draw_box;
	ObjectType type;

public:
	DrawableObject() : type(OBJ_UNDEFINED), animation(nullptr), scale({ 1.0f, 1.0f }), draw_box({ 0, 0, 1, 1 }) {}
	DrawableObject(std::string anim_name, sf::FloatRect db);
	virtual ~DrawableObject();
	int GetAnimationIteration() { return animation->GetIterat(); };
	void InitAnimation(std::string anim_name, sf::FloatRect db);
	sf::FloatRect GetDrawBox();
	void SetDrawBox(sf::FloatRect db);
	void Draw(sf::RenderWindow& win);
	virtual void Update(sf::Time dt) /*= 0*/;
	virtual void SendMsg(MSG& m) = 0;
};

