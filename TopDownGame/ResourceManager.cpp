#include "ResourceManager.h"
#include "Animation.h"

#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/error/error.h"
#include "rapidjson/error/en.h"

#include <fstream>
#include <iostream>

using namespace std;
using namespace sf;

ResourceManager* ResourceManager::instance = nullptr;

ResourceManager::~ResourceManager()
{
	for (auto t: TextureDic)
	{
		delete t.second;
	}
	TextureDic.clear();
	ResourceManager::instance = nullptr;
}

ResourceManager* ResourceManager::GetInstance()
{
	if (ResourceManager::instance == nullptr)
	{
		ResourceManager::instance = new ResourceManager();
	}
	return ResourceManager::instance;
}

void ResourceManager::LoadAnimations(std::string path_to_animation_file)
{
	ifstream anim_file;
	anim_file.open(path_to_animation_file);
	if (!anim_file.is_open())
	{
		std::cout << "Couldn't load file " << path_to_animation_file << " with animation data!" << std::endl;
		exit(1);
	}

	anim_file.seekg(0, std::ios::end);
	size_t size = anim_file.tellg();
	std::string file_content(size, ' ');
	anim_file.seekg(0);
	anim_file.read(&file_content[0], size);
	anim_file.close();

	rapidjson::Document doc;
	
	rapidjson::ParseResult ok = doc.Parse(file_content.c_str());
	if (!ok) {
		fprintf(stderr, "JSON parse error: %s (%u)",
			rapidjson::GetParseError_En(ok.Code()), ok.Offset());
		exit(EXIT_FAILURE);
	}

	for (auto itr = doc.MemberBegin(); itr != doc.MemberEnd(); ++itr)
	{
		rapidjson::Value& obj = itr->value.GetObj();
		std::string name = itr->name.GetString();

		Animation* a = new Animation();
		LoadNewTexture(name, obj["file"].GetString());
		a->timeout = obj["timeout"].GetDouble();
		a->frame_count = obj["framecount"].GetInt();
		a->frames = new sf::IntRect[a->frame_count];

		rapidjson::Value& arr_frames = obj["frames"].GetArray();
		for (int i = 0; i < a->frame_count; i++)
		{
			rapidjson::Value& arr_data = arr_frames[i].GetArray();
			a->frames[i] = {
				arr_data[0].GetInt(),
				arr_data[1].GetInt(),
				arr_data[2].GetInt(),
				arr_data[3].GetInt()
			};
		}
		
		AnimationDic[name] = a;
	}
}

Animation* ResourceManager::GetAnimationCopy(std::string key)
{
	Animation *a = new Animation(), *b = AnimationDic[key];
	a->frame_count = b->frame_count;
	a->timeout = b->timeout;
	a->sprite = new sf::Sprite(*TextureDic[key]);
	
	a->frames = new sf::IntRect[a->frame_count];
	for (int i = 0; i < a->frame_count; i++)
		a->frames[i] = b->frames[i];

	return a;
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
		return nullptr;
	return TextureDic[key];
}
