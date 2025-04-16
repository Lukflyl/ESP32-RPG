#include "Tile.h"

Tile::Tile(TileType type, uint32_t color): type{type}, color{color} {}

bool Tile::is_walkable() {
    return type != WATER;
}

TileType Tile::get_type() {
    return type;
}

uint32_t Tile::get_color() {
    return color;
}