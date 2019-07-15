#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 10;

void print_matrix(int m, int n, float** img) {
    for (int i=0; i < m; i++) {
        for (int j=0; j < n; j++) {
            cout << setw(8) << img[i][j];
        }
        cout << endl;
    }
}

void subsample(int m, int n, float** img) {
    int new_rows = (m+1) / 2;
    int new_cols = (n+1) / 2;

    cout << new_rows << " " << new_cols << endl;

    float** s;
    s = new float*[new_rows];

    for (int i=0; i < new_rows; i++) {
        s[i] = new float[n];
        for (int j=0; j < new_cols; j++) {
            float average = 0;
            int average_nmbers = 0;
            cout << endl;

            for (int y=i*2; y <= i*2 + 1; ++y) {
                for (int x=j*2; x <= j*2 + 1; ++x) {
                    if (y >= m || x >= n) {
                        continue;
                    }

                    average += img[y][x];
                    average_nmbers++;
                    cout << y << " " << x << ": " << img[y][x] << endl;
                    cout << "avg: " << average << " " << average_nmbers << endl;
                }
            }

            s[i][j] = average / average_nmbers;
        }
    }

    print_matrix(new_rows, new_cols, s);
}

int main(int argc, char** argv) {

    // int m, n;

    // do {
    //     cout << "Enter M: ";
    //     cin >> m;
    // } while (m < 0 || m > MAX_SIZE);

    // do {
    //     cout << "Enter N: ";
    //     cin >> n;
    // } while (n < 0 || n > MAX_SIZE);

    // float** img;
    // img = new float*[m];

    // for (int i=0; i < m; i++) {
    //     img[i] = new float[n];
    //     for (int j=0; j < n; j++) {
    //         cin >> img[i][j];
    //     }
    // }

    int m = 2;
    int n = 3;

    float** img;
    img = new float*[m];
    img[0] = new float[n];
    img[1] = new float[n];

    img[0][0] = 1.0;
    img[0][1] = 2.0;
    img[0][2] = 3.0;
    img[1][0] = 4.5;
    img[1][1] = 6.5;
    img[1][2] = 7.5;

    print_matrix(m, n, img);

    subsample(m, n, img);

    return 0;
}