#include <iostream>
#include <stdlib.h>

using namespace std;

const char RIVER = 'R';
const char ROCK = 'S';
const char FOREST_1 = '1';
const char FOREST_2 = '2';
const char FOREST_3 = '3';
const char FOREST_4 = '4';

char** build_map(int m, int n) {
    char** map = new char*[m];

    for (int i=0; i<m; ++i) {
        map[i] = new char[n];
        for (int j=0; j<n; ++j) {
            char element;
            int mod = (i+j) % 10;

            switch(mod) {
                case 0:
                    element = ROCK;
                    break;
                case 1:
                    element = RIVER;
                    break;
                case 2:
                case 3:
                    element = FOREST_1;
                    break;
                case 4:
                case 5:
                case 6:
                    element = FOREST_2;
                    break;
                case 7:
                    element = FOREST_3;
                    break;
                case 8:
                case 9:
                    element = FOREST_4;
                    break;
                default:
                    element = ROCK;
            }

            map[i][j] = element;
        }
    }

    return map;
}

bool** build_visited_mask(int m, int n) {
    bool** visited = new bool*[m];
    for (int i=0; i<m; ++i) {
        visited[i] = new bool[n];
        for (int j=0; j<n; ++j) {
            visited[i][j] = false;
        }
    }
    return visited;
}

void print_map(char** map, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print_map(bool** map, int m, int n) {
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int find_area(char** map, bool** visited, int m, int n, int i, int j, char type) {
    // Check boundaries
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return 0;
    }

    // Check land type
    if (map[i][j] != type) {
        return 0;
    }

    // Chech for visited cell
    if (visited[i][j]) {
        return 0;
    }

    // Mark as visited
    visited[i][j] = true;

    return 1 +
        find_area(map, visited, m, n, i-1, j, type) +
        find_area(map, visited, m, n, i+1, j, type) +
        find_area(map, visited, m, n, i, j-1, type) +
        find_area(map, visited, m, n, i, j+1, type);
}

int find_max_area(char** map, int m, int n, char type) {
    int max_area = 0, current_area;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            if (map[i][j] == type) {
                bool** visited = build_visited_mask(n, m);
                current_area = find_area(map, visited, m, n, i, j, type);
                if (current_area > max_area) {
                    max_area = current_area;
                }
            }
        }
    }
    return max_area;
}

int main(int argc, char** argv) {

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    char** map = build_map(m, n);
    print_map(map, m, n);

    cout << "area of R: " << find_max_area(map, m, n, 'R') << endl;
    cout << "area of S: " << find_max_area(map, m, n, 'S') << endl;
    cout << "area of 1: " << find_max_area(map, m, n, '1') << endl;
    cout << "area of 2: " << find_max_area(map, m, n, '2') << endl;
    cout << "area of 3: " << find_max_area(map, m, n, '3') << endl;
    cout << "area of 4: " << find_max_area(map, m, n, '4') << endl;

    return 0;
}