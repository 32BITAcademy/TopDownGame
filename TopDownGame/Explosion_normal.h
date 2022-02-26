#pragma once
#include"Decoration.h"
class Explosion_normal:
	public Decoration
{
private:
    Explosiontype expose_type;
public:
    Explosion_normal(sf::FloatRect pos);
    ~Explosion_normal();

    void Update(sf::Time dt);
};


