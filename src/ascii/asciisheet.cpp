#include "asciisheet.hpp"
#include <iostream>

void AsciiSheet::init() {
    int width = 16;
    int index = 0;
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            int x1 = j * width;
            int y1 = i * width;

            asciiList.at(index) = sf::IntRect(x1, y1, width, width);
            index++;
        }
    }
}
