#ifndef KNIGHT_HH__
#define KNIGHT_HH__

#include <list>

// #include "globals.hh"
#include "Point.hh"
#include "GamePlayer.hh"

using namespace std;

// extern const int N;
const int SIZE = 5;

struct Knight {

private:
    Point position;

public:

    Knight();
    Knight(Point position);

    Point get_position();
    list<Point> allowedMoves(Point board[SIZE][SIZE]);

};

#endif