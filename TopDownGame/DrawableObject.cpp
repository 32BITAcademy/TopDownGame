#include "DrawableObject.h"
#include "ResourceManager.h"

void DrawableObject::UpdateAnim(sf::Time dt)
{
	animation->Update(dt.asSeconds());
}

DrawableObject::DrawableObject(std::string anim_name, sf::FloatRect db)
{
	animation = ResourceManager::GetInstance()->GetAnimationCopy(anim_name);
	draw_box = db;
}

DrawableObject::~DrawableObject()
{
	delete animation;
}

void DrawableObject::Init(std::string anim_name, sf::FloatRect db)
{
	animation = ResourceManager::GetInstance()->GetAnimationCopy(anim_name);
	draw_box = db;
}

void DrawableObject::Draw(sf::RenderWindow &win)
{
	animation->Draw(win, draw_box.left, draw_box.top);
}

void DrawableObject::Update(sf::Time dt)
{
	UpdateAnim(dt);
}
