#pragma once
#include "Decoration.h"
class Explosion_small :
    public Decoration
{
private:
    Explosiontype expose_type;
public:
    Explosion_small(sf::FloatRect pos);
    ~Explosion_small();

    void Update(sf::Time dt);
};

