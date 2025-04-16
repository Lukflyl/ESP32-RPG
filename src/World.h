#ifndef WORLD_H
#define WORLD_H

#include <TFT_eSPI.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <array>
#include "Camera.h"
#include "BoundingBox.h"
#include "Tile.h"
#include "constants.h"

class Camera;

class World {
public:
    void draw(TFT_eSprite& g, Camera& camera);
    void init();
    void is_movement_allowed(int& desired_x, int &desired_y, BoundingBox& bounding_box);
private:
    std::vector<std::vector<Tile>> terrain_data;

    int get_tile_coordinate(int coordinate);
    void generate();
    bool apply_rules();
    int count_neighbours(int x, int y, TileType to_count);
    void find_furthest_allowed_position(int x, int y, int& desired_mov_x, int& desired_mov_y);
};

#endif // WORLD_H
