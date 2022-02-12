#include "PlayerTank.h"
#include <iostream>

using namespace sf;

PlayerTank::PlayerTank() : Unit(200.f, { 0,0,150,200 }, 100.f)
{
	InitAnimation("GreenTank1", { 0,0,150,200 });
}

PlayerTank::~PlayerTank()
{
}

void PlayerTank::Update(sf::Time dt)
{
	Vector2f s = { 0.0f, 0.0f };
	if (Keyboard::isKeyPressed(Keyboard::Up)) s.y += -1.f;
	if (Keyboard::isKeyPressed(Keyboard::Down)) s.y += 1.f;
	if (Keyboard::isKeyPressed(Keyboard::Right)) s.x += 1.f;
	if (Keyboard::isKeyPressed(Keyboard::Left)) s.x += -1.f;

	float speedlen = sqrt(s.x * s.x + s.y * s.y);
	if (speedlen != 0)
	{
		s.x *= maxspeed / speedlen;
		s.y *= maxspeed / speedlen;
	}

	speed = s;

	Unit::Update(dt);
}

void PlayerTank::SendMsg(MSG& m)
{
	if (m.sender == this) return;
	/*if (m.type == MSG_MOVEMENT)
	{
		std::cout << m.movement.new_pos.left << ", " << m.movement.new_pos.top << "\n";
	}*/
}
