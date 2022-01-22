#include "ResourceManager.h"

using namespace std;
using namespace sf;

ResourceManager* ResourceManager::instance = NULL;

ResourceManager::~ResourceManager()
{
	for (auto t: TextureDic)
	{
		delete t.second;
	}
	TextureDic.clear();
}

ResourceManager* ResourceManager::GetInstance()
{
	if (ResourceManager::instance == NULL)
	{
		ResourceManager::instance = new ResourceManager();
	}
	return instance;
}

void ResourceManager::LoadNewTexture(std::string key, std::string path)
{
	Texture* tex = new Texture();
	tex->loadFromFile(path);
	TextureDic[key] = tex;
}

sf::Texture* ResourceManager::GetTexture(std::string key)
{
	if (TextureDic.find(key) == TextureDic.end())
		return NULL;
	return TextureDic[key];
}
