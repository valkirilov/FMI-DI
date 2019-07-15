#include <iostream>
#include <math.h>

#include "point.hh"
#include "point.cc"

using namespace std;

// Calculate the factoriesl of a given number
long int factoriel(int number) {
    long int result = 1;

    for (int i=2; i<=number; ++i) {
        result *= i;
    }

    return result;
}

// Calculate the fibonachi number of a given number
int fibonachi(int number) {
    if (number == 0) {
        return 1;
    }

    if (number == 1) {
        return 1;
    }

    return fibonachi(number - 1) + fibonachi(number - 2);
}

int calculate_distance(Point* a, Point* b) {
    int dx = b->get_x() - a->get_x();
    int dy = b->get_y() - a->get_y();

    return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main(int argc, char* argv[]) {

    // Factoriel
    cout << "1! = " << factoriel(1) << endl;
    cout << "2! = " << factoriel(2) << endl;
    cout << "3! = " << factoriel(3) << endl;
    cout << "5! = " << factoriel(5) << endl;
    cout << "13! = " << factoriel(13) << endl;

    // Fibonachi
    cout << "Fibonachi of 1 = " << fibonachi(1) << endl;
    cout << "Fibonachi of 2 = " << fibonachi(2) << endl;
    cout << "Fibonachi of 3 = " << fibonachi(3) << endl;
    cout << "Fibonachi of 5 = " << fibonachi(5) << endl;
    cout << "Fibonachi of 13 = " << fibonachi(13) << endl;

    // Distance between points
    Point* O = new Point(0, 0);
    Point* A = new Point(1, 1);
    Point* B = new Point(2, 0);
    Point* C = new Point(3, 5);

    cout << "Distance between O(0, 0) and O(0, 0) = " << calculate_distance(O, O) << endl;
    cout << "Distance between A(1, 1) and B(2, 0) = " << calculate_distance(A, B) << endl;
    cout << "Distance between O(0, 0) and C(3, 5) = " << calculate_distance(O, C) << endl;

    return 0;
}