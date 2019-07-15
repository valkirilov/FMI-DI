#include <iostream>
#include "Point.hh"

using namespace std;

Point::Point() {}

Point::Point(unsigned int x, unsigned int y, char value):
x(x), y(y), value(value)
{}

char Point::get_x() const {
    return x;
}

char Point::get_y() const {
    return y;
}

char Point::get_value() const {
    return value;
}
