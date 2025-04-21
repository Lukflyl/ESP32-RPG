#ifndef TREE_H
#define TREE_H

#include <TFT_eSPI.h>
#include "Entity.h"
#include "BoundingBox.h"
#include "Camera.h"

class Tree: public Entity {
private:
public:
    Tree(int start_x, int start_y, BoundingBox b);
    
    void draw(TFT_eSprite& g, const Camera& camera) const;
    void update();
};
    


#endif