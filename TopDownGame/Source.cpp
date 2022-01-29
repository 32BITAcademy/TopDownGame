#include<iostream>
#include<SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "Animation.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1300, 600), "TopDownGame");
    CircleShape shape(200.f, 6);
    shape.setFillColor(Color::Blue);
    Clock clock;
    Time time = clock.getElapsedTime();
    float timef;

    ResourceManager* rm = ResourceManager::GetInstance();
    rm->LoadNewTexture("Player", "Resources\\images\\1.png");
    rm->LoadNewTexture("Explosion1", "Resources\\images\\explosion_1.png");
    rm->LoadNewTexture("Explosion2", "Resources\\images\\explosion_2.png");
    rm->LoadNewTexture("Explosion3", "Resources\\images\\explosion_3.png");

    Sprite sp(*rm->GetTexture("Player"));

    sp.setScale({ 1.f, 1.f });
    sp.setTextureRect({ 20, 48, 146, 204 });

    Animation e1("Explosion1");
    Animation e2("Explosion2");
    Animation e3("Explosion3");

    e1.frame_count = 64;
    e2.frame_count = 64;
    e3.frame_count = 64;

    e1.frames = new IntRect[64];
    e2.frames = new IntRect[64];
    e3.frames = new IntRect[64];

    e1.timeout = 0.05;
    e2.timeout = 0.01;
    e3.timeout = 0.01;

    e1.sp->setPosition(20, 200);
    e2.sp->setPosition(20, 500);
    e3.sp->setPosition(20, 800);

    for(int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            e1.frames[i * 8 + j] = { j * 256, i * 256, 256, 256 };
            e2.frames[i * 8 + j] = { j * 256, i * 256, 256, 256 };
            e3.frames[i * 8 + j] = { j * 256, i * 256, 256, 256 };
        }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        Time dt = clock.restart();
        time += dt;
        timef = time.asMicroseconds() / 1000000.0;
        shape.setPosition(50+50*cos(timef*2), 50 + 50 * sin(timef*2));

        e1.Update(dt.asSeconds());
        e2.Update(dt.asSeconds());
        e3.Update(dt.asSeconds());

        window.clear(Color(100,100,100));
        window.draw(shape);
        window.draw(sp);
        e1.Draw(window, 200, 20);
        e2.Draw(window, 500, 20);
        e3.Draw(window, 800, 20);
        window.display();
    }

    return 0;
}