#ifndef SPRITES_H
#define SPRITES_H

#include "array"
#include "constants.h"
#include "map"
#include "TFT_eSPI.h"

enum AnimationType {
    IDLE,
    WALKING,
    ATTACKING,
    DYING,
};


typedef std::map<AnimationType, std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4>> AnimationSprites;

extern std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> player_walking;
extern std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> player_idle;
extern AnimationSprites player_sprites;

extern std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> tree_idle;
extern AnimationSprites tree_sprites;

extern std::map<int, uint16_t> player_sprites_color_map;
extern std::map<int, uint16_t> tree_sprites_color_map;

#endif