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
	float dir_angle;

protected:
	sf::FloatRect draw_box;
	ObjectType type;
	void _set_dir_angle(float a);
	Direction direction = RIGHT;

public:
	DrawableObject() : type(OBJ_UNDEFINED), animation(nullptr), scale({ 1.0f, 1.0f }), draw_box({ 0, 0, 1, 1 }), dir_angle(0) {}
	DrawableObject(std::string anim_name, sf::FloatRect db);
	virtual ~DrawableObject();
	float GetDirAngle();
	int GetAnimationIteration() { return animation->GetIterat(); };
	ObjectType GetType();
	void InitAnimation(std::string anim_name, sf::FloatRect db);
	sf::FloatRect GetDrawBox();
	void SetDrawBox(sf::FloatRect db);
	void Draw(sf::RenderWindow& win);
	void DebugDrawSpriteBox(sf::RenderWindow& win);
	virtual void DebugDrawHitBox(sf::RenderWindow& win);
	virtual void Update(sf::Time dt) /*= 0*/;
	virtual void SendMsg(MSG& m) = 0;
};

