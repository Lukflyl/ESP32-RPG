#include "Entity.h"

Entity::Entity(int start_x, int start_y, BoundingBox bounding_box, AnimationSprites& animation_sprites):
    x{start_x}, y{start_y}, bounding_box{bounding_box}, animation_sprites{animation_sprites} {}

int Entity::get_size() const {
    return scale_factor * SPRITE_SIZE;
}

int Entity::get_x() const {
    return x;
}

int Entity::get_y() const {
    return y;
}

int Entity::get_dx() const {
    return dx;
}

int Entity::get_dy() const {
    return dy;
}

void Entity::set_direction(int dx, int dy) {
    this->dx = dx;
    this->dy = dy;
}

BoundingBox Entity::get_bounding_box() const {
    return bounding_box;
}

// THIS CODE IS ONLY FOR DEBUGGING PURPOSES
void Entity::draw_bb(TFT_eSprite& g, int off_x, int off_y) const {
    auto corners = bounding_box.get_corners();
    g.drawLine(std::get<0>(corners[0]) - off_x, std::get<1>(corners[0]) - off_y, std::get<0>(corners[1]) - off_x, std::get<1>(corners[1]) - off_y, TFT_RED);
    g.drawLine(std::get<0>(corners[1]) - off_x, std::get<1>(corners[1]) - off_y, std::get<0>(corners[2]) - off_x, std::get<1>(corners[2]) - off_y, TFT_RED);
    g.drawLine(std::get<0>(corners[2]) - off_x, std::get<1>(corners[2]) - off_y, std::get<0>(corners[3]) - off_x, std::get<1>(corners[3]) - off_y, TFT_RED);
    g.drawLine(std::get<0>(corners[3]) - off_x, std::get<1>(corners[3]) - off_y, std::get<0>(corners[0]) - off_x, std::get<1>(corners[0]) - off_y, TFT_RED);
}

void Entity::receive_damage(int damage) {
    health -= damage;
}

bool Entity::is_dead() const {
    return health < 0;
}