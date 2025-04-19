#ifndef ENTITY_H
#define ENTITY_H

#include <TFT_eSPI.h>
#include "World.h"
#include "BoundingBox.h"
#include "constants.h"
#include "sprites.h"

class World;
class Camera;

class Entity {
private:


protected:
    World& world;
    BoundingBox bounding_box;
    AnimationSprites& animation_sprites;
    AnimationType animation_type;
    int animation_loop_length = 24;
    int animation_frame_length = 6;
    int animation_current_frame = 0;
    int scale_factor = 2;
    int x;
    int y;
public:
    Entity(World& w, int start_x, int start_y, BoundingBox bounding_box, AnimationSprites& animation_sprites);
    virtual void draw(TFT_eSprite& g, Camera& camera) const = 0;
    virtual void update(int dx, int dy) = 0;
    int get_x() const;
    int get_y() const;
    
    int get_size() const;
};

#endif