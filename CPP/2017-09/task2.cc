#include <iostream>

using namespace std;

template <class T>
class List {

    struct Node {

    public:
        T value;
        Node* next;
        Node* prev;

        Node(T value):
        value(value),
        next(0),
        prev(0) {}
    };

    Node* head;
    int size;

public:

    List():
    head(new Node(0)) {
        head->next = head;
        head->prev = head;
        size = 0;
    }

    bool is_empty();
    int get_size();

    void push_front(T value);
    void push_back(T value);

    T pop_front();
    T pop_back();

    class iterator {

        friend class List;

        List* list;
        Node* current;

        iterator(List<T>* list, Node* current):
        list(list),
        current(current)
        {}

    public:

        bool has_next() {
            return current->next != list->head;
        }

        Node* get_current_node() {
            return current;
        }

        T get_current() {
            return current->value;
        }

        void next() {
            current = current->next;
        }
    };

    iterator begin() {
        return iterator(this, head);
    }

    Node* get_element_node(int index) {
        int i=0;

        for (List<T>::iterator it=begin(); it.has_next();) {
            it.next();

            if (i == index) {
                return it.get_current_node();
            }

            i++;
        }

        return head;
    }

    T get_element(int index) {
        return get_element_node(index)->value;
    }

    void swap(int i, int j) {
        Node* node1 = this->get_element_node(i);
        Node* node2 = this->get_element_node(j);

        T temp = node1->value;
        node1->value = node2->value;
        node2->value = temp;
    }

};

template <class T>
bool List<T>::is_empty() {
    return head->next == head;
}

template <class T>
int List<T>::get_size() {
    return size;
}

template <class T>
void List<T>::push_front(T value) {
    Node* front = head->next;
    Node* node = new Node(value);

    node->next = front;
    front->prev = node;

    head->next = node;
    node->prev = head;

    size++;
}

template <class T>
void List<T>::push_back(T value) {
    Node* back = head->prev;
    Node* node = new Node(value);

    node->prev = back;
    back->next = node;

    node->next = head;
    head->prev = node;

    size++;
}

template <class T>
T List<T>::pop_front() {
    Node* front = head->next;

    head->next = front->next;
    front->next->prev = head;

    size--;

    return front->value;
}

template <class T>
T List<T>::pop_back() {
    Node* back = head->prev;

    back->next = head;
    head->prev = back;

    size--;

    return back->value;
}

// template <class T>
// List<T>* operator+=(const List<T>& list1, const List<T>& list2) {
//     List<T>* list = new List<T>();

//     for (List<int>::iterator list_iterator=list1->begin(); list_iterator.has_next();) {
//         list_iterator.next();
//         list->push_back(list_iterator.get_current());
//     }

//     for (List<int>::iterator list_iterator=list2->begin(); list_iterator.has_next();) {
//         list_iterator.next();
//         list->push_back(list_iterator.get_current());
//     }

//     return list;
// }

template <class T>
List<T>* operator+(const List<T>& list1, const List<T>& list2) {
    List<T>* list = new List<T>();

    for (List<int>::iterator list_iterator=list1->begin(); list_iterator.has_next();) {
        list_iterator.next();
        list->push_back(list_iterator.get_current());
    }

    for (List<int>::iterator list_iterator=list2->begin(); list_iterator.has_next();) {
        list_iterator.next();
        list->push_back(list_iterator.get_current());
    }

    return list;
}

ostream& operator<<(ostream& out, List<int>* list) {
    for(List<int>::iterator it=list->begin(); it.has_next();) {
        it.next();
        out << it.get_current() << " ";
    }

    return out;
}

List<int>* merge_lists(List<List<int>* >* lists) {
    List<int>* merged_list = new List<int>();

    for (List<List<int>* >::iterator lists_iterator=lists->begin(); lists_iterator.has_next();) {
        lists_iterator.next();
        List<int>* list = lists_iterator.get_current();

        for (List<int>::iterator list_iterator=list->begin(); list_iterator.has_next();) {
            list_iterator.next();
            merged_list->push_back(list_iterator.get_current());
        }
    }

    return merged_list;
}

List<int>* merge_and_sort_lists(List<List<int>* >* lists) {
    List<int>* list = merge_lists(lists);
    int size = list->get_size();

    cout << list << endl;

    for (int i=0; i<size-1; ++i) {
        for (int j=0; j<size-i-1; ++j) {
            if (list->get_element(j) > list->get_element(j+1)) {
                list->swap(j, j+1);
            }
        }
    }

    return list;
}

int main(int argc, char** argv) {

    List<int>* list1 = new List<int>();
    list1->push_front(1);
    list1->push_back(2);
    list1->push_front(3);
    list1->push_back(4);
    list1->push_front(5);

    cout << list1 << endl;

    List<int>* list2 = new List<int>();
    list2->push_front(8);
    list2->push_back(6);
    list2->push_front(7);

    cout << list2 << endl;

    List<int>* list3 = new List<int>();
    list3->push_front(12);
    list3->push_back(5);
    list3->push_front(3);

    cout << list3 << endl;

    List<List<int>*>* lists = new List<List<int>* >[2];
    lists->push_back(list1);
    lists->push_back(list3);
    lists->push_back(list2);

    List<int>* sorted_list = merge_and_sort_lists(lists);
    cout << sorted_list << endl;

    cout << list1 + list2 << endl;

    return 0;
}