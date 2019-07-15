#include <iostream>
#include <list>
#include <map>

using namespace std;

struct ChessPosition {
    char x;
    short y;

public:
    ChessPosition(): x(' '), y(0) {}
    ChessPosition(char x, short y): x(x), y(y) {}
    ChessPosition(const ChessPosition& position) {
        x = position.x;
        y = position.y;
    }

    void set_position(char x, short y) {
        this->x = x;
        this->y = y;
    };

    string to_string() {
        string code;
        code.push_back(x);
        code.push_back(y);
        return code;
    }
};

bool operator==(const ChessPosition& position1, const ChessPosition& position2) {
    return position1.x == position2.x && position1.y == position2.y;
}

bool operator!=(const ChessPosition& position1, const ChessPosition& position2) {
    return position1.x != position2.x || position1.y != position2.y;
}

ostream& operator<<(ostream& out, const ChessPosition& position) {
    out << position.x << position.y;
    return out;
}

class ChessPiece {

private:
    ChessPosition position;
    string name;

public:

    virtual ChessPosition getPosition() = 0;
    virtual void set_position(ChessPosition position) = 0;
    virtual list<ChessPosition> allowedMoves() = 0;
    virtual bool captures(ChessPosition position) = 0;

    virtual void print_moves() = 0;
    virtual void print_move(ChessPosition start_position, ChessPosition end_position) = 0;
    virtual void print_position() = 0;

};

class Rook : public ChessPiece {

private:
    ChessPosition position;
    string name;

public:

    Rook(char x, short y): position(x, y) {
        name = "Rook";
    }

    ChessPosition getPosition() {
        return position;
    }

    void set_position(ChessPosition new_position) {
        position = new_position;
    }

    list<ChessPosition> allowedMoves() {
        static list<ChessPosition> positions;
        positions.clear();

        // cout << "Generate moves: ";

        // Generate horizontal moves
        for (char x='A'; x <= 'H'; x++) {
            ChessPosition newPosition = ChessPosition(x, position.y);

            // cout << newPosition << " ";

            if (newPosition != position) {
                positions.push_back(newPosition);
            }
        }

        // Generate vertical moves
        for (int y=1; y <= 8; y++) {
            ChessPosition newPosition = ChessPosition(position.x, y);

            // cout << newPosition << " ";

            if (newPosition != position) {
                positions.push_back(newPosition);
            }
        }

        // cout << endl;

        return positions;
    }

    bool captures(ChessPosition position) {
        list<ChessPosition> moves = allowedMoves();
        for (list<ChessPosition>::iterator it = moves.begin(); it != moves.end(); ++it) {
            if (*it == position){
                return true;
            }
        }
        return false;
    }

    // Extra
    void print_moves() {
        list<ChessPosition> moves = this->allowedMoves();
        cout << name << " on " << position << "(" << moves.size() << "): ";
        for (list<ChessPosition>::iterator it = moves.begin(); it != moves.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    void print_move(ChessPosition start_position, ChessPosition end_position) {
        cout << name << " " << start_position << " -> " << end_position << endl;
    }

    void print_position() {
        cout << name << " on " << position << endl;
    }

};

class Knight : public ChessPiece {

private:
    ChessPosition position;
    string name;

public:

    Knight(char x, short y): position(x, y) {
        name = "Knight";
    }

    ChessPosition getPosition() {
        return position;
    }

    void set_position(ChessPosition new_position) {
        position = new_position;
    }

    list<ChessPosition> allowedMoves() {
        static list<ChessPosition> positions;
        positions.clear();

        // Go up

        // Generate move to x-1 y+2
        if (position.x - 1 >= 'A' && position.y + 2 <= 8) {
            ChessPosition newPosition = ChessPosition(position.x - 1, position.y + 2);
            positions.push_back(newPosition);
        }

        // Generate move to x+1 y+2
        if (position.x + 1 <= 'H' && position.y + 2 <= 8) {
            ChessPosition newPosition = ChessPosition(position.x + 1, position.y + 2);
            positions.push_back(newPosition);
        }

        // Generate move to x-2 y+1
        if (position.x - 2 >= 'A' && position.y + 1 <= 8) {
            ChessPosition newPosition = ChessPosition(position.x - 2, position.y + 1);
            positions.push_back(newPosition);
        }

        // Generate move to x+2 y+1
        if (position.x + 2 <= 'H' && position.y + 2 <= 8) {
            ChessPosition newPosition = ChessPosition(position.x + 2, position.y + 1);
            positions.push_back(newPosition);
        }

        // Go down

        // Generate move to x+1 y-2
        if (position.x + 1 <= 'H' && position.y - 2 >= 1) {
            ChessPosition newPosition = ChessPosition(position.x + 1, position.y - 2);
            positions.push_back(newPosition);
        }

        // Generate move to x-1 y-2
        if (position.x - 1 >= 'A' && position.y - 2 >= 1) {
            ChessPosition newPosition = ChessPosition(position.x - 1, position.y - 2);
            positions.push_back(newPosition);
        }

        // Generate move to x+2 y-1
        if (position.x + 2 <= 'H' && position.y - 1 >= 1) {
            ChessPosition newPosition = ChessPosition(position.x + 2, position.y - 1);
            positions.push_back(newPosition);
        }

        // Generate move to x-2 y-1
        if (position.x - 2 >= 'A' && position.y - 1 >= 1) {
            ChessPosition newPosition = ChessPosition(position.x - 2, position.y - 1);
            positions.push_back(newPosition);
        }

        return positions;
    }

    bool captures(ChessPosition position) {
        list<ChessPosition> moves = allowedMoves();
        for (list<ChessPosition>::iterator it = moves.begin(); it != moves.end(); ++it) {
            if (*it == position){
                return true;
            }
        }
        return false;
    }

    // Extra
    void print_moves() {
        list<ChessPosition> moves = this->allowedMoves();
        cout << name << " on " << position << ": ";
        for (list<ChessPosition>::iterator it = moves.begin(); it != moves.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    void print_move(ChessPosition start_position, ChessPosition end_position) {
        cout << name << " " << start_position << " -> " << end_position << endl;
    }

    void print_position() {
        cout << name << " on " << position << endl;
    }

};

bool validate_board(list<ChessPiece*> pieces) {
    map<string, bool> positions;

    for (list<ChessPiece*>::iterator it = pieces.begin(); it != pieces.end(); ++it) {
        list<ChessPosition> moves = (*it)->allowedMoves();
        // (*it)->print_moves();

        for (list<ChessPosition>:: iterator itm = moves.begin(); itm != moves.end(); ++itm) {
            // cout << *itm << endl;

            if (positions.find((*itm).to_string()) != positions.end()) {
                return false;
            }

            positions[(*itm).to_string()] = true;
        }
    }

    return true;
}


void print_board(list<ChessPiece*> pieces) {
    cout << "> Board:" << endl;
    for (list<ChessPiece*>::iterator itp = pieces.begin(); itp != pieces.end(); ++itp) {
        (*itp)->print_position();
    }
}

void allMoves(list<ChessPiece*> pieces) {
    for (list<ChessPiece*>::iterator itp = pieces.begin(); itp != pieces.end(); ++itp) {
        list<ChessPosition> moves = (*itp)->allowedMoves();
        (*itp)->print_moves();
        for (list<ChessPosition>::iterator itm = moves.begin(); itm != moves.end(); ++itm) {
            ChessPosition tempPosition = (*itp)->getPosition();
            cout << "Move to " << (*itm) << ": ";

            (*itp)->set_position(*itm);

            // print_board(pieces);
            cout << "Validate boiard: " << validate_board(pieces) << endl;
            if (validate_board(pieces)) {
                (*itp)->print_move(tempPosition, (*itm));
            }

            (*itp)->set_position(tempPosition);
        }
    }
}


int main(int argc, char** argv) {

    ChessPosition positionA3 = ChessPosition('A', 3);
    ChessPosition positionB2 = ChessPosition('B', 2);

    Rook rookA1 = Rook('A', 1);

    // rookA1.print_moves();
    // cout << "Rook on A1 to A3: " << rookA1.captures(positionA3) << endl;
    // cout << "Rook on A1 to B2: " << rookA1.captures(positionB2) << endl;

    Knight knightB1 = Knight('B', 1);
    // knightB1.print_moves();
    // cout << "Knight on A1 to A3: " << knightB1.captures(positionA3) << endl;
    // cout << "Knight on A1 to B2: " << knightB1.captures(positionB2) << endl;

    Knight knightD3 = Knight('D', 3);
    // knightD3.print_moves();
    // cout << "Knight on D3 to A3: " << knightD3.captures(positionA3) << endl;
    // cout << "Knight on D3 to B2: " << knightD3.captures(positionB2) << endl;

    Knight knightE5 = Knight('E', 5);

    list<ChessPiece*> pieces;
    pieces.push_back(&rookA1);
    // pieces.push_back(&knightB1);
    // pieces.push_back(&knightD3);
    pieces.push_back(&knightE5);

    print_board(pieces);
    cout << "Validate initial board: " << validate_board(pieces) << endl;

    allMoves(pieces);

    return 0;
}