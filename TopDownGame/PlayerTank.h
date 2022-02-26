#pragma once
#include "Unit.h"
class PlayerTank : public Unit
{
private: float curr_cd_of_bul=0, max_cd_of_bul=1, curr_cd_of_rotation=0, max_cd_of_rotation = 0.3f;
public:
	PlayerTank();
	~PlayerTank();

	void Update(sf::Time dt);
	void SendMsg(MSG& m);
};

//TODO: Debug hit_box, draw_box