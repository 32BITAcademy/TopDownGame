#pragma once
#include "Unit.h"
class Mine :
    public Unit
{
protected:
    float dmg;
public:

    Mine(sf::FloatRect pos) : dmg(30.f), Unit("Mine", pos, UP, -1) {}

    void Update(sf::Time dt);
    bool SendMsg(MSG& m);
};