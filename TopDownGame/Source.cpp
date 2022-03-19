#include<iostream>
#include<SFML\Graphics.hpp>
#include "ResourceManager.h"
#include "DrawableObject.h"
#include "GameManager.h"
#include"LevelManager.h"
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
    
    LevelManager* lm = LevelManager::GetInstance();
    GameManager* gm = GameManager::GetInstance();
    lm->SetEnemyCount(7);

    for (int i=50;i<=100;i+=10)
    lm->AddSpawnPoint({ float(i),float(i) });


    gm->SetDebugMode(0);
    gm->AddObject(new Decoration("background",{1300/2,600/2,1300,600}));
    gm->AddObject(new PlayerTank(LEFT));
    gm->AddObject(new AI_Tank(DOWN));
   //gm->AddObject(new Block("brick_wall", { 0,0,40,30 }));
    for (int i = 0; i < 1300; i += 40)
    {   
        gm->AddObject(new Block("brick_wall", { float(i)+20,15,40,30 }));
        gm->AddObject(new Block("brick_wall", { float(i)+20,585,40,30 }));
    }
    for (int i = 0; i < 600; i += 30)
    {
        gm->AddObject(new Block("brick_wall", { 20,float(i)+15,40,30 }));
        gm->AddObject(new Block("brick_wall", { 1280,float(i)+15,40,30 }));
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
        gm->Draw(window);

        window.display();
    }

    return 0;
}