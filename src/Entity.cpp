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

void Entity::draw_health_bar(TFT_eSprite& g, const Camera& camera) const {
    int width = get_size();
    int height = 8;
    int start_x = x - camera.get_offset_pixels_x();
    int start_y = y - camera.get_offset_pixels_y() - height - 2;
    int filled_width = static_cast<double>(health) / static_cast<double>(max_health) * width;
    g.fillRect(start_x, start_y, filled_width, height, TFT_RED);
    g.drawRect(start_x, start_y, width, height, TFT_BLACK);
}

void Entity::receive_damage(int damage) {
    health -= damage;
}

bool Entity::is_dead() const {
    return health < 0;
}
