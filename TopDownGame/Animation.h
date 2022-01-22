#pragma once

#include <SFML/Graphics.hpp>

class Animation
{
public:
	sf::Sprite* sp;
	int frame_count;
	int cur_frame;

	sf::Rect<int>* frames;
	float timeout;
	float cur_time;

	Animation();
	Animation(std::string path);
	~Animation();

	void Update(float dt);
	void Draw(sf::RenderWindow win, int x, int y);
};