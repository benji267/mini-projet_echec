#include <stdlib.h>
#include <iostream>
#include <color.h>

Color operator!(Color color) {
    return color == Color::White ? Color::Black : Color::White;
}

std::ostream &operator<<(std::ostream &os, Color color) {
    switch (color) {
    case Color::White:
        return os << "White";
    case Color::Black:
        return os << "Black";
    default:
        return os << "Unknown";
    }
}