#include "Decoration.h"

Decoration::Decoration(std::string anim_name, sf::FloatRect pos,Direction dir) : DrawableObject(anim_name, pos,dir)
{
}

void Decoration::Update(sf::Time dt)
{
	DrawableObject::Update(dt);
}

void Decoration::SendMsg(MSG& m)
{
	if (m.sender == this) return;
}
