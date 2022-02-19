#include "AI_Tank.h"
#include "GameManager.h"
#include <iostream>

using namespace sf;
using namespace std;

AI_Tank::AI_Tank(): time_left_to_move(0), Unit("AI_Tank1", 50.f, { 400, 150 ,150,165 }, 20.f)
{
}

AI_Tank::~AI_Tank()
{
}

void AI_Tank::Update(sf::Time dt)
{
	if (time_left_to_move <= 0)
	{
		if (speed.x != 0 or speed.y != 0)
		{
			MSG m;
			m.type = MSG_SHOOT;
			m.sender = this;
			m.sender_type = type;
			m.shoot.dir = { speed.x * 3, speed.y * 3 };
			m.shoot.who_to_create = OBJ_BULLET;
			m.shoot.pos = { hit_box.left + hit_box.width / 2,hit_box.top + hit_box.height / 2 };
			GameManager::GetInstance()->SendMsg(m);
		}

		time_left_to_move = rand() % 2501 + 500;
		Direction chosen_dir = Direction(rand() % 5);
		switch (chosen_dir)
		{
		case RIGHT: speed = { maxspeed, 0.f }; break;
		case DOWN: speed = { 0.f, maxspeed }; break;
		case LEFT: speed = { -maxspeed, 0.f }; break;
		case UP: speed = { 0.f, -maxspeed }; break;
		case NONE: speed = { 0.f, 0.f }; break;
		}
	}
	
	time_left_to_move -= dt.asMilliseconds();
	Unit::Update(dt);
}

void AI_Tank::SendMsg(MSG& m)
{
	if (m.sender == this) return;
	if (m.type == MSG_MOVEBACK)
	{
		hit_box = m.moveback.move_here;
	}
	if (m.type == MSG_DEALDMG)
	{
		if (m.dealdmg.who_takes_dmg == this)
		{
			hp -= m.dealdmg.dmg;
			
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
	
}
