#include <iostream>

using namespace std;

void print_array(int a[], int size) {
    for (int i=0; i<size; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void selection_sort(int nums[], int N) {
    for (int i=0; i < N; i++) {
        int min = i;
        for (int j=min; j < N; j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }

        if (min != i) {
            int x = nums[i];
            nums[i] = nums[min];
            nums[min]= x;
        }
    }
}

bool member (int x, int a[], int size) {
    if (size == 0) {
        return false;
    }

    return a[size/2] == x ||
        (a[size/2] < x && member(x, a + size/2 + 1, size/2)) ||
        (a[size/2] > x && member(x, a, size/2));
}

void c() {
    int a = 0;
    int b = 15;
    int result = 1;

    if (b < 10 && b / a < 10) {
        result = 0;
    }
    else {
        result = 1;
    }

    cout << "result:" << result << endl;
}

int main(int argc, char** argv) {

    int SIZE = 6;
    int a[SIZE] = { 6, 4, 2, 3, 5, 1 };

    print_array(a, SIZE);

    selection_sort(a, SIZE);

    print_array(a, SIZE);

    cout << "find 1: " << member(1, a, SIZE) << endl;
    cout << "find 2: " << member(2, a, SIZE) << endl;
    cout << "find 3: " << member(3, a, SIZE) << endl;
    cout << "find 4: " << member(4, a, SIZE) << endl;
    cout << "find 5: " << member(5, a, SIZE) << endl;
    cout << "find 6: " << member(6, a, SIZE) << endl;
    cout << "find 7: " << member(7, a, SIZE) << endl;

    c();

    int d = 6 | 11;
    cout << d << endl;

    return 0;
}