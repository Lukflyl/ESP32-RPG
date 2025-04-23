#ifndef BOUNDING_BOX_H
#define BOUNDING_BOX_H

#include <array>
#include <tuple>
#include "constants.h"

class BoundingBox {
private:
    int x;
    int y;
    int width;
    int height;
public:
    BoundingBox(int x, int y, int width, int height);

    void shift(int dx, int dy);

    std::array<std::tuple<int, int>, 4> get_corners() const;

    bool intersects(BoundingBox& other);
    int start_x();
    int start_y();
    int end_x();
    int end_y();
};

#endif