#ifndef TILE_H
#define TILE_H

#include <TFT_eSPI.h>

enum TileType {
    EMPTY,
    GRASS,
    WATER,
};

class Tile {
private:
    TileType type;
    uint32_t color;
public:
    Tile(TileType type, uint32_t color);

    bool is_walkable();

    TileType get_type();

    uint32_t get_color();
};



#endif