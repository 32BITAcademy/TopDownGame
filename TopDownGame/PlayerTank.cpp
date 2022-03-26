#include "PlayerTank.h"
#include "GameManager.h"
#include "Bullet.h"
#include <iostream>


using namespace sf;

PlayerTank::PlayerTank(Direction dir) : Unit("GreenTank1", { 200,200,60,80 },dir, 100.f)
{
	Rotate(dir);
	std::cout << hp << " hp" << std::endl;
	//std::cout << direction << std::endl;
	type = OBJ_PLAYER;
	maxspeed = 150;
}

PlayerTank::~PlayerTank()
{
}

void PlayerTank::Update(sf::Time dt)
{
	Vector2f s = { 0.0f, 0.0f };
	
	if (curr_cd_of_rotation <= 0)
	{
		if (Keyboard::isKeyPressed(Keyboard::Right)) { Rotate(true); curr_cd_of_rotation = max_cd_of_rotation; }
		if (Keyboard::isKeyPressed(Keyboard::Left)) { Rotate(false); curr_cd_of_rotation = max_cd_of_rotation; }
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		switch (direction)
		{
		case UP: speed = { 0, -maxspeed }; break;
		case DOWN: speed = { 0, maxspeed }; break;
		case RIGHT: speed = { maxspeed, 0 }; break;
		case LEFT: speed = { -maxspeed, 0 }; break;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		switch (direction)
		{
		case UP: speed = { 0, maxspeed }; break;
		case DOWN: speed = { 0, -maxspeed }; break;
		case RIGHT: speed = { -maxspeed, 0 }; break;
		case LEFT: speed = { maxspeed, 0 }; break;
		}
	}
	else
		speed = { 0,0 };
	
	if (Keyboard::isKeyPressed(Keyboard::Space) and curr_cd_of_bul<=0)
	{
		if (direction != NONE)
		{
			MSG m;
			m.type = MSG_SHOOT;
			m.sender = this;
			m.sender_type = type;
			m.shoot.dir = direction;
			m.shoot.who_to_create = OBJ_BULLET;
			m.shoot.pos = { hit_box.left + hit_box.width / 2,hit_box.top + hit_box.height / 2 };
			GameManager::GetInstance()->SendMsg(m);
			curr_cd_of_bul = max_cd_of_bul;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::Enter))
	{
		//std::cout << hit_box.left << " " << hit_box.top << std::endl;
		//std::cout << direction << std::endl;
		std::cout << hp << " hp" << std::endl;
	}
	curr_cd_of_bul -= dt.asSeconds();
	curr_cd_of_rotation -= dt.asSeconds();
	Unit::Update(dt);
}

bool PlayerTank::SendMsg(MSG& m)
{
	if (m.sender == this) return false;
	if (m.type == MSG_DEALDMG)
	{
		if (m.dealdmg.who_takes_dmg == this)
		{
			hp -= m.dealdmg.dmg;

			std::cout << hp << " hp" << std::endl;

			if (hp <= 0)
			{
				MSG m1;
				m1.type = MSG_DEATH;
				m1.sender = this;
				m1.death.killer = m.dealdmg.who_deals_dmg;
				m1.death.who_dies = this;
				GameManager::GetInstance()->SendMsg(m1);

				m1.type = MSG_EXPLOSION;
				m1.sender = this;
				m1.explode.pos.x = hit_box.left;
				m1.explode.pos.y = hit_box.top;
				m1.explode.type_of_explosion = EXP_BIG;
				GameManager::GetInstance()->SendMsg(m1);
			}
		}

	}
	if (m.type == MSG_MOVEMENT)
	{
		if (m.sender_type == OBJ_BULLET)
		{
			if (((Bullet*)m.sender)->GetOwner() == this)
				return false;
		}
		if (m.movement.new_pos.intersects(hit_box))
		{
			MSG mes;
			mes.type = MSG_COLLIDE;
			mes.sender = this;
			/*sf::FloatRect intersection;
			m.movement.new_pos.intersects(hit_box, intersection);
			if (abs((intersection.top + intersection.height / 2) - (hit_box.top + hit_box.height / 2)) >
				abs((intersection.left + intersection.width / 2) - (hit_box.left + hit_box.width / 2)))
			{
				if ((intersection.top + intersection.height / 2) - (hit_box.top + hit_box.height / 2) < 0)
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
			else if ((intersection.left + intersection.width / 2) - (hit_box.left + hit_box.width / 2) < 0)
			{
				mes.collide.move_here.left = hit_box.left - m.movement.new_pos.width;
				mes.collide.move_here.width = m.movement.new_pos.width;
				mes.collide.move_here.top = m.movement.new_pos.top;
				mes.collide.move_here.height = m.movement.new_pos.height;
			}
			else
			{
				mes.moveback.move_here.left = hit_box.left + hit_box.width;
				mes.moveback.move_here.width = m.movement.new_pos.width;
				mes.moveback.move_here.top = m.movement.new_pos.top;
				mes.moveback.move_here.height = m.movement.new_pos.height;
			}*/
			m.sender->SendMsg(mes);
			return true;
		}
	}
	return false;
}
