#ifndef PLAYER_H
#define PLAYER_H

#include <TFT_eSPI.h>
#include "Entity.h"
#include "BoundingBox.h"
#include "Camera.h"

class Player: public Entity {
private:
public:
    Player(int start_x, int start_y, BoundingBox b);

    void draw(TFT_eSprite& g, const Camera& camera) const;
    void update();
};



#endif