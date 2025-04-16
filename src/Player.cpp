#include "Player.h"

Player::Player(World& world, int start_x, int start_y, BoundingBox bounding_box): 
    Entity{world, start_x, start_y, bounding_box} {}

void Player::draw(TFT_eSprite& g, Camera& camera) {
    std::array<int, 7> colors {TFT_BLACK, TFT_BROWN, 0xFDB8, TFT_RED, 0xAEDC, TFT_LIGHTGREY, TFT_DARKGREY};

    for (int sy = 0; sy < sprite.size(); sy++) {
        for (int sx = 0; sx < sprite[sy].size(); sx++) {
            if (sprite[sy][sx] == 0) {
                continue;
            }
            //TODO: adjust based on camera offset
            int pixel_x = x + sx * SCALE_FACTOR - camera.get_offset_pixels_x();
            int pixel_y = y + sy * SCALE_FACTOR - camera.get_offset_pixels_y();
            g.fillRect(pixel_x, pixel_y, SCALE_FACTOR, SCALE_FACTOR, colors[sprite[sy][sx] - 1]);
        }
    }

    for (auto [x, y]: bounding_box.get_corners()) {
        g.drawPixel(x - camera.get_offset_pixels_x(), y - camera.get_offset_pixels_y(), TFT_RED);
    }
}

void Player::update(int direction_x, int direction_y){
    int world_size_pixels = WORLD_SIZE * UNIT_SIZE;
    world.is_movement_allowed(direction_x, direction_y, bounding_box);

    x = (x + direction_x) % world_size_pixels;
    if (x < 0) {
        x += world_size_pixels;
    }
    
    y = (y + direction_y) % world_size_pixels;
    if (y < 0) {
        y += world_size_pixels;
    }
    
    bounding_box.update(x, y);
    Serial.println("Player world position: [" + String(x) + ", " + String(y) + "]");
}

int Player::get_size() const {
    return SCALE_FACTOR * SPRITE_SIZE;
}