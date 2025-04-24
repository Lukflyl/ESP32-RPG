#ifndef SPRITES_H
#define SPRITES_H

#include <TFT_eSPI.h>
#include <array>
#include <map>
#include "constants.h"

enum AnimationType {
    IDLE,
    WALK,
    ATTACK,
    DEATH,
};


typedef std::map<AnimationType, std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4>> AnimationSprites;

extern std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> player_walk;
extern std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> player_idle;
extern std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> player_attack;
extern AnimationSprites player_sprites;

extern std::array<std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE>, 4> tree_idle;
extern AnimationSprites tree_sprites;

extern std::map<int, uint16_t> player_sprites_color_map;
extern std::map<int, uint16_t> tree_sprites_color_map;

#endif