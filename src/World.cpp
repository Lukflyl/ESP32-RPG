#include "World.h"

void World::init() {
    for (int y = 0; y < WORLD_SIZE; y++) {
        terrain_data.push_back(std::vector<Tile>(WORLD_SIZE, Tile(EMPTY, TFT_BLACK)));
    }
    player = std::make_shared<Player>(Player{170, 300, BoundingBox{170 + 9, 300 + 0, UNIT_SIZE - 1, 2 * UNIT_SIZE - 1}});
    camera.follow(player.get());
    entities[std::make_tuple(170 / 16, 300 / 16)].push_back(player);
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
                entities[std::make_tuple(x, y)].push_back(std::make_shared<Tree>(Tree{tx, ty, {tx + 9, ty + 13, 11, UNIT_SIZE + 2}}));
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

void World::update(int direction_x, int direction_y, bool is_attacking) {
    player->set_direction(direction_x, direction_y);
    if (is_attacking) {
        player->attack();
    }

    int start_tile_x = camera.get_start_tile_x();
    int start_tile_y = camera.get_start_tile_y();
    int end_tile_x = camera.get_end_tile_x();
    int end_tile_y = camera.get_end_tile_y();
    
    std::vector<std::shared_ptr<Entity>> entities_to_update;
        // FIX: -1 here aint really correct, it should be minus
    // ('size' of the largest entity) / UNIT_SIZE 
    for (int x = start_tile_x - 1; x < end_tile_x + 1; x++) {
        for (int y = start_tile_y - 1; y < end_tile_y + 1; y++) {
            auto tile_key = std::make_tuple(x, y);
            for (auto& entity: entities[tile_key]) {
                entities_to_update.push_back(entity);
            }
        }
    }

    for (auto &entity: entities_to_update) {
        constraint_movement(entity, entities_to_update);
        entity->update();
    }

    // keys have to be updated after update() is called on all entities
    // to prevent multiple updates in one frame
    for (int x = start_tile_x - 1; x < end_tile_x + 1; x++) {
        for (int y = start_tile_y - 1; y < end_tile_y + 1; y++) {
            auto old_key = std::make_tuple(x, y);
            for (auto& entity: entities[old_key]) {
                auto new_key = std::make_tuple(get_tile_coordinate(entity->get_x()), get_tile_coordinate(entity->get_y()));
                if (new_key == old_key) {
                    continue;
                }
                // assign entity to the new key
                entities[new_key].push_back(entity);
                int old_index = std::find(entities[old_key].begin(), entities[old_key].end(), entity) - entities[old_key].begin();
                int end_index = entities[old_key].size() - 1;
                // 'semi-swap' the entity to be removed from the old key to the end so it can be removed
                // without shifting the vector (no need to really swap the last value is to be forgotten anyway)
                entities[old_key][old_index] = entities[old_key][end_index];
                entities[old_key].pop_back();
            }
        }
    }
    remove_dead_entities();

    camera.update();
}

void World::remove_dead_entities() {
    // FIX: this approach to removing entities from vectors here and updating tile keys
    // is probably INCORRECT
    int start_tile_x = camera.get_start_tile_x();
    int start_tile_y = camera.get_start_tile_y();
    int end_tile_x = camera.get_end_tile_x();
    int end_tile_y = camera.get_end_tile_y();
    for (int x = start_tile_x; x < end_tile_x; x++) {
        for (int y = start_tile_y; y < end_tile_y; y++) {
            auto key = std::make_tuple(x, y);
            for (auto& entity: entities[key]) {
                if (!entity->is_dead()) {
                    continue;
                }
                int index = std::find(entities[key].begin(), entities[key].end(), entity) - entities[key].begin();
                entities[key][index] = entities[key][entities[key].size() - 1];
                entities[key].pop_back();
                Serial.println("removed dead body");
            }
        }
    }
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

    // Entities have to be drawn over the tiles
    std::vector<std::shared_ptr<Entity>> entities_to_draw;
    // FIX: -1 here aint really correct, it should be minus
    // ('size' of the largest entity) / UNIT_SIZE 
    for (int x = start_tile_x - 1; x < end_tile_x + 1; x++) {
        for (int y = start_tile_y - 1; y < end_tile_y + 1; y++) {
            auto tile_key = std::make_tuple(x, y);
            if (entities.count(tile_key) == 0) {
                continue;
            }
            for (auto &entity: entities.at(tile_key)) {
                entities_to_draw.push_back(entity);
            }
        }
    }
    std::sort(entities_to_draw.begin(), entities_to_draw.end(), [](std::shared_ptr<Entity>& a, std::shared_ptr<Entity>& b) {
        return a->get_y() < b->get_y();
    });
    for (auto &entity: entities_to_draw) {
        entity->draw(g, camera);
    }
}

bool World::is_movement_valid(std::shared_ptr<Entity>& e, std::vector<std::shared_ptr<Entity>>& active_entities, int dx, int dy) const {
    for (auto [x, y]: e->get_bounding_box().get_corners()) {
        if (!terrain_data[get_tile_coordinate(y + dy)][get_tile_coordinate(x + dx)].is_walkable()) {
            return false;
        }
    }

    auto bounding_box = e->get_bounding_box();
    bounding_box.shift(dx, dy);
    for (auto &entity: active_entities) {
        if (entity == e) {
            continue;
        }
        if (entity->get_bounding_box().intersects(bounding_box)) {
            // FIX: there is a bug where the player probably gets checked with himself
            // TODO: remove the receive damage
            return false;
        }
    }
    return true;
}

// the corners of the bounding box have to be on walkable tiles before running this fn
void World::find_furthest_allowed_position(std::shared_ptr<Entity>& e, std::vector<std::shared_ptr<Entity>>& active_entities) const {
    int low_x = 0;
    int last_valid_x = 0;
    int high_x = e->get_dx();
    while(abs(low_x) != abs(high_x)) {
        int mid = (low_x + high_x) / 2;
        if (!is_movement_valid(e, active_entities, mid, 0)) {
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
        if (!is_movement_valid(e, active_entities, last_valid_x, mid)) {
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

void World::constraint_movement(std::shared_ptr<Entity>& e, std::vector<std::shared_ptr<Entity>>& active_entities) const {
    if (is_movement_valid(e, active_entities, e->get_dx(), e->get_dy())) {
        return;
    }
    find_furthest_allowed_position(e, active_entities);
}