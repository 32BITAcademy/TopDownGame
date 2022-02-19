#include "PlayerTank.h"
#include "GameManager.h"
#include <iostream>


using namespace sf;

PlayerTank::PlayerTank() : Unit("GreenTank1", 200.f, { 100,100,150,200 }, 100.f)
{
}

PlayerTank::~PlayerTank()
{
}

void PlayerTank::Update(sf::Time dt)
{
	Vector2f s = { 0.0f, 0.0f };
	
	if (Keyboard::isKeyPressed(Keyboard::Up)) s.y += -1.f;
	if (Keyboard::isKeyPressed(Keyboard::Down)) s.y += 1.f;
	if (Keyboard::isKeyPressed(Keyboard::Right)) s.x += 1.f;
	if (Keyboard::isKeyPressed(Keyboard::Left)) s.x += -1.f;

	float speedlen = sqrt(s.x * s.x + s.y * s.y);
	if (speedlen != 0)
	{
		s.x *= maxspeed / speedlen;
		s.y *= maxspeed / speedlen;
	}

	speed = s;
	
	
	if (Keyboard::isKeyPressed(Keyboard::Space) and curr_cd_of_bul<=0)
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
		curr_cd_of_bul = max_cd_of_bul;
	}
	curr_cd_of_bul -= dt.asMilliseconds();
	Unit::Update(dt);
}

void PlayerTank::SendMsg(MSG& m)
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
			}
		}

	}
}
