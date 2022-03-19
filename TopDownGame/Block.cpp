#include "Block.h"
#include<iostream>
Block::Block(std::string anim_name, sf::FloatRect pos) : GameObject(anim_name, pos,NONE,99999.f)
{
	std::cout<<OBJ_WALL<<std::endl;
}

Block::~Block()
{
	;
}

bool Block::SendMsg(MSG& m)
{
	if (m.sender == this) return;
	if (m.type == MSG_MOVEMENT)
	{
		if (m.movement.new_pos.intersects(hit_box))
		{
			MSG mes;
			mes.type = MSG_COLLIDE;
			mes.sender = this;
			sf::FloatRect intersection;
			m.movement.new_pos.intersects(hit_box, intersection);
			if (abs((intersection.top +intersection.height/ 2) - (hit_box.top+hit_box.height / 2)) > 
				abs((intersection.left+intersection.width / 2) - (hit_box.left+hit_box.width / 2)))
			{
				if ((intersection.top + intersection.height / 2) - (hit_box.top + hit_box.height / 2)<0)
				{
					mes.collide.move_here.left = m.movement.new_pos.left;
					mes.collide.move_here.width = m.movement.new_pos.width;
					mes.collide.move_here.top = hit_box.top - m.movement.new_pos.height;
					mes.collide.move_here.height = m.movement.new_pos.height;
				}
				else
				{
					mes.collide.move_here.left = m.movement.new_pos.left;
					mes.collide.move_here.width = m.movement.new_pos.width;
					mes.collide.move_here.top = hit_box.top + hit_box.height;
					mes.collide.move_here.height = m.movement.new_pos.height;
				}
			}
			else if ((intersection.left + intersection.width / 2) - (hit_box.left + hit_box.width / 2)<0)
			{
				mes.collide.move_here.left = hit_box.left - m.movement.new_pos.width;
				mes.collide.move_here.width = m.movement.new_pos.width;
				mes.collide.move_here.top = m.movement.new_pos.top;
				mes.collide.move_here.height = m.movement.new_pos.height;
			}
			else
			{
				mes.collide.move_here.left = hit_box.left + hit_box.width;
				mes.collide.move_here.width = m.movement.new_pos.width;
				mes.collide.move_here.top = m.movement.new_pos.top;
				mes.collide.move_here.height = m.movement.new_pos.height;
			}
			/*switch (m.movement.dir)
			{
			case UP:
				mes.moveback.move_here.left = m.movement.new_pos.left;
				mes.moveback.move_here.width = m.movement.new_pos.width;
				mes.moveback.move_here.top = hit_box.top + hit_box.height;
				mes.moveback.move_here.height = m.movement.new_pos.height;
				break;
			case DOWN:
				mes.moveback.move_here.left = m.movement.new_pos.left;
				mes.moveback.move_here.width = m.movement.new_pos.width;
				mes.moveback.move_here.top = hit_box.top - m.movement.new_pos.height;
				mes.moveback.move_here.height = m.movement.new_pos.height;
				break;
			case LEFT:
				mes.moveback.move_here.left = hit_box.left + hit_box.width;
				mes.moveback.move_here.width = m.movement.new_pos.width;
				mes.moveback.move_here.top = m.movement.new_pos.top;
				mes.moveback.move_here.height = m.movement.new_pos.height;
				break;
			case RIGHT:
				mes.moveback.move_here.left = hit_box.left-m.movement.new_pos.width;
				mes.moveback.move_here.width = m.movement.new_pos.width;
				mes.moveback.move_here.top = m.movement.new_pos.top;
				mes.moveback.move_here.height = m.movement.new_pos.height;
				break;
			case NONE:
				mes.moveback.move_here = m.movement.old_pos;
			}*/
				m.sender->SendMsg(mes);
		}
	}
	return false;
}

void Block::Update(sf::Time dt)
{
	GameObject::Update(dt);
}
