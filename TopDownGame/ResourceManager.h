#pragma once

#include<map>
#include<string>
#include<list>
#include<SFML/Graphics.hpp>

class Animation;

class ResourceManager
{
private:
	std::map<std::string, sf::Texture*> TextureDic;
	std::map<std::string, Animation*> AnimationDic;

	static ResourceManager* instance;
	ResourceManager() { ; }
	ResourceManager(const ResourceManager& rm) { ; }

	void LoadNewTexture(std::string key, std::string path);
	sf::Texture* GetTexture (std::string key);

public:
	~ResourceManager();
	static ResourceManager* GetInstance();

	void LoadAnimations(std::string path_to_animation_file);
	Animation* GetAnimationCopy (std::string key);
};

