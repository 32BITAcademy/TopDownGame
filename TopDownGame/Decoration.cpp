#include "Decoration.h"

Decoration::Decoration(std::string anim_name, sf::FloatRect pos) : DrawableObject(anim_name, pos)
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
