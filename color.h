#include <stdlib.h>
#include <iostream>

enum class Color { White, Black };

Color operator!(Color color);

std::ostream &operator<<(std::ostream &os, Color color);