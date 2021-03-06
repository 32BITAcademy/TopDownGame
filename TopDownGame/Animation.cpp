#include "Animation.h"
#include "ResourceManager.h"

Animation::Animation()
{
	sprite = nullptr;
	cur_time = 0;
	cur_frame = 0;
	timeout = 1;
	frame_count = 5;
}

Animation::~Animation()
{
	delete sprite;
	delete[] frames;
}

void Animation::Update(float dt)
{
	if (frame_count == 1)
		return;
	cur_time += dt;
	if (cur_time > timeout)
	{
		cur_frame = (cur_frame + 1) % frame_count;
		cur_time -= timeout;
		if (cur_frame == 0) iterations++;
	}
}

void Animation::Draw(sf::RenderWindow &win, int x, int y, int dir_angle)
{
	sprite->setOrigin({ frames[cur_frame].width / 2.f, frames[cur_frame].height / 2.f });
	sprite->setRotation(dir_angle);
	sprite->setTextureRect(frames[cur_frame]);
	sprite->setPosition(x, y);
	win.draw(*sprite);
}

void Animation::SetScale(float scalex, float scaley)
{
	sprite->setScale({ scalex, scaley });
}

void Animation::GetFrameSize(int& width, int& height)
{
	width = frames[0].width;
	height = frames[0].height;
}
