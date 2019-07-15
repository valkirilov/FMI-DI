#ifndef GAME_PLAYER_HH__
#define GAME_PLAYER_HH__

#include <list>

// #include "globals.hh"
#include "Point.hh"

using namespace std;

// extern const int N;
const int BOARD_SIZE = 5;

struct GamePlayer {

private:
    Point position;

public:

    GamePlayer();
    GamePlayer(Point position);

    virtual Point get_position() = 0;
    virtual list<Point> allowedMoves(Point board[BOARD_SIZE][BOARD_SIZE]) = 0;

};

#endif