#ifndef POINT_HH__
#define POINT_HH__

struct Point {

private:
    unsigned int x;
    unsigned int y;
    char value;
public:
    Point();
    Point(unsigned int x, unsigned int y, char value);

    char get_x() const;
    char get_y() const;
    char get_value() const;

};

#endif