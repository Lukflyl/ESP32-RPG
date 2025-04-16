#include "Camera.h"

void Camera::follow(Entity& e) {
    int world_size_pixels = WORLD_SIZE * UNIT_SIZE;
    
    offset_pixels_x = (e.get_x() + e.get_size() / 2) - SCREEN_WIDTH_PIXELS / 2;
    
    offset_pixels_y = (e.get_y() + e.get_size() / 2) - SCREEN_HEIGHT_PIXELS / 2;
}

int Camera::get_offset_pixels_x() {
    return offset_pixels_x;
}

int Camera::get_offset_pixels_y() {
    return offset_pixels_y;
}
// TODO: solve
int Camera::get_start_tile_x() {
    return offset_pixels_x / UNIT_SIZE - 1;
}

int Camera::get_start_tile_y() {
    return offset_pixels_y / UNIT_SIZE - 1;
}

int Camera::get_end_tile_x() {
    return (offset_pixels_x + SCREEN_WIDTH_PIXELS) / UNIT_SIZE + 1;
}

int Camera::get_end_tile_y() {
    return (offset_pixels_y + SCREEN_HEIGHT_PIXELS) / UNIT_SIZE + 1;
}
