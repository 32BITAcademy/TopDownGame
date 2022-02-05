#pragma once
#include "Unit.h"
class PlayerTank : public Unit
{
public:
	PlayerTank();
	~PlayerTank();

	void Update(sf::Time dt);
	void SendMsg(MSG& m);
};

