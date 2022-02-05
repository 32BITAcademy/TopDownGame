#include "GameObject.h"

GameObject::~GameObject()
{

}

bool GameObject::CheckCollision(GameObject* go)
{
    return hit_box.intersects(go->hit_box);
}
