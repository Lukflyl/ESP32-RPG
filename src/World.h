#ifndef WORLD_H
#define WORLD_H

#include <TFT_eSPI.h>

#include <vector>
#include <cstdlib>
#include <tuple>
#include <map>
#include <ctime>
#include <array>
#include <memory>

#include "Camera.h"
#include "Entity.h"
#include "Player.h"
#include "Tree.h"
#include "Tile.h"
#include "constants.h"

// TODO: constructor should take seed and spawn probabilities
class World {
public:
    void init();
    void draw(TFT_eSprite& g) const;
    void update(int direction_x, int direction_y, bool is_attacking);
    void constraint_movement(std::shared_ptr<Entity>& e, std::vector<std::shared_ptr<Entity>>& active_entities) const;
private:
    std::vector<std::vector<Tile>> terrain_data;
    // could possibly contain multiple values at given tile later
    std::map<std::tuple<int, int>, std::vector<std::shared_ptr<Entity>>> entities;
    Camera camera;
    std::shared_ptr<Player> player;

    void add_trees();
    bool is_movement_valid(std::shared_ptr<Entity>& e, std::vector<std::shared_ptr<Entity>>& active_entities, int dx, int dy) const;
    int get_tile_coordinate(int coordinate) const;
    void generate();
    bool apply_rules();
    int count_neighbours(int x, int y, TileType to_count) const;
    void find_furthest_allowed_position(std::shared_ptr<Entity>& e, std::vector<std::shared_ptr<Entity>>& active_entities) const;
    void remove_dead_entities();
};

#endif // WORLD_H
