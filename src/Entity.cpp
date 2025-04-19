#include "Entity.h"

Entity::Entity(World& world, int start_x, int start_y, BoundingBox bounding_box, AnimationSprites& animation_sprites):
    world{world}, x{start_x}, y{start_y}, bounding_box{bounding_box}, animation_sprites{animation_sprites} {}

int Entity::get_size() const {
    return scale_factor * SPRITE_SIZE;
}

int Entity::get_x() const {
    return x;
}

int Entity::get_y() const {
    return y;
}