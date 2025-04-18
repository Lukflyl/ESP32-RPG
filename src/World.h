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
class BoundingBox;

class World {
public:
    void draw(TFT_eSprite& g, Camera& camera);
    void init();
    void constraint_movement(BoundingBox& bounding_box, int& dx, int &dy);
private:
    std::vector<std::vector<Tile>> terrain_data;

    bool is_movement_valid(BoundingBox& bounding_box, int dx, int dy);
    int get_tile_coordinate(int coordinate);
    void generate();
    bool apply_rules();
    int count_neighbours(int x, int y, TileType to_count);
    void find_furthest_allowed_position(BoundingBox& bounding_box, int& dx, int& dy);
};

#endif // WORLD_H
