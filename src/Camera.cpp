#include "Camera.h"

void Camera::follow(Entity* e) {
    target = e;
}

void Camera::update() {
    if (target == nullptr) {
        return;
    }
    int world_size_pixels = WORLD_SIZE * UNIT_SIZE;
    
    offset_pixels_x = (target->get_x() + target->get_size() / 2) - SCREEN_WIDTH_PIXELS / 2;
    
    offset_pixels_y = (target->get_y() + target->get_size() / 2) - SCREEN_HEIGHT_PIXELS / 2;
}

int Camera::get_offset_pixels_x() const {
    return offset_pixels_x;
}

int Camera::get_offset_pixels_y() const {
    return offset_pixels_y;
}

int Camera::get_start_tile_x() const {
    return offset_pixels_x / UNIT_SIZE;
}

int Camera::get_start_tile_y() const {
    return offset_pixels_y / UNIT_SIZE;
}

int Camera::get_end_tile_x() const {
    return (offset_pixels_x + SCREEN_WIDTH_PIXELS) / UNIT_SIZE + 1;
}

int Camera::get_end_tile_y() const {
    return (offset_pixels_y + SCREEN_HEIGHT_PIXELS) / UNIT_SIZE + 1;
}
