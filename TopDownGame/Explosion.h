#pragma once
#include "Decoration.h"
class Explosion :
    public Decoration
{
private:
    Explosiontype expose_type;
public:
    Explosion(sf::FloatRect pos);
    ~Explosion();

    void Update(sf::Time dt);
};

