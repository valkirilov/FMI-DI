#include <iostream>

// #include "globals.hh"

#include "Point.hh"
#include "Knight.hh"

using namespace std;

// extern cont int N;
const int N = 5;

ostream& operator<<(ostream& out, const Point& point) {
    out << point.get_value();
    return out;
}

/**
 * Helpers
 */

void init_board(char board[N][N], Point game_board[N][N]) {
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            game_board[i][j] = Point(i, j, board[i][j]);
        }
    }
}

void print_board(Point board[N][N]) {
    cout << "Board:" << endl;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void print_moves(list<Point> moves) {
    cout << "Moves:" << endl;
    for (list<Point>::iterator it = moves.begin(); it != moves.end(); ++it) {
        cout << "(" << (*it).get_x() << ", " << (*it).get_y()  << ") ";
        // cout << (*it) << " ";
    }
    cout << endl;
}

int main(int argc, char** argv) {

    // char board[N][N] = {
    //     { '1', '1', '0', '2', '0' },
    //     { '0', '2', '1', 'K', '2' },
    //     { '2', 'S', '2', '2', '1' },
    //     { '1', '1', '2', '2', '0' },
    //     { '2', '2', '1', '1', '1' }
    // };

    char board[N][N] = {
        { '2', '2', '2', '2', '2' },
        { '2', '1', '0', '1', '2' },
        { '2', '0', 'K', '2', '2' },
        { '2', '0', '0', '2', '2' },
        { '2', '2', '2', '2', '2' }
    };

    Point game_board[N][N];
    init_board(board, game_board);

    print_board(game_board);

    Point knight_position = Point(3, 1, 'K');
    Knight knight = Knight(knight_position);
    list<Point> knight_moves = knight.allowedMoves(game_board);
    cout << knight_moves.size() << endl;
    print_moves(knight_moves);

    return 0;
}