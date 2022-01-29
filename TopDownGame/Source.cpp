#include<iostream>
#include<SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "DrawableObject.h"

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1300, 600), "TopDownGame");
    Clock clock;
    Time time = clock.getElapsedTime();
    float timef;

    ResourceManager* rm = ResourceManager::GetInstance();

    rm->LoadAnimations("Resources\\topdownanimations.txt");

    DrawableObject e1("Explosion1", { 200, 20, 256, 256 });
    DrawableObject e2("Explosion2", { 500, 20, 256, 256 });
    DrawableObject e3("Explosion3", { 800, 20, 256, 256 });

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        Time dt = clock.restart();

        e1.Update(dt);
        e2.Update(dt);
        e3.Update(dt);

        window.clear(Color(100,100,100));

        e1.Draw(window);
        e2.Draw(window);
        e3.Draw(window);
        
        window.display();
    }

    return 0;
}