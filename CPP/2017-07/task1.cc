#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

const char RIVER = 'R';
const char ROCK = 'S';
const char FOREST_1 = '1';
const char FOREST_2 = '2';
const char FOREST_3 = '3';
const char FOREST_4 = '4';

void print_map(char** map, int m, int n) {
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

char** build_map(char input[4][6], int m, int n) {
    char** map;

    map = new char*[m];
    for (int i=0; i<m; ++i) {
        map[i] = new char[n];
        for (int j=0; j<n; ++j) {
            map[i][j] = input[i][j];
        }
    }

    return map;
}

char mutate_field(char** map, int m, int n, int i, int j) {
    if (map[i][j] == RIVER || map[i][j] == ROCK) {
        return map[i][j];
    }
    else if (map[i][j] == '1') {
        return '2';
    }
    else if (map[i][j] == '2') {
        return '3';
    }
    else if (map[i][j] == '3') {
        return '4';
    }
    else if (map[i][j] == '4') {
        int forest4_neighbours = 0;

        for (int k=i-1; k<=i+1; ++k) {
            for (int l=j-1; l<=j+1; ++l) {
                if (k <= 0 || k >= m || l <= 0 || l >= n) {
                    continue;
                }
                else if (k == i && l == j) {
                    continue;
                }
                else if (map[k][l] == '4') {
                    forest4_neighbours++;
                }
            }
        }

        return forest4_neighbours >= 3 ? '3' : '4';
    }
}

char** mutate_map(char** map, int m, int n) {
    char** mutated_map;

    mutated_map = new char*[m];
    for (int i=0; i<m; ++i) {
        mutated_map[i] = new char[n];
        for (int j=0; j<n; ++j) {
            mutated_map[i][j] = mutate_field(map, m, n, i, j);
        }
    }

    return mutated_map;
}

int main(int argc, char** argv) {

    char input[4][6] = {
        { 'R', 'R', '1', '1', '2', '2' },
        { '1', 'R', 'R', 'R', '1', '2' },
        { 'S', '1', 'R', 'R', '2', '3' },
        { '4', '4', 'S', 'S', 'R', 'R' },
    };

    char** map = build_map(input, 4, 6);
    print_map(map, 4, 6);

    for (int i=0; i<10; ++i) {
        map = mutate_map(map, 4, 6);
        print_map(map, 4, 6);
    }

    return 0;
}
