#include "Block.h"

Block::Block(std::string anim_name, sf::FloatRect pos) : GameObject(pos,99999.f)
{
	InitAnimation(anim_name, pos);

}

Block::~Block()
{
	;
}

void Block::SendMsg(MSG& m)
{
	if (m.sender == this) return;
	if (m.type == MSG_MOVEMENT)
	{
		if (m.movement.new_pos.intersects(hit_box))
		{
			MSG mes;
			mes.type = MSG_MOVEBACK;
			mes.sender = this;
			mes.moveback.move_here = m.movement.old_pos;
			m.sender->SendMsg(mes);
		}
	}
}

void Block::Update(sf::Time dt)
{
	GameObject::Update(dt);
}
