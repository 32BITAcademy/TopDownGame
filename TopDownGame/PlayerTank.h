#pragma once
#include "Unit.h"
class PlayerTank : public Unit
{
private: float curr_cd_of_bul=0, max_cd_of_bul=1;
public:
	PlayerTank();
	~PlayerTank();

	void Update(sf::Time dt);
	void SendMsg(MSG& m);
};

