#include "Tree.h"

Tree::Tree(int start_x, int start_y, BoundingBox bounding_box): 
    Entity{start_x, start_y, bounding_box, tree_sprites} {}

void Tree::draw(TFT_eSprite& g, const Camera& camera) const {
    auto& current_frame = animation_sprites[IDLE][0];

    for (int sy = 0; sy < current_frame.size(); sy++) {
        for (int sx = 0; sx < current_frame[sy].size(); sx++) {
            if (current_frame[sy][sx] == 0) {
                continue;
            }

            int pixel_x = x + sx * scale_factor - camera.get_offset_pixels_x();
            int pixel_y = y + sy * scale_factor - camera.get_offset_pixels_y();
            int color_key = current_frame[sy][sx];
            g.fillRect(pixel_x, pixel_y, scale_factor, scale_factor, tree_sprites_color_map[color_key]);
        }
    }
    draw_health_bar(g, camera);
    bounding_box.draw(g, camera.get_offset_pixels_x(), camera.get_offset_pixels_y());
}

void Tree::update() {}