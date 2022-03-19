#include "DrawableObject.h"
#include "ResourceManager.h"

void DrawableObject::UpdateAnim(sf::Time dt)
{
	animation->Update(dt.asSeconds());
}

void DrawableObject::_set_dir_angle(float a)
{
	dir_angle = a;
}

void DrawableObject::DebugDrawSpriteBox(sf::RenderWindow& win)
{
	sf::RectangleShape shape({ draw_box.width, draw_box.height });
	shape.setPosition({ draw_box.left - draw_box.width/2, draw_box.top - draw_box.height/2 });
	shape.setOutlineColor(sf::Color::Blue);
	shape.setOutlineThickness(3);
	shape.setFillColor(sf::Color(0, 0, 0, 0));
	win.draw(shape);
}

void DrawableObject::DebugDrawHitBox(sf::RenderWindow& win)
{
	;
}

DrawableObject::DrawableObject(std::string anim_name, sf::FloatRect db,Direction dir)
{
	animation = ResourceManager::GetInstance()->GetAnimationCopy(anim_name);
	SetDrawBox(db);
	dir_angle = 0;
	direction = dir;
}

DrawableObject::~DrawableObject()
{
	delete animation;
}

float DrawableObject::GetDirAngle()
{
	return dir_angle;
}

ObjectType DrawableObject::GetType()
{
	return type;
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
	animation->Draw(win, draw_box.left, draw_box.top, dir_angle);
}

void DrawableObject::Update(sf::Time dt)
{
	UpdateAnim(dt);
}

bool DrawableObject::SendMsg(MSG& m)
{
	return false;
}
