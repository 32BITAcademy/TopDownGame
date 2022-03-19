#pragma once
#include "Unit.h"

class AI_Tank : public Unit
{
private:
	int time_left_to_move;
	int cd_of_shooting;
	int maxcd = 500;
public:
	AI_Tank(Direction dir);
	AI_Tank(sf::Vector2f pos,Direction dir);
	~AI_Tank();

	void Update(sf::Time dt);
	bool SendMsg(MSG& m);
};

