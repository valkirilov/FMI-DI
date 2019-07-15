#include <iostream>
#include <list>

using namespace std;

void print_list(list<int> l) {
    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    cout << endl;
}

int find_duplicates(list<int> l)  {
    int duplicates = 0;
    int last;
    int last_occurancies = 0;

    for (list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        if (last_occurancies == 0) {
            last = *it;
            last_occurancies = 1;
        }
        else if (last == *it) {
            last_occurancies++;
        }
        else if (last != *it) {
            if (last_occurancies > 1)  {
               duplicates++;
            }

            last = *it;
            last_occurancies = 1;
        }
    }

    // One last check for the final element
    if (last_occurancies > 1)  {
        duplicates++;
    }

    return duplicates;
}

int main() {

    list<int> l = list<int>();
    l.push_back(1);
    l.push_back(2);
    l.push_back(2);
    l.push_back(3);
    l.push_back(3);
    l.push_back(3);
    l.push_back(4);
    l.push_back(4);
    l.push_back(4);
    l.push_back(4);

    print_list(l);
    cout << "Duplicates: " << find_duplicates(l) << endl;

    return 0;
}