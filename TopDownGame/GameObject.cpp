#include "GameObject.h"
#include "GameManager.h"
#include <math.h>

GameObject::~GameObject()
{

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

        hit_box.left += speed.x * dt.asSeconds();
        hit_box.top += speed.y * dt.asSeconds();

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

        m.movement.new_pos = hit_box;

        GameManager::GetInstance()->SendMsg(m);

        sf::FloatRect r = GetDrawBox();
        r.left = hit_box.left;
        r.top = hit_box.top;
        SetDrawBox(r);
    }
}

bool GameObject::CheckCollision(GameObject* go)
{
    return hit_box.intersects(go->hit_box);
}
