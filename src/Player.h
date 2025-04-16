#ifndef PLAYER_H
#define PLAYER_H

#include <TFT_eSPI.h>
#include "Entity.h"
#include "Camera.h"
#include "BoundingBox.h"

class Player: public Entity {
private:
    const int SCALE_FACTOR = 2;
    static const int SPRITE_SIZE = 16;
    std::array<std::array<uint16_t, SPRITE_SIZE>, SPRITE_SIZE> sprite = {{
        {{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 2, 2, 1, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 2, 3, 2, 2, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 2, 3, 3, 3, 3, 2, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 2, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 1, 3, 3, 1, 3, 3, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 3, 3, 3, 3, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 3, 3, 4, 4, 3, 1, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 3, 3, 3, 1, 0, 0, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 1, 1, 1, 7, 7, 7, 1, 1, 1, 3, 1, 0}},
        {{0, 1, 3, 1, 0, 0, 1, 7, 7, 7, 1, 0, 0, 1, 0, 0}},
        {{0, 0, 1, 0, 0, 1, 5, 5, 1, 5, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 5, 1, 0, 1, 5, 1, 0, 0, 0, 0}},
        {{0, 0, 0, 0, 1, 6, 6, 1, 0, 1, 6, 6, 1, 0, 0, 0}},
        {{0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0}}
    }};

public:
    Player(World& world, int start_x, int start_y, BoundingBox b);
      
    void draw(TFT_eSprite& g, Camera& camera);
      
    void update(int direction_x, int direction_y);

    int get_size() const;
};



#endif