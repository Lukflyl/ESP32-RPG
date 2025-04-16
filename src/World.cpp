#include "world.h"

void World::init() {
    for (int y = 0; y < WORLD_SIZE; y++) {
        terrain_data.push_back(std::vector<Tile>(WORLD_SIZE, Tile(EMPTY, TFT_BLACK)));
    }
    generate();
}

void World::generate() {    
    unsigned int seed = 68;
    std::srand(seed);
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int y = 0; y < WORLD_SIZE; y++) {
            int reminder = std::rand() % 2;
            terrain_data[y][x] = reminder == 0 ? Tile(GRASS, TFT_GREEN) : Tile (WATER, TFT_BLUE);
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
            TileType to_count = terrain_data[y][x].get_type() == GRASS ? WATER : GRASS;
            int neighbours = count_neighbours(x, y, to_count);
            if (neighbours > 4) {
                terrain_data[y][x] = Tile(to_count, to_count == GRASS ? TFT_GREEN : TFT_BLUE);
                changed = true;
            }
        }
    }
    return changed;
}

int World::count_neighbours(int x, int y, TileType to_count) {
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

            if (terrain_data[ty][tx].get_type() == to_count) {
                count++;
            }
        }
    }
    return count;
}

void World::draw(TFT_eSprite& g, Camera& camera) {
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
            g.fillRect(pixels_x, pixels_y, UNIT_SIZE, UNIT_SIZE, terrain_data[index_y][index_x].get_color());
        }
    }
}

void World::find_furthest_allowed_position(int x, int y, int& desired_mov_x, int& desired_mov_y) {
    // TODO: deserver refactor to separate bin search fn
    // does not work for movement in negative direction
    Serial.println(String(desired_mov_x) + " " + String(desired_mov_y));
    int low_x = 0;
    int high_x = desired_mov_x;
    while(low_x <= high_x) {
        int mid = (low_x + high_x) / 2;
        if (!terrain_data[get_tile_coordinate(y)][get_tile_coordinate(x + mid)].is_walkable()) {
            high_x = mid - 1;
        } else {
            low_x = mid + 1;
        }
        Serial.println(String(low_x) + " " + String(high_x));
    }

    int low_y = 0;
    int high_y = desired_mov_y;
    while(low_y <= high_y) {
        int mid = (low_y + high_y) / 2;
        if (!terrain_data[get_tile_coordinate(y + mid)][get_tile_coordinate(x)].is_walkable()) {
            Serial.println("H");
            high_y = mid - 1;
        } else {
            Serial.println("L");
            low_y = mid + 1;
        }
        Serial.println(String(low_y) + " " + String(high_y));
    }

    desired_mov_x = low_x - 1;
    desired_mov_y = low_y - 1;
}

int World::get_tile_coordinate(int coordinate) {
    int tile = coordinate / UNIT_SIZE;
    if (tile < 0) {
        tile += WORLD_SIZE;
    }
    return tile;
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
        if (!terrain_data[get_tile_coordinate(y)][get_tile_coordinate(x + desired_mov_x)].is_walkable()) {
            find_furthest_allowed_position(x, y, desired_mov_x, desired_mov_y);
        }
        if (!terrain_data[get_tile_coordinate(y + desired_mov_y)][get_tile_coordinate(x)].is_walkable()) {
            find_furthest_allowed_position(x, y, desired_mov_x, desired_mov_y);
        }
    }
}