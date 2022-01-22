#pragma once

#include<map>
#include<string>
#include<list>
#include<SFML/Graphics.hpp>

class ResourceManager
{
private:
	std::map<std::string, sf::Texture*> TextureDic;

	static ResourceManager* instance;
	ResourceManager() { ; }
	ResourceManager(const ResourceManager& rm) { ; }

public:
	~ResourceManager();
	static ResourceManager* GetInstance();

	void LoadNewTexture(std::string key, std::string path);
	sf::Texture* GetTexture (std::string key);
};

