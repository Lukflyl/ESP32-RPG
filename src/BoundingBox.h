#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <TFT_eSPI.h>
#include <array>
#include <tuple>
#include "constants.h"


class BoundingBox {
private:
    int x;
    int y;
    int offset_x;
    int offset_y;
    int width;
    int height;
public:
    BoundingBox(int x, int y, int offset_x, int offset_y, int width, int height);

    void update(int new_x, int new_y);

    std::array<std::tuple<int, int>, 4> get_corners() const;

    void draw(TFT_eSprite& g, int off_x, int off_y) const;
};

#endif