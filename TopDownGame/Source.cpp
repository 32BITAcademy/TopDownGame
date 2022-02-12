#include<iostream>
#include<SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "DrawableObject.h"
#include "GameManager.h"
#include "PlayerTank.h"
#include "AI_Tank.h"
#include"Block.h"

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

    GameManager* gm = GameManager::GetInstance();
    gm->AddObject(new PlayerTank());
    gm->AddObject(new AI_Tank());
   //gm->AddObject(new Block("brick_wall", { 0,0,40,30 }));
    for (int i = 0; i < 1300; i += 40)
    {   
        gm->AddObject(new Block("brick_wall", { float(i),0,40,30 }));
        gm->AddObject(new Block("brick_wall", { float(i),570,40,30 }));
    }
    for (int i = 0; i < 800; i += 30)
    {
        gm->AddObject(new Block("brick_wall", { 0,float(i),40,30 }));
        gm->AddObject(new Block("brick_wall", { 1260,float(i),40,30 }));
    }
    /*gm->AddObject(new DrawableObject("Explosion1", { 200, 20, 128, 512 }));
    gm->AddObject(new DrawableObject("Explosion2", { 500, 20, 256, 256 }));
    gm->AddObject(new DrawableObject("Explosion3", { 800, 20, 128, 128 }));*/

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        Time dt = clock.restart();
        gm->Update(dt);
        gm->ReadMsgs();

        window.clear(Color(100,100,100));
        gm->Draw(window);
        window.display();
    }

    return 0;
}