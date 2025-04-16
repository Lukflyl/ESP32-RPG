#ifndef CAMERA_H
#define CAMERA_H

#include <TFT_eSPI.h>
#include "Entity.h"
#include "constants.h"

class Entity;

class Camera {
private:
    int offset_pixels_x;
    int offset_pixels_y;
public:
    void follow(Entity& e);

    int get_start_tile_x();
    
    int get_start_tile_y();
    
    int get_end_tile_x();
    
    int get_end_tile_y();

    int get_offset_pixels_x();
    
    int get_offset_pixels_y();
    
};

#endif