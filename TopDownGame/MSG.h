#pragma once
#include <SFML/Graphics.hpp>

class DrawableObject;

enum DamageType;

enum Explosiontype{EXP_SMALL,EXP_NORMAL,EXP_BIG};
enum MsgType { MSG_MOVEMENT, MSG_DEATH, MSG_SHOOT, MSG_COLLIDE, MSG_DEALDMG,MSG_EXPLOSION, MSG_AREADMG, MSG_CREATE_OBJECT, MSG_HEAL};
enum ObjectType { OBJ_UNDEFINED, OBJ_MANAGER, OBJ_GAMEOBJECT, OBJ_BULLET,OBJ_EXPLOSION, OBJ_AI_TANK,OBJ_ROCKET, OBJ_PLAYER, OBJ_WALL, OBJ_REPAIRKIT, OBJ_MINE};
enum Direction { NONE, RIGHT, DOWN, LEFT, UP };

struct MSG
{
	MSG() { ; }
	~MSG() { ; }
	MsgType type;
	DrawableObject* sender; // nullptr - game manager
	ObjectType sender_type; // nullptr - game manager
	union {
		struct {
			sf::FloatRect old_pos, new_pos;
			Direction dir;
		} movement;
		struct {
			sf::FloatRect old_pos, new_pos;
			Direction dir;
		} movefinish;
		struct {
			DrawableObject* who_dies, * killer;
		} death;
		struct {
			sf::Vector2f pos;
			Direction dir;
			ObjectType who_to_create;
		} shoot;
		struct {
			float dmg;
			DrawableObject* who_deals_dmg, * who_takes_dmg;
		} dealdmg;
		struct {
			sf::FloatRect move_here;
		} collide;
		struct {
			sf::Vector2f pos;
			Explosiontype type_of_explosion;
		}explode;
		struct {
			sf::FloatRect pos;
			float dmg;
		} areadmg;
		struct
		{
			sf::Vector2f pos;
			ObjectType who_to_create;
			Direction dir;
		}creation;
		struct
		{
			float heal_amount;
			DrawableObject* who_heals, * who_take_heal;
		}heal;
	};
};
