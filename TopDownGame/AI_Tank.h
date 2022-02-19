#pragma once
#include "Unit.h"

class AI_Tank : public Unit
{
private:
	int time_left_to_move;

public:
	AI_Tank();
	~AI_Tank();

	void Update(sf::Time dt);
	void SendMsg(MSG& m);
};

