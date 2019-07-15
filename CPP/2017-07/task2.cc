#include <iostream>

using namespace std;

struct Node {

public:
    int value;
    Node* next;
    Node* prev;

    Node(int value): value(value), next(0), prev(0) {}
};

class List {

    Node* head;
    int size;

public:

    List(): head(new Node(0)) {
        head->next = head;
        head->prev = head;
        size = 0;
    };

    bool is_empty() {
        return head->next == head;
    }

    void push_front(int value) {
        Node* front = head->next;

        Node* node = new Node(value);
        head->next = node;
        node->prev = head;

        node->next = front;
        front->prev = node;

        size++;
    }

    void push_back(int value) {
        Node* back = head->prev;

        Node* node = new Node(value);
        head->prev = node;
        node->next = head;

        node->prev = back;
        back->next = node;

        size++;
    }

    int get_size() {
        return size;
    }

    class iterator {
        friend class List;

        List*  list;
        Node* current;

        iterator(const List* list, Node* current)
        : list(const_cast<List*>(list)),
          current(current)
        {}

    public:

        bool has_next() const {
            return current->next != list->head;
        }

        Node* get_current() {
            return current->next;
        }

        int next() {
            current = current->next;
            return current->value;
        }

        int prev() {
            current = current->prev;
            return current->value;
        }

        int get_value() const {
            if(current != list->head) {
                return current->value;
            }
        }
    };

    iterator get_iterator() {
        return iterator(this, head);
    }

    Node* get_element(int index) {
        int i = 0;
        for(List::iterator it = get_iterator(); it.has_next(); ) {
            if (i == index) {
                return it.get_current();
            }

            it.next();
            i++;
        }

        return head;
    }

    void swap(Node* node1, Node* node2) {
        int tmp = node1->value;
        node1->value = node2->value;
        node2->value = tmp;
    }

};

void print_list(List* list) {
    for(List::iterator it = list->get_iterator(); it.has_next(); ) {
        cout << it.next() << " ";
    }
    cout << endl;
}

void sort_list(List* list) {
    int size = list->get_size();

    for (int i=0; i<size-1; ++i) {
        for (int j=0; i<size-j-1; ++j) {
            Node* current = list->get_element(j);
            Node* next = list->get_element(j+1);

            if (current->value > next->value) {
                list->swap(current, next);
            }
        }
    }
}

int main(int argc, char** argv) {

    List* list = new List();

    cout << "is empty: " << list->is_empty() << endl;

    list->push_front(1);
    list->push_back(2);
    list->push_front(3);
    list->push_back(4);
    list->push_front(5);

    cout << "is empty: " << list->is_empty() << endl;
    cout << "size: " << list->get_size() << endl;

    print_list(list);
    sort_list(list);
    print_list(list);

    return 0;
}