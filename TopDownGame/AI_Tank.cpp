#include "AI_Tank.h"
#include <iostream>

using namespace sf;
using namespace std;

enum Direction { NONE, RIGHT, DOWN, LEFT, UP };

AI_Tank::AI_Tank(): time_left_to_move(0), Unit("AI_Tank1", 50.f, { 400, 150 ,150,165 }, 100.f)
{
}

AI_Tank::~AI_Tank()
{
}

void AI_Tank::Update(sf::Time dt)
{
	if (time_left_to_move <= 0)
	{
		time_left_to_move = rand() % 2501 + 500;
		Direction chosen_dir = Direction(rand() % 5);
		switch (chosen_dir)
		{
		case RIGHT: speed = { maxspeed, 0.f }; break;
		case DOWN: speed = { 0.f, maxspeed }; break;
		case LEFT: speed = { -maxspeed, 0.f }; break;
		case UP: speed = { 0.f, -maxspeed }; break;
		case NONE: speed = { 0.f, 0.f }; break;
		}
	}
	
	time_left_to_move -= dt.asMilliseconds();
	Unit::Update(dt);
}

void AI_Tank::SendMsg(MSG& m)
{
	if (m.sender == this) return;
	if (m.type == MSG_MOVEBACK)
	{
		hit_box = m.moveback.move_here;
	}
}
