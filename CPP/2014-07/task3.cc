#include <iostream>
#include <stdlib.h>
#include <stack>
#include <iomanip>

using namespace std;

const int SIZE = 27;
const float MIN = 0.0;
const float MAX = 4.9;
const int COLUMNS = 5;

float generate_random_number(float min, float max) {
    float number = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / max));

    return number;
}

void fill_array(float* array) {
    for (int i=0; i < SIZE; i++) {
        array[i] = generate_random_number(MIN, MAX);
    }
}

void print_array(float* array) {
    for (int i=0; i < SIZE; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

bool stacks_are_empty(stack<float> stacks[5]) {
    return stacks[0].empty() &&
        stacks[1].empty() &&
        stacks[2].empty() &&
        stacks[3].empty() &&
        stacks[4].empty();
}

int main(int argc, char** argv) {

    float A[SIZE];

    fill_array(A);
    print_array(A);

    stack<float> columns[5];

    for (int i=0; i < SIZE; ++i) {
        if (A[i] >= 0 && A[i] < 1) {
            columns[0].push(A[i]);
        }
        else if (A[i] >= 1 && A[i] < 2) {
            columns[1].push(A[i]);
        }
        else if (A[i] >= 2 && A[i] < 3) {
            columns[2].push(A[i]);
        }
        else if (A[3] >= 3 && A[i] < 4) {
            columns[3].push(A[i]);
        }
        else if (A[4] >= 4 && A[i] < 5) {
            columns[4].push(A[i]);
        }
    }

    cout << left << setw(8) << "Pod 1";
    cout << left << setw(8) << "Pod 2";
    cout << left << setw(8) << "Pod 3";
    cout << left << setw(8) << "Pod 4";
    cout << left << setw(8) << "Pod 5" << endl;

    while (!stacks_are_empty(columns)) {
        for (int i=0; i < COLUMNS; ++i) {
            if (!columns[i].empty()) {
                cout << right << setw(8) << setprecision(4) << columns[i].top();
                columns[i].pop();
            }
            else {
                cout << setw(8) <<  "";
            }
        }
        cout << endl;
    }

    return 0;
}