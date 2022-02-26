#include<iostream>
#include<SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "DrawableObject.h"
#include "GameManager.h"
#include "PlayerTank.h"
#include "AI_Tank.h"
#include"Block.h"
#include "Bullet.h"
#include "Decoration.h"
using namespace sf;

int main()
{
    srand(time(nullptr));
    RenderWindow window(VideoMode(1300, 600), "TopDownGame");
    Clock clock;
    Time time = clock.getElapsedTime();
    float timef;

    ResourceManager* rm = ResourceManager::GetInstance();
    rm->LoadAnimations("Resources\\topdownanimations.txt");

    Animation* a = rm->GetAnimationCopy("AI_Tank1");
    

    GameManager* gm = GameManager::GetInstance();
    gm->AddObject(new Decoration("background",{0,0,1300,600}));
    gm->AddObject(new PlayerTank());
    gm->AddObject(new AI_Tank());
   //gm->AddObject(new Block("brick_wall", { 0,0,40,30 }));
    for (int i = 0; i < 1300; i += 40)
    {   
        gm->AddObject(new Block("brick_wall", { float(i),0,40,30 }));
        gm->AddObject(new Block("brick_wall", { float(i),570,40,30 }));
    }
    for (int i = 0; i < 600; i += 30)
    {
        gm->AddObject(new Block("brick_wall", { 0,float(i),40,30 }));
        gm->AddObject(new Block("brick_wall", { 1260,float(i),40,30 }));
    }
    /*gm->AddObject(new DrawableObject("Explosion1", { 200, 20, 128, 512 }));
    gm->AddObject(new DrawableObject("Explosion2", { 500, 20, 256, 256 }));
    gm->AddObject(new DrawableObject("Explosion3", { 800, 20, 128, 128 }));*/

    //gm->AddObject(new Bullet(nullptr, 10, DT_STANDARD, { 10, 0 }, { 650, 300 }));

    int t = 0;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Keyboard::isKeyPressed(Keyboard::Space))
                gm->AddObject(new Bullet());
        }

        Time dt = clock.restart();
        gm->Update(dt);
        gm->ReadMsgs();

        window.clear(Color(100,100,100));
        //gm->Draw(window);

        t += dt.asMilliseconds();

        if (t < 1000)
            a->Draw(window, 0, 0, 0);
        else if ( t < 2000)
            a->Draw(window, 0, 0, 90);
        else if (t < 3000)
            a->Draw(window, 0, 0, 180);
        else if (t < 4000)
            a->Draw(window, 0, 0, 270);
        else
        {
            a->Draw(window, 0, 0, 270);
            t = 0;
        }

        window.display();
    }

    return 0;
}