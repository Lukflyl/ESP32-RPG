#include "Attack.h"

Attack::Attack(Entity* source, BoundingBox bounding_box, int damage): 
    source{source}, bounding_box{bounding_box}, damage{damage}
        {}

bool Attack::apply_damage(Entity* target) {
    if (target == nullptr || target == source) {
        return false;
    }
    if (target->get_bounding_box().intersects(bounding_box)) {
        return false;
    }
    target->receive_damage(damage);
    return true;
}

BoundingBox Attack::get_bounding_box() const {
    return bounding_box;
}