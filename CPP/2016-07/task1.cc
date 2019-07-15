#include <iostream>

using namespace std;

const int N = 5;

void init_matrix(float matrix[N][N]) {
    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
            matrix[i][j] = i + j;
        }
    }
}

float get_symetry_group_average(float matrix[N][N], int i, int j) {
    //cout << "Check (" << i << ", " << j << ")" << endl;

    int sum = 0;
    int collectables = 0;

    if (i == j) { // Check weather the element is on the main diagonal
        sum += matrix[i][j];
        sum += matrix[N-i-1][N-j-1];
        collectables += 2;
    }
    else if (i + j == N - 1) { // Check weather the element is on the secondary diagonal
        sum += matrix[i][j];
        sum += matrix[j][i];
        collectables += 2;
    }
    else { // all other elements
        sum += matrix[i][j];
        sum += matrix[N-i-1][N-j-1];
        sum += matrix[N-j-1][N-i-1];

        collectables += 3;
    }

    //cout << sum << " " << collectables << endl;

    if (collectables == 0) {
        return 0;
    }

    return sum / collectables;
}

void change_matrix(float matrix[N][N]) {
    float input[N][N];
    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
           input[i][j] = matrix[i][j];
        }
    }

    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
           matrix[i][j] = get_symetry_group_average(input, i, j);
        }
    }
}

void print_matrix(float matrix[N][N]) {
    for (int i=0; i < N; ++i) {
        for (int j=0; j < N; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char** argv) {

    float matrix[N][N];
    init_matrix(matrix);
    print_matrix(matrix);

    change_matrix(matrix);
    print_matrix(matrix);

    return 0;
}