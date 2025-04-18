#ifndef ENTITY_H
#define ENTITY_H

#include <TFT_eSPI.h>
#include "World.h"
#include "BoundingBox.h"

class World;

class Entity {
private:
protected:
    World& world;
    BoundingBox bounding_box;
    int animation_frames = 24;
    int animation_frame_length = 6;
    int x;
    int y;
public:
    Entity(World& w, int start_x, int start_y, BoundingBox bounding_box);

    int get_x() const;
    int get_y() const;
    
    virtual int get_size() const = 0;
};

#endif