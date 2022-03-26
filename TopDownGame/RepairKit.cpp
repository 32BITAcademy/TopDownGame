#include "RepairKit.h"
#include "GameManager.h"
RepairKit::RepairKit(sf::Vector2f pos) :Unit("RepairKit", { pos.x,pos.y,50,50 }, RIGHT,0) 
{
	type = OBJ_REPAIRKIT;
	heal = 10;
}
RepairKit::~RepairKit()
{
}
void RepairKit::Update(sf::Time dt)
{
	Unit::Update(dt);
}

bool RepairKit::SendMsg(MSG& m)
{
	if (!alive) return false;
	if (m.type == MSG_MOVEMENT)
	{
		if (CheckCollision((GameObject*)m.sender) and m.sender_type == OBJ_PLAYER)
		{
			std::cout << "pick up a repairkit" << std::endl;
			MSG m1;
			m1.type = MSG_HEAL;
			m1.heal.heal_amount = heal;
			m1.heal.who_heals = this;
			m1.heal.who_take_heal = m.sender;

			GameManager::GetInstance()->SendMsg(m1);
			m1.type = MSG_DEATH;
			m1.sender = this;
			m1.sender_type = OBJ_REPAIRKIT;
			m1.death.who_dies = this;
			m1.death.killer = this;
			alive = false;

			GameManager::GetInstance()->SendMsg(m1);

		}
		
	}
	return false;
}
