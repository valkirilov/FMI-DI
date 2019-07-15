#include <iostream>

#include <list>

// #include "globals.hh"
#include "Point.hh"
#include "GamePlayer.hh"
#include "Knight.hh"

using namespace std;

// extern const int N;
const int N = 5;

Knight::Knight() {}

Knight::Knight(Point position):
position(position)
{}

Point Knight::get_position(){
    return position;
}


bool check_bounds(int x, int y) {
    if (x < 0 || x >= N) {
        return false;
    }
    if (y < 0 || y >= N) {
        return false;
    }
    return true;
}

/**
 * Check neighbours for fire
 */
bool check_position(int x, int y, Point board[N][N]) {
    if (check_bounds(x-1, y+1) && board[x-1][y+1].get_value() == '1') {
        // cout << "-1" << endl;
        return false;
    }
    if (check_bounds(x, y+1) && board[x][y+1].get_value() == '1') {
        // cout << "-2" << endl;
        return false;
    }
    if (check_bounds(x+1, y+1) && board[x+1][y+1].get_value() == '1') {
        // cout << "-3" << endl;
        return false;
    }
    if (check_bounds(x-1, y) && board[x-1][y].get_value() == '1') {
        // cout << "-4" << endl;
        return false;
    }
    if (check_bounds(x+1, y) && board[x+1][y].get_value() == '1') {
        // cout << "-5" << endl;
        return false;
    }
    if (check_bounds(x-1, y-1) && board[x-1][y-1].get_value() == '1') {
        // cout << "-6" << endl;
        return false;
    }
    if (check_bounds(x, y-1) && board[x][y-1].get_value() == '1') {
        // cout << "-7" << endl;
        return false;
    }
    if (check_bounds(x+1, y-1) && board[x-1][y-1].get_value() == '1') {
        // cout << "-8" << endl;
        return false;
    }
    return true;
}

list<Point> Knight::allowedMoves(Point board[N][N]) {
    static list<Point> moves;
    moves.clear();

    int x = position.get_x();
    int y = position.get_y();

    // Find land neighbours
    if (check_bounds(x-1, y+1) && check_position(x-1, y+1, board)) {
        cout << "1" << check_bounds(x-1, y+1) << check_position(x-1, y+1, board) << endl;
        Point point = Point(x-1, y+1, 'K');
        cout << x-1 << " " << point.get_x() << endl;
        moves.push_back(point);
    }
    if (check_bounds(x, y+1) && check_position(x, y+1, board)) {
        cout << "2" << endl;
        moves.push_back(Point(x, y+1, 'K'));
    }
    if (check_bounds(x+1, y+1) && check_position(x+1, y+1, board)) {
        cout << "3" << endl;
        moves.push_back(Point(x+1, y+1, 'K'));
    }
    if (check_bounds(x-1, y) && check_position(x-1, y, board)) {
        cout << "4" << endl;
        moves.push_back(Point(x-1, y, 'K'));
    }
    if (check_bounds(x+1, y) && check_position(x+1, y, board)) {
        cout << "5" << endl;
        moves.push_back(Point(x+1, y, 'K'));
    }
    if (check_bounds(x-1, y-1) && check_position(x-1, y-1, board)) {
        cout << "6" << endl;
        moves.push_back(Point(x-1, y-1, 'K'));
    }
    if (check_bounds(x, y-1) && check_position(x, y-1, board)) {
        cout << "7" << endl;
        moves.push_back(Point(x, y-1, 'K'));
    }
    if (check_bounds(x+1, y-1) && check_position(x+1, y-1, board)) {
        cout << "8" << endl;
        moves.push_back(Point(x+1, y-1, 'K'));
    }

    return moves;
}
