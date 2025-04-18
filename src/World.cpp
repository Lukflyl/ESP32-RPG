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

bool World::is_movement_valid(BoundingBox& bounding_box, int dx, int dy) {
    for (auto [x, y]: bounding_box.get_corners()) {
        if (!terrain_data[get_tile_coordinate(y + dy)][get_tile_coordinate(x + dx)].is_walkable()) {
            return false;
        }
    }
    return true;
}

// the corners of the bounding box have to be on walkable tiles before running this fn
void World::find_furthest_allowed_position(BoundingBox& bounding_box, int& dx, int& dy) {
    int low_x = 0;
    int last_valid_x = 0;
    int high_x = dx;
    while(abs(low_x) < abs(high_x)) {
        int mid = (low_x + high_x) / 2;
        if (!is_movement_valid(bounding_box, mid, 0)) {
            high_x = mid - (dx > 0 ? 1 : -1);
        } else {
            last_valid_x = mid;
            low_x = mid + (dx > 0 ? 1 : -1);
        }
    }

    int low_y = 0;
    int last_valid_y = 0;
    int high_y = dy;
    while(abs(low_y) < abs(high_y)) {
        int mid = (low_y + high_y) / 2;
        if (!is_movement_valid(bounding_box, last_valid_x, mid)) {
            high_y = mid - (dy > 0 ? 1 : -1);
        } else {
            last_valid_y = mid;
            low_y = mid + (dy > 0 ? 1 : -1);;
        }
    }

    dx = last_valid_x;
    dy = last_valid_y;
}

int World::get_tile_coordinate(int coordinate) {
    int tile = coordinate / UNIT_SIZE;
    if (tile < 0) {
        tile += WORLD_SIZE;
    }
    return tile;
}

void World::constraint_movement(BoundingBox& bounding_box, int& dx, int &dy) {
    if (is_movement_valid(bounding_box, dx, dy)) {
        return;
    }
    find_furthest_allowed_position(bounding_box, dx, dy);
}