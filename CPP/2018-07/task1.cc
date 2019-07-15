#include <iostream>
#include <sstream>

using namespace std;

void print_array(int n, unsigned int* a) {
    for (int i=0; i<n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool cmpLex(unsigned int a, unsigned int b) {
    string aStr, bStr;
    stringstream aStream, bStream;

    aStream << a;
    bStream << b;

    aStr = aStream.str();
    bStr = bStream.str();

    int aLen = aStr.length();
    int bLen = bStr.length();
    int len = aLen > bLen ? bLen : aLen;

    for (int i=0; i<len; ++i) {
        if (bStr[i] > aStr[i]) {
            return false;
        }
        else if (bStr[i] == aStr[i]) {
            if (i == len-1) {
                return aLen > bLen;
            }
        }
        else {
            return true;
        }
    }
}

void sortLex(int n, unsigned int* a) {

    int current, prev;
    for (int i=1; i<n; ++i) {
        current = a[i];
        prev = i - 1;

        while (prev >= 0 && cmpLex(a[prev], current)) {
            a[prev+1] = a[prev];
            prev--;
        }
        a[prev+1] = current;
    }

}

int main(int argc, char** argv) {

    // Example 1
    unsigned int a[6] = { 13, 14, 7, 2018, 9, 0 };
    print_array(6, a);

    sortLex(6, a);
    print_array(6, a);

    // Example 2
    unsigned int b[6] = { 1, 2, 3, 12, 123, 23 };
    print_array(6, b);

    sortLex(6, b);
    print_array(6, b);

    // Example 3
    unsigned int c[6] = { 5, 4, 3, 2, 1, 123 };
    print_array(6, c);

    sortLex(6, c);
    print_array(6, c);

    // Example 4
    unsigned int d[0] = { };
    print_array(0, d);

    sortLex(0, d);
    print_array(0, d);

    // Example 5
    unsigned int e[1] = { 1 };
    print_array(1, e);

    sortLex(1, e);
    print_array(1, e);

    // Example 6
    unsigned int f[2] = { 2, 12 };
    print_array(2, f);

    sortLex(2, f);
    print_array(2, f);

    // Example 7
    unsigned int g[5] = { 1, 2, 3, 4, 5 };
    print_array(5, g);

    sortLex(5, g);
    print_array(5, g);

    return 0;
}