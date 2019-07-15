#include <iostream>
#include <string>

using namespace std;

#define INTEGER_ARRAY_LEN(array) ((int) (sizeof (array) / sizeof (array)[0]))
#define CHAR_ARRAY_LEN(array) ((char) (sizeof (array) / sizeof (array)[0]))

/**
 * Print array of Integers
 */
void print_array(int* array) {
    int array_size = INTEGER_ARRAY_LEN(array);
    for (int i=0; i <= array_size; ++i) {
        cout << array[i] << " ";
    }
}

/**
 * Print array of Characters
 */
void print_array(char* array) {
    int array_size = CHAR_ARRAY_LEN(array);
    for (int i=0; i <= array_size; ++i) {
        cout << array[i] << " ";
    }
}

/**
 * Print two dimencional array of Integers
 */
void print_array(int array[][3]) {
    int array_size_rows = INTEGER_ARRAY_LEN(array);
    int array_size_cols = INTEGER_ARRAY_LEN(array[0]);

    cout << "Rows: " << array_size_rows << endl;
    cout << "Cols: " << array_size_cols << endl;
    for (int i=0; i <= array_size_rows; ++i) {
        for (int j=0; i <= array_size_cols; ++j) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

int main(int argc, char* argv[]) {

    // Numeric types
    int integer = 1;
    float floatRealNumber = 1234.5678;
    double doubleRealNumber = 1234.56789123456;

    cout << "Integer: " << integer << endl;
    cout << "Float: " << floatRealNumber << endl;
    cout << "Double: " << doubleRealNumber << endl;

    // Character types
    char character = 'C';
    char cString[] = "I'm a fake string, just an array of chars";
    string cppString = "Yeah, I'm the real string!";

    cout << "Character: " << character << endl;
    cout << "C String: " << cString << endl;
    cout << "C++ String: " << cppString << endl;

    // Complex types
    int arrayOfIntegers[] = { 1, 2, 3 };

    cout << "Array of Integers: ";
    print_array(arrayOfIntegers);
    cout << endl;

    char arrayOfChars[] = { 'A', 'B', 'C' };

    cout << "Array of Chars: ";
    print_array(arrayOfChars);
    cout << endl;

    int twoDimencionalArray[2][3] = {
        { 1, 2, 3 },
        { 4, 5, 6 },
    };

    cout << "Two dimencional array: " << endl;
    print_array(twoDimencionalArray);
    cout << endl;

    return 0;
}