#pragma once
#include "Decoration.h"
class Explosion_big :
    public Decoration
{
private:
    Explosiontype expose_type;
public:
    Explosion_big(sf::FloatRect pos);
    ~Explosion_big();

    void Update(sf::Time dt);
};

