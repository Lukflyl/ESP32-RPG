#include "World.h"

void World::init() {
    for (int y = 0; y < WORLD_SIZE; y++) {
        terrain_data.push_back(std::vector<Tile>(WORLD_SIZE, Tile(EMPTY, TFT_BLACK)));
    }
    player = std::make_shared<Player>(Player{170, 300, BoundingBox{170, 300, 9, 0, UNIT_SIZE - 1, 2 * UNIT_SIZE - 1}});
    camera.follow(player.get());
    entities.emplace(std::make_tuple(170 / 16, 300 / 16), player);
    generate();
    add_trees();
}


void World::add_trees() {
    for (int x = 0; x < WORLD_SIZE; x++) {
        for (int y = 0; y < WORLD_SIZE; y++) {
            if (terrain_data[y][x].get_type() != GRASS) {
                continue;
            }
            int value = std::rand() % 100;
            if (value == 0) {
                int tx = x * UNIT_SIZE;
                int ty = y * UNIT_SIZE;
                entities.emplace(std::make_tuple(x, y), std::make_shared<Tree>(Tree{tx, ty, {tx, ty, 9, 13, 11, UNIT_SIZE + 2}}));
            }
        }
    }
}

void World::generate() {    
    unsigned int seed = 73;
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

int World::count_neighbours(int x, int y, TileType to_count) const {
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

void World::update(int direction_x, int direction_y) {
    player->set_direction(direction_x, direction_y);

    int start_tile_x = camera.get_start_tile_x();
    int start_tile_y = camera.get_start_tile_y();
    int end_tile_x = camera.get_end_tile_x();
    int end_tile_y = camera.get_end_tile_y();
    
    for (int x = start_tile_x; x < end_tile_x; x++) {
        for (int y = start_tile_y; y < end_tile_y; y++) {
            auto tile_key = std::make_tuple(x, y);
            if (entities.count(tile_key) != 0) {
                // TODO: entity might have changed its tile
                constraint_movement(entities[tile_key]);
                entities[tile_key]->update();
            }
        }
    }
    camera.update();
}

void World::draw(TFT_eSprite& g) const {
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

    // Entities have to be drawn over the tiles...
    for (int x = start_tile_x; x < end_tile_x; x++) {
        for (int y = start_tile_y; y < end_tile_y; y++) {
            auto tile_key = std::make_tuple(x, y);
            if (entities.count(tile_key) != 0) {
                entities.at(tile_key)->draw(g, camera);
            }
        }
    }
}

bool World::is_movement_valid(std::shared_ptr<Entity>& e, int dx, int dy) const {
    for (auto [x, y]: e->get_bounding_box().get_corners()) {
        if (!terrain_data[get_tile_coordinate(y + dy)][get_tile_coordinate(x + dx)].is_walkable()) {
            return false;
        }
    }
    return true;
}

// the corners of the bounding box have to be on walkable tiles before running this fn
void World::find_furthest_allowed_position(std::shared_ptr<Entity>& e) const {
    int low_x = 0;
    int last_valid_x = 0;
    int high_x = e->get_dx();
    while(abs(low_x) != abs(high_x)) {
        int mid = (low_x + high_x) / 2;
        if (!is_movement_valid(e, mid, 0)) {
            high_x = mid - (e->get_dx() > 0 ? 1 : -1);
        } else {
            last_valid_x = mid;
            low_x = mid + (e->get_dx() > 0 ? 1 : -1);
        }
    }

    int low_y = 0;
    int last_valid_y = 0;
    int high_y = e->get_dy();
    while(abs(low_y) != abs(high_y)) {
        int mid = (low_y + high_y) / 2;
        if (!is_movement_valid(e, last_valid_x, mid)) {
            high_y = mid - (e->get_dy() > 0 ? 1 : -1);
        } else {
            last_valid_y = mid;
            low_y = mid + (e->get_dy() > 0 ? 1 : -1);;
        }
    }
    e->set_direction(last_valid_x, last_valid_y);
}

int World::get_tile_coordinate(int coordinate) const {
    int tile = coordinate / UNIT_SIZE;
    if (tile < 0) {
        tile += WORLD_SIZE;
    }
    return tile;
}

void World::constraint_movement(std::shared_ptr<Entity>& e) const {
    if (is_movement_valid(e, e->get_dx(), e->get_dy())) {
        return;
    }
    find_furthest_allowed_position(e);
}