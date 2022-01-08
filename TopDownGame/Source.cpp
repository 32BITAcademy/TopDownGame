#include<iostream>
#include<SFML\Graphics.hpp>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(500, 500), "TopDownGame");
    CircleShape shape(200.f, 6);
    shape.setFillColor(Color::Blue);
    Clock clock;
    Time time = clock.getElapsedTime();
    float timef;


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        time += clock.restart();
        timef = time.asMicroseconds() / 1000000.0;
        shape.setPosition(50+50*cos(timef*2), 50 + 50 * sin(timef*2));

        window.clear(Color(100,100,100));
        window.draw(shape);
        window.display();
    }

    return 0;
}