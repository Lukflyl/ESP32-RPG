#include "Player.h"

Player::Player(int start_x, int start_y, BoundingBox bounding_box): 
    Entity{start_x, start_y, bounding_box, player_sprites} {}

void Player::draw(TFT_eSprite& g, const Camera& camera) const {
    auto& current_frame = animation_sprites[animation_type][animation_current_frame / animation_frame_length];

    for (int sy = 0; sy < current_frame.size(); sy++) {
        for (int sx = 0; sx < current_frame[sy].size(); sx++) {
            if (current_frame[sy][sx] == 0) {
                continue;
            }
            int draw_direction_x = dx >= 0 ? sx : current_frame[sy].size() - 1 - sx;
            int pixel_x = x + draw_direction_x * scale_factor - camera.get_offset_pixels_x();
            int pixel_y = y + sy * scale_factor - camera.get_offset_pixels_y();
            int color_key = current_frame[sy][sx];
            g.fillRect(pixel_x, pixel_y, scale_factor, scale_factor, player_sprites_color_map[color_key]);
        }
    }

    draw_bb(g, camera.get_offset_pixels_x(), camera.get_offset_pixels_y());
}

void Player::update() {
    animation_current_frame = (animation_current_frame + 1) % animation_loop_length;
    if (animation_type == ATTACK && animation_current_frame != 0) {
        // attack aniamtion did not run through yet
        return;
    }

    x = (x + dx) % WORLD_SIZE_PIXELS;
    if (x < 0) {
        x += WORLD_SIZE_PIXELS;
    }
    
    y = (y + dy) % WORLD_SIZE_PIXELS;
    if (y < 0) {
        y += WORLD_SIZE_PIXELS;
    }

    if (dx != 0 || dy != 0) {
        animation_type = WALK;
    } else {
        animation_type = IDLE;
    }
    
    bounding_box.shift(dx, dy);
    // Serial.println("Player world position: [" + String(x) + ", " + String(y) + "]");
}

void Player::attack() {
    if (animation_type == ATTACK) {
        return;
    }
    animation_type = ATTACK;
    animation_current_frame = 0;
}