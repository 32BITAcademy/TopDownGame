#pragma once
#include "Unit.h"
class PlayerTank : public Unit
{
private: float curr_cd_of_bul, max_cd_of_bul=1000.f;
public:
	PlayerTank();
	~PlayerTank();

	void Update(sf::Time dt);
	void SendMsg(MSG& m);
};

