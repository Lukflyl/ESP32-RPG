#include "BoundingBox.h"

BoundingBox::BoundingBox(int x, int y, int offset_x, int offset_y, int width, int height): 
    x{x}, y{y}, offset_x{offset_x}, offset_y{offset_y}, width{width}, height{height} {}

void BoundingBox::update(int new_x, int new_y) {
    x = new_x;
    y = new_y;
}

std::array<std::tuple<int, int>, 4> BoundingBox::get_corners() const {
    return {
        std::make_tuple(x + offset_x, y + offset_y),                        // Top-left
        std::make_tuple(x + offset_x + width, y + offset_y),                // Top-right
        std::make_tuple(x + offset_x + width, y + offset_y + height),       // Bottom-right
        std::make_tuple(x + offset_x, y + offset_y + height)                // Bottom-left
    };
}

void BoundingBox::draw(TFT_eSprite& g, int off_x, int off_y) {
    auto corners = get_corners();
    g.drawLine(std::get<0>(corners[0]) - off_x, std::get<1>(corners[0]) - off_y, std::get<0>(corners[1]) - off_x, std::get<1>(corners[1]) - off_y, TFT_RED);
    g.drawLine(std::get<0>(corners[1]) - off_x, std::get<1>(corners[1]) - off_y, std::get<0>(corners[2]) - off_x, std::get<1>(corners[2]) - off_y, TFT_RED);
    g.drawLine(std::get<0>(corners[2]) - off_x, std::get<1>(corners[2]) - off_y, std::get<0>(corners[3]) - off_x, std::get<1>(corners[3]) - off_y, TFT_RED);
    g.drawLine(std::get<0>(corners[3]) - off_x, std::get<1>(corners[3]) - off_y, std::get<0>(corners[0]) - off_x, std::get<1>(corners[0]) - off_y, TFT_RED);
}