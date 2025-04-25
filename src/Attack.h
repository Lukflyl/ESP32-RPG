#ifndef ATTACK_H
#define ATTACK_H

#include <TFT_eSPI.h>
#include "Entity.h"
#include "BoundingBox.h"

class Entity;

class Attack {
private:
    Entity* source;
    BoundingBox bounding_box;
    int damage;
public:
    Attack(Entity* source, BoundingBox bounding_box, int damage);

    bool apply_damage(Entity* target);

    BoundingBox get_bounding_box() const;
};

#endif