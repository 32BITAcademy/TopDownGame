#include "GameObject.h"
#include "GameManager.h"
#include <math.h>
#include <iostream>

GameObject::~GameObject()
{

}

void GameObject::Rotate(Direction d)
{
    direction = d;

    switch (direction) {
    case DOWN: _set_dir_angle(0); break;
    case LEFT: _set_dir_angle(90); break;
    case UP: _set_dir_angle(180); break;
    case RIGHT: _set_dir_angle(270); break;
    }

    sf::FloatRect old_box = hit_box;
    sf::Vector2f c = { old_box.left + old_box.width / 2, old_box.top + old_box.height / 2 };
    hit_box.width = old_box.height;
    hit_box.height = old_box.width;
    hit_box.left = c.x - hit_box.width / 2;
    hit_box.top = c.y - hit_box.height / 2;

    MSG m;
    m.type = MSG_MOVEMENT;
    m.sender = this;
    m.movement.dir = direction;
    m.movement.old_pos = old_box;
    m.movement.new_pos = hit_box;

    sf::FloatRect r = GetDrawBox();
    r.left = hit_box.left + hit_box.width / 2;
    r.top = hit_box.top + hit_box.height / 2;
    SetDrawBox(r);

    GameManager::GetInstance()->SendMsg(m);
}

void GameObject::Rotate(bool cw)
{
    if (cw)
    {
        switch (direction) {
        case UP: direction = RIGHT; break;
        case RIGHT: direction = DOWN; break;
        case DOWN: direction = LEFT; break;
        case LEFT: direction = UP; break;
        }
    } else {
        switch (direction) {
        case UP: direction = LEFT; break;
        case RIGHT: direction = UP; break;
        case DOWN: direction = RIGHT; break;
        case LEFT: direction = DOWN; break;
        }
    }

    switch (direction) {
    case DOWN: _set_dir_angle(0); break;
    case LEFT: _set_dir_angle(90); break;
    case UP: _set_dir_angle(180); break;
    case RIGHT: _set_dir_angle(270); break;
    }

    std::cout << direction << std::endl;

    sf::FloatRect old_box = hit_box;
    sf::Vector2f c = { old_box.left + old_box.width / 2, old_box.top + old_box.height / 2 };
    hit_box.width = old_box.height;
    hit_box.height = old_box.width;
    hit_box.left = c.x - hit_box.width / 2;
    hit_box.top = c.y - hit_box.height / 2;

    sf::FloatRect r = GetDrawBox();
    r.left = hit_box.left + hit_box.width / 2;
    r.top = hit_box.top + hit_box.height / 2;
    SetDrawBox(r);

    MSG m;
    m.type = MSG_MOVEMENT;
    m.sender = this;
    m.movement.dir = direction;
    m.movement.old_pos = old_box;
    m.movement.new_pos = hit_box;
    
    GameManager::GetInstance()->SendMsg(m);
}

void GameObject::Update(sf::Time dt)
{
    DrawableObject::Update(dt);

    if (speed.x != 0 || speed.y != 0)
    {
        MSG m;
        m.type = MSG_MOVEMENT;
        m.sender = this;
        m.sender_type = type;
        m.movement.old_pos = hit_box;
        m.movement.new_pos = hit_box;

        m.movement.new_pos.left += speed.x * dt.asSeconds();
        m.movement.new_pos.top += speed.y * dt.asSeconds();

        if (abs(speed.x) > abs(speed.y))
        {
            if (speed.x > 0)
                m.movement.dir = RIGHT;
            else
                m.movement.dir = LEFT;
        }
        else if (abs(speed.x) < abs(speed.y))
        {
            if (speed.y > 0)
                m.movement.dir = DOWN;
            else
                m.movement.dir = UP;
        }
        else
            m.movement.dir = NONE;

        GameManager::GetInstance()->SendMsg(m);

       
    }

}

bool GameObject::CheckCollision(GameObject* go)
{
    return hit_box.intersects(go->hit_box);
}

void GameObject::FinishMovement(MSG m)
{
     sf::FloatRect r = GetDrawBox();
     hit_box = m.movement.new_pos;
     //direction = m.movement.dir;
     r.left = hit_box.left + hit_box.width / 2;
     r.top = hit_box.top + hit_box.height / 2;
     SetDrawBox(r);
}

void GameObject::DebugDrawHitBox(sf::RenderWindow& win)
{
    sf::RectangleShape shape({ hit_box.width, hit_box.height });
    shape.setPosition({ hit_box.left, hit_box.top});
    shape.setOutlineColor(sf::Color::Red);
    shape.setOutlineThickness(3);
    shape.setFillColor(sf::Color(0, 0, 0, 0));
    win.draw(shape);
}
