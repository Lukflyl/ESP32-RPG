#ifndef CAMERA_H
#define CAMERA_H

#include <TFT_eSPI.h>
#include "Entity.h"
#include "constants.h"

class Entity;

class Camera {
private:
    Entity* target = nullptr;
    int offset_pixels_x;
    int offset_pixels_y;
public:
    void follow(Entity* e);

    void update();

    int get_start_tile_x() const;
    
    int get_start_tile_y() const;
    
    int get_end_tile_x() const;
    
    int get_end_tile_y() const;

    int get_offset_pixels_x() const;
    
    int get_offset_pixels_y() const;
    
};

#endif