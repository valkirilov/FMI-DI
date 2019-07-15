#ifndef POINT_HH__
#define POINT_HH__

class Point {

protected:
    int x;
    int y;

public:
    Point(int x, int y);

    int get_x();
    int get_y();

};

#endif