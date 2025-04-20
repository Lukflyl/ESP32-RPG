#ifndef TREE_H
#define TREE_H

#include <TFT_eSPI.h>
#include "Entity.h"
#include "World.h"
#include "Camera.h"
#include "BoundingBox.h"

class Tree: public Entity {
private:
public:
    Tree(World& world, int start_x, int start_y, BoundingBox b);
    
    void draw(TFT_eSprite& g, Camera& camera) const;
    void update(int dx, int dy);
};
    


#endif