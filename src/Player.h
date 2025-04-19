#ifndef PLAYER_H
#define PLAYER_H

#include <TFT_eSPI.h>
#include "Entity.h"
#include "Camera.h"
#include "BoundingBox.h"
#include <map>

class Player: public Entity {
private:
public:
    Player(World& world, int start_x, int start_y, BoundingBox b);
      
    int get_size() const;

    void draw(TFT_eSprite& g, Camera& camera);
    void update(int dx, int dy);
};



#endif