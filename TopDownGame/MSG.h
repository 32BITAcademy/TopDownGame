#pragma once
#include <SFML/Graphics.hpp>

class DrawableObject;

enum MsgType { MSG_MOVEMENT, MSG_DEATH, MSG_SHOOT,MSG_MOVEBACK };
enum ObjectType { OBJ_UNDEFINED, OBJ_MANAGER, OBJ_GAMEOBJECT };

struct MSG
{
	MsgType type;
	DrawableObject* sender; // nullptr - game manager
	ObjectType sender_type; // nullptr - game manager
	union {
		struct {
			sf::FloatRect old_pos, new_pos;
		} movement;
		struct {
			DrawableObject* who_dies, * killer;
		} death;
		struct {
			sf::Vector2f pos;
			sf::Vector2f dir;
			ObjectType who_to_create;
		} shoot;
		struct
		{
			sf::FloatRect move_here;
		}moveback;
	};

	MSG() {}
};