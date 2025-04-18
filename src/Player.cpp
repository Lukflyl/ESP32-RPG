#include "Player.h"

Player::Player(World& world, int start_x, int start_y, BoundingBox bounding_box): 
    Entity{world, start_x, start_y, bounding_box, player_sprites} {}

void Player::draw(TFT_eSprite& g, Camera& camera) const {
    std::array<int, 7> colors {TFT_BLACK, TFT_BROWN, 0xFDB8, TFT_RED, 0xAEDC, TFT_LIGHTGREY, TFT_DARKGREY};

    auto& current_frame = animation_sprites[animation_type][animation_current_frame / animation_frame_length];

    for (int sy = 0; sy < current_frame.size(); sy++) {
        for (int sx = 0; sx < current_frame[sy].size(); sx++) {
            if (current_frame[sy][sx] == 0) {
                continue;
            }

            int pixel_x = x + sx * scale_factor - camera.get_offset_pixels_x();
            int pixel_y = y + sy * scale_factor - camera.get_offset_pixels_y();
            g.fillRect(pixel_x, pixel_y, scale_factor, scale_factor, colors[current_frame[sy][sx] - 1]);
        }
    }

    bounding_box.draw(g, camera.get_offset_pixels_x(), camera.get_offset_pixels_y());
}

void Player::update(int dx, int dy) {
    int world_size_pixels = WORLD_SIZE * UNIT_SIZE;
    world.constraint_movement(bounding_box, dx, dy);

    animation_current_frame = (animation_current_frame + 1) % animation_loop_length;

    x = (x + dx) % world_size_pixels;
    if (x < 0) {
        x += world_size_pixels;
    }
    
    y = (y + dy) % world_size_pixels;
    if (y < 0) {
        y += world_size_pixels;
    }

    if (dx != 0 || dy != 0) {
        animation_type = WALKING;
    } else {
        animation_type = IDLE;
    }
    
    bounding_box.update(x, y);
    // Serial.println("Player world position: [" + String(x) + ", " + String(y) + "]");
}