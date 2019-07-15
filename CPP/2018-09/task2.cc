#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

struct Node {
        int value;
        Node* next;
        Node* k_next;

public:
    Node(int value):
    value(value),
    next(0),
    k_next(0)
    {}
};

class List {

    Node* tail;
    int size;
    int k;

public:

    Node* head;

    List():
    head(new Node(0)),
    tail(new Node(0)),
    size(0),
    k(0) {
        head->next = tail;
        head->k_next = tail;

        tail->next = head;
    }

    bool is_empty();
    void add(int value);
    void build_index();

    class iterator {

        friend class List;

        List* list;
        Node* current;

        iterator(List* list, Node* current):
        list(list),
        current(current)
        {}

    public:

        bool has_next() {
            return current->next != list->head;
        }

        Node* next() {
            current = current->next;
            return current;
        }

    };

    iterator begin() {
        return iterator(this, head);
    }

};

bool List::is_empty() {
    return this->head->next == this->head;
}

void List::add(int value) {
    Node* back = tail->next;
    Node* node = new Node(value);

    if (size == 0) {
        head->next = node;
    }

    back->next = node;
    node->next = head;
    tail->next = node;

    size++;
    k = ceil(sqrt(size));

    build_index();
}

void List::build_index() {
    int index = 0;
    Node* prev_node;
    for (List::iterator it = begin(); it.has_next();) {
        Node* next = it.next();

        next->k_next = 0;

        if (index == 0) {
            prev_node = next;
        }
        if (index % k == 0) {
            prev_node->k_next = next;
            prev_node = next;
        }

        index++;
    }
}

ostream& operator<<(ostream& out, List* list) {
    for (List::iterator it = list->begin(); it.has_next();) {
        out << it.next()->value << " ";
    }

    return out;
}

List* readList(char* filename) {
    List* list = new List();
    ifstream file(filename);

    int input;
    if (file.is_open()) {

        while(true) {
            file >> input;
            list->add(input);

            if (file.eof()) {
                break;
            }
        };

        file.close();
    }

    return list;
}

bool member(List* list, int value) {
    Node* current = list->head->next;
    Node* last;

    int index = 0;
    bool is_fast_search = true;
    while (true) {
        if (current->value == value) {
            return true;
        }

        if (current->value < value) {
            last = current;
            if (is_fast_search && current->k_next != 0) {
                current = current->k_next;
            }
            else if (current->next != 0) {
                current = current->next;
            }
            else {
                break;
            }
        }
        else if (current->value > value) {
            current = last;
            is_fast_search = false;
        }

        index++;
        if (index == 6) {
            break;
        }
    }

    return false;
}

int main(int argc, char** argv) {

    List* list = readList((char *)"list.in");
    cout << list << endl;

    cout << "member(1): " << member(list, 1) << endl;
    cout << "member(4): " << member(list, 4) << endl;
    cout << "member(7): " << member(list, 7) << endl;
    cout << "member(3): " << member(list, 3) << endl;
    cout << "member(5): " << member(list, 5) << endl;
    cout << "member(6): " << member(list, 6) << endl;
    cout << "member(9): " << member(list, 9) << endl;
    cout << "member(13): " << member(list, 13) << endl;

    return 0;
}