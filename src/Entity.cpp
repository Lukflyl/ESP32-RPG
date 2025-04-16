#include "Entity.h"

Entity::Entity(World& world, int start_x, int start_y, BoundingBox bounding_box):
    world{world}, x{start_x}, y{start_y}, bounding_box{bounding_box}  {}

int Entity::get_x() const {
    return x;
}

int Entity::get_y() const {
    return y;
}