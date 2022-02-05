#include "DrawableObject.h"
#include "ResourceManager.h"

void DrawableObject::UpdateAnim(sf::Time dt)
{
	animation->Update(dt.asSeconds());
}

DrawableObject::DrawableObject(std::string anim_name, sf::FloatRect db)
{
	animation = ResourceManager::GetInstance()->GetAnimationCopy(anim_name);
	SetDrawBox(db);
}

DrawableObject::~DrawableObject()
{
	delete animation;
}

void DrawableObject::InitAnimation(std::string anim_name, sf::FloatRect db)
{
	animation = ResourceManager::GetInstance()->GetAnimationCopy(anim_name);
	draw_box = db;
}

sf::FloatRect DrawableObject::GetDrawBox()
{
	return draw_box;
}

void DrawableObject::SetDrawBox(sf::FloatRect db)
{
	draw_box = db;
	int w, h;
	animation->GetFrameSize(w, h);
	float scalex = float(db.width) / w;
	float scaley = float(db.height) / h;
	animation->SetScale(scalex, scaley);
}

void DrawableObject::Draw(sf::RenderWindow &win)
{
	animation->Draw(win, draw_box.left, draw_box.top);
}

void DrawableObject::Update(sf::Time dt)
{
	UpdateAnim(dt);
}

void DrawableObject::SendMsg(MSG& m)
{
	;
}
