#pragma once
#include "Unit.h"
class RepairKit: public Unit
{
private:
	float heal;
public:
	RepairKit(sf::Vector2f pos);
	~RepairKit();
	
	void Update(sf::Time dt);
	bool SendMsg(MSG& m);
};

