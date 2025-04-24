#ifndef ENTITY_H
#define ENTITY_H

#include <TFT_eSPI.h>
#include "BoundingBox.h"
#include "Camera.h"
#include "constants.h"
#include "sprites.h"

class Camera;

class Entity {
private:
protected:
    BoundingBox bounding_box;
    AnimationSprites& animation_sprites;
    AnimationType animation_type;

    int animation_loop_length = 24;
    int animation_frame_length = 6;
    int animation_current_frame = 0;
    int scale_factor = 2;
    
    int health = 10;
    int x;
    int y;
    int dx;
    int dy;
public:
    Entity(int start_x, int start_y, BoundingBox bounding_box, AnimationSprites& animation_sprites);
    virtual void draw(TFT_eSprite& g, const Camera& camera) const = 0;
    virtual void update() = 0;
    BoundingBox get_bounding_box() const;
    void set_direction(int dx, int dy);
    int get_x() const;
    int get_y() const;
    int get_dx() const;
    int get_dy() const;
    int get_size() const;
    void receive_damage(int damage);
    bool is_dead() const;
    void draw_bb(TFT_eSprite& g, int off_x, int off_y) const;
};

#endif