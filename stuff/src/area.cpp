#include "area.hpp"

// There are several ways to declare and define functions.
// These are just a few examples.

// Get the area of a circle of radius 'radius'.
auto get_circle_area ( double radius ) -> double
{
    return radius * 2 * pi;
}

// Get the area of a square of side 'side'.
auto get_square_area ( double side ) -> double
{
    return side * side;
}
