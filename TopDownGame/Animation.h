#pragma once

#include <SFML/Graphics.hpp>

#include "ResourceManager.h"

class Animation
{
private:
	Animation();

public:
	sf::Sprite* sprite;
	int frame_count;
	int cur_frame;

	sf::IntRect* frames;
	float timeout;
	float cur_time;

	~Animation();

	void Update(float dt);
	void Draw(sf::RenderWindow &win, int x, int y);

	friend void ResourceManager::LoadAnimations(std::string path_to_animation_file);
	friend Animation* ResourceManager::GetAnimationCopy(std::string key);
};