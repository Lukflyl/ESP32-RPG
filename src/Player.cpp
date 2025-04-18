#include "Player.h"

Player::Player(World& world, int start_x, int start_y, BoundingBox bounding_box): 
    Entity{world, start_x, start_y, bounding_box} {}

void Player::draw(TFT_eSprite& g, Camera& camera) {
    std::array<int, 7> colors {TFT_BLACK, TFT_BROWN, 0xFDB8, TFT_RED, 0xAEDC, TFT_LIGHTGREY, TFT_DARKGREY};

    auto& current_frame = sprites[animation_frames / animation_frame_length];

    for (int sy = 0; sy < current_frame.size(); sy++) {
        for (int sx = 0; sx < current_frame[sy].size(); sx++) {
            if (current_frame[sy][sx] == 0) {
                continue;
            }

            int pixel_x = x + sx * SCALE_FACTOR - camera.get_offset_pixels_x();
            int pixel_y = y + sy * SCALE_FACTOR - camera.get_offset_pixels_y();
            g.fillRect(pixel_x, pixel_y, SCALE_FACTOR, SCALE_FACTOR, colors[current_frame[sy][sx] - 1]);
        }
    }

    bounding_box.draw(g, camera.get_offset_pixels_x(), camera.get_offset_pixels_y());
}

void Player::update(int dx, int dy){
    int world_size_pixels = WORLD_SIZE * UNIT_SIZE;
    world.constraint_movement(bounding_box, dx, dy);

    x = (x + dx) % world_size_pixels;
    if (x < 0) {
        x += world_size_pixels;
    }
    
    y = (y + dy) % world_size_pixels;
    if (y < 0) {
        y += world_size_pixels;
    }
    
    bounding_box.update(x, y);
    // Serial.println("Player world position: [" + String(x) + ", " + String(y) + "]");
}

int Player::get_size() const {
    return SCALE_FACTOR * SPRITE_SIZE;
}