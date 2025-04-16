#include "world.h"

void World::init() {
    for (int y = 0; y < WORLD_SIZE; y++) {
        terrain_data.push_back(std::vector<int>(WORLD_SIZE, 0));
    }
    generate();
}

void World::generate() {
    // int LAVA = 0;
    int WATER = 0;
    // int DIRT = 2;
    int GRASS = 1;
    // int SAND = 4;
    // int STONE = 5;
    
    unsigned int seed = 68;
    std::srand(seed);
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int y = 0; y < WORLD_SIZE; y++) {
            terrain_data[y][x] = std::rand() % 2;
        }
    }

    for (int i = 0; i < 4; i++) {
        apply_rules();
    }
}

bool World::apply_rules() {
    bool changed = false;
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int y = 0; y < WORLD_SIZE; y++) {
            // if I am grass count water else count grass
            int to_count = terrain_data[y][x] == 1 ? 0 : 1;
            int neighbours = count_neighbours(x, y, to_count);
            if (neighbours > 4) {
                terrain_data[y][x] = to_count;
                changed = true;
            }
        }
    }
    return changed;
}

int World::count_neighbours(int x, int y, int to_count) {
    int count = 0;
    for (int lx = x - 1; lx <= x + 1; lx++) {
        for (int ly = y - 1; ly <= y + 1; ly++) {
            int tx = lx % WORLD_SIZE;
            if (tx < 0) {
                tx += WORLD_SIZE;
            }
            int ty = ly % WORLD_SIZE;
            if (ty < 0) {
                ty += WORLD_SIZE;
            }

            if (terrain_data[ty][tx] == to_count) {
                count++;
            }
        }
    }
    return count;
}

void World::draw(TFT_eSprite& g, Camera& camera) {
    std::array<int, 6> colors{/*TFT_RED, TFT_BLUE, TFT_BROWN, TFT_GREEN, TFT_YELLOW, TFT_LIGHTGREY*/ TFT_BLUE, TFT_GREEN};
    int start_tile_x = camera.get_start_tile_x();
    int start_tile_y = camera.get_start_tile_y();
    int end_tile_x = camera.get_end_tile_x();
    int end_tile_y = camera.get_end_tile_y();
    
    int tile_offset_pixels_x = camera.get_offset_pixels_x() % UNIT_SIZE;
    int tile_offset_pixels_y = camera.get_offset_pixels_y() % UNIT_SIZE;

    for (int x = start_tile_x; x < end_tile_x; x++) {
        for (int y = start_tile_y; y < end_tile_y; y++) {
            int index_x = x % WORLD_SIZE;
            if (index_x < 0) {
                index_x += WORLD_SIZE;
            }
            int index_y = y % WORLD_SIZE;
            if (index_y < 0) {
                index_y += WORLD_SIZE;
            }
            int pixels_x = (x - start_tile_x) * UNIT_SIZE - tile_offset_pixels_x;
            int pixels_y = (y - start_tile_y) * UNIT_SIZE - tile_offset_pixels_y;
            g.fillRect(pixels_x, pixels_y, UNIT_SIZE, UNIT_SIZE, colors[terrain_data[index_y][index_x]]);
        }
    }
}

void World::find_furthest_allowed_position(int x, int y, int& desired_mov_x, int& desired_mov_y) {
    Serial.println(String(desired_mov_x) + " " + String(desired_mov_y));
    int low_x = desired_mov_x < 0 ? desired_mov_x : 0;
    int high_x = desired_mov_x < 0 ? 0 : desired_mov_x;
    while(low_x != high_x) {
        int mid = (low_x + high_x) / 2;
        if (terrain_data[y / UNIT_SIZE][(x + mid) / UNIT_SIZE] == 0) {
            high_x = mid - (desired_mov_x > 0 ? 1 : -1);
        } else {
            low_x = mid + (desired_mov_x > 0 ? -1 : 1);
        }
    }

    int low_y = desired_mov_y < 0 ? desired_mov_y : 0;
    int high_y = desired_mov_y < 0 ? 0 : desired_mov_y;
    while(low_y != high_y) {
        int mid = (low_y + high_y) / 2;
        if (terrain_data[(y + mid) / UNIT_SIZE][x / UNIT_SIZE] == 0) {
            Serial.println("H");
            high_y = mid - (desired_mov_y > 0 ? 1 : -1);
        } else {
            Serial.println("L");
            low_y = mid + (desired_mov_y > 0 ? -1 : 1);
        }
        Serial.println(String(low_y) + " " + String(high_y));
    }

    desired_mov_x = low_x - 1;
    desired_mov_y = low_y - 1;
}

void World::is_movement_allowed(int& desired_mov_x, int &desired_mov_y, BoundingBox& bounding_box) {
    // TODO: finish cirularity of world, best to implement functions for converting coordinates to tile coordinates
    // why - UNIT_SIZE ???
    // desired_mov_x, desired_mov_y should not be set to zero directly but allow as much movement as possible
    for (auto [x, y]: bounding_box.get_corners()) {
        x -= UNIT_SIZE;
        y -= UNIT_SIZE;
        // Serial.println(y);
        // Serial.println(x);
        if (terrain_data[y / UNIT_SIZE][(x + desired_mov_x) / UNIT_SIZE] != 1) {
            find_furthest_allowed_position(x, y, desired_mov_x, desired_mov_y);
        }
        if (terrain_data[(y + desired_mov_y) / UNIT_SIZE][x / UNIT_SIZE] != 1) {
            find_furthest_allowed_position(x, y, desired_mov_x, desired_mov_y);
        }
    }
}