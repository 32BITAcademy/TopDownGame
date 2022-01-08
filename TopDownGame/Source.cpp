#include<iostream>
#include<SFML\Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(200, 200), "SFML works!");
    CircleShape shape(100.f, 6);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}