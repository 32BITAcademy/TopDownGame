#include "AI_Tank.h"
#include <iostream>

using namespace sf;
using namespace std;

enum Directions {NONE, RIGHT, DOWN, LEFT, UP};

AI_Tank::AI_Tank(): Unit(50.f, { 0,0,150,165 }, 100.f)
{
	InitAnimation("AI_Tank1", { 0,0,150,165 });
}


AI_Tank::~AI_Tank()
{
}

void AI_Tank::Update(sf::Time dt)
{
	Vector2f s = { 0.0f, 0.0f };
	int chosen_dir;
	float maxtime, _time;
	srand(time(nullptr));
	chosen_dir = rand() % 20;
	maxtime = rand() % 2;
	for (_time = 0.f; _time <= maxtime; )
	{
		if (chosen_dir <= UP) s.y += -1.f;
		else if (chosen_dir <= DOWN) s.y += 1.f;
		else if (chosen_dir <= RIGHT) s.x += 1.f;
		else if (chosen_dir <= LEFT) s.x += -1.f;
		float speedlen = sqrt(s.x * s.x + s.y * s.y);
		if (speedlen != 0)
		{
			s.x *= maxspeed / speedlen;
			s.y *= maxspeed / speedlen;
		}
		speed = s;
		_time += dt.asSeconds();
	}
	Unit::Update(dt);
	
	
}

void AI_Tank::SendMsg(MSG& m)
{
	if (m.sender == this) return;
}
