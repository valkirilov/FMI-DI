#include <iostream>
#include <string>

using namespace std;

string** buildLibrary(int m, int n) {
    string** library = new string*[m];

    library[0] = new string[n];
    library[0][0] = "Алгебра";
    library[0][1] = "Аналитична геометрия";
    library[0][2] = "Математически анализ";

    library[1] = new string[n];
    library[1][0] = "Увод в програмирането";
    library[1][1] = "Обектно-ориентирано програмиране";
    library[1][2] = "Структури от данни и програмиране";

    library[2] = new string[n];
    library[2][0] = "Бази от данни";
    library[2][1] = "Изкуствен интелект";
    library[2][2] = "Функционално програмиране";

    return library;
}

bool isRowSorted(string* a, int n) {
    for (int i=0; i<n-1; ++i) {
        if (a[i].compare(a[i+1]) > 0) {
            return false;
        }
    }
    return true;
}

string getMiddleBook(string*a, int n) {
    return a[n/2];
}

void revealPassword(string** a, int m, int n) {
    for (int i=0; i<m; ++i) {
        if (isRowSorted(a[i], n)) {
            string middle = getMiddleBook(a[i], n);

            int password = 0;
            for (int j=0; j<middle.length(); ++j) {
                if (middle[j] == ' ') {
                    cout << password << " ";
                    password = -1;
                }
                password++;
            }
            cout << password << " ";
        }
    }
}

int main(int argc, char** argv) {

    int m = 3;
    int n = 3;

    string** library = buildLibrary(m, n);
    revealPassword(library, m, n);

    return 0;
}