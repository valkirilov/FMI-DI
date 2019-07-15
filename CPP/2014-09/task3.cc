#include <iostream>
#include <cmath>

using namespace std;

const int N = 5;

void square(int n, float x[], float y[]) {
    int min_x = x[0],
        max_x = x[0];
    int min_y = y[0],
        max_y = y[0];

    // Find the MIN and MAX coords
    for (int i = 1; i < n; i++)
    {
        if (x[i] < min_x) {
            min_x = x[i];
        }

        if (x[i] > max_x) {
            max_x = x[i];
        }

        if (y[i] < min_y) {
            min_y = y[i];
        }

        if (y[i] > max_y) {
            max_y = y[i];
        }
    }

    cout << "min_x: " << min_x << endl;
    cout << "max_x: " << max_x << endl;
    cout << "min_y: " << min_y << endl;
    cout << "max_y: " << max_y << endl;

    // Find which side is the bigger one
    float dx = abs(max_x - min_x);
    float dy = abs(max_y - min_y);

    float side = dx > dy ? dx : dy;
    float center_x = min_x + (side / 2);
    float center_y = min_y + (side / 2);


    cout << "Center: (" << center_x << "," << center_y << ") with side = " << side << endl;

}

int main(int argc, char** argv) {

    float x[N] = {-1, 1, 2, 3, 2};
    float y[N] = {-4, 1, 2, 3, 5};

    square(N, x, y);

    return 0;
}