#include "BoundingBox.h"

BoundingBox::BoundingBox(int x, int y, int width, int height): 
    x{x}, y{y}, width{width}, height{height} {}

void BoundingBox::shift(int dx, int dy) {
    x = (x + dx) % WORLD_SIZE_PIXELS;
    if (x < 0) {
        x += WORLD_SIZE_PIXELS;
    }
    
    y = (y + dy) % WORLD_SIZE_PIXELS;
    if (y < 0) {
        y += WORLD_SIZE_PIXELS;
    }
}

std::array<std::tuple<int, int>, 4> BoundingBox::get_corners() const {
    return {
        std::make_tuple(x, y),                        // Top-left
        std::make_tuple(x + width, y),                // Top-right
        std::make_tuple(x + width, y + height),       // Bottom-right
        std::make_tuple(x, y + height)                // Bottom-left
    };
}

bool BoundingBox::intersects(BoundingBox& other) {
    return !(end_x() < other.start_x() || 
             start_x() > other.end_x() ||
             end_y() < other.start_y() ||
             start_y() > other.end_y());
}

int BoundingBox::start_x() {
    return x;
}

int BoundingBox::start_y() {
    return y;
}

int BoundingBox::end_x() {
    return x + width;
}

int BoundingBox::end_y() {
    return y + height;
}