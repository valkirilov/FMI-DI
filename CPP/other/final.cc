#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

/**
 * Stack implementation
 */

class Stack {

    int* data;
    int top;
    int size;

public:

    Stack() {
        this->size = 2;
        this->top = -1;
        this->data = new int[this->size];
    }

    ~Stack() {
        while(this->is_empty() == false) {
            this->pop();
        }
        delete [] this->data;
    }

    bool is_empty();
    bool is_full();
    void push(int value);
    int pop();


};

bool Stack::is_empty() {
    return this->top == -1;
}

bool Stack::is_full() {
    return this->top == this->size - 1;
}

void Stack::push(int value) {
    if (this->is_full()) {
        int* tmp = this->data;

        this->size *= 2;
        this->data = new int[this->size];

        for (int i=0; i <= this->top; ++i) {
            this->data[i] = tmp[i];
        }

        delete [] tmp;
    }

    this->top++;
    this->data[this->top] = value;
}

int Stack::pop() {
    if (this->is_empty()) {
        return -1;
    }

    return this->data[this->top--];
}

/**
 * List implementation
 */

template <class T>
struct Node {

    T value;
    Node<T>* next;
    Node<T>* prev;

public:

    Node(T value):
    value(value),
    next(0),
    prev(0)
    {}

};

template <class T>
class List {

    Node<T>* head;
    int size;

public:

    List():
    head(new Node<T>(0)) {
        head->next = head;
        head->prev = head;
        size = 0;
    }

    List(List<T>* input):
    head(new Node<T>(0)) {
        head->next = head;
        head->prev = head;
        size = 0;

        for (List<T>::iterator it = input->begin(); it.has_next(); ) {
            Node<T>* node = it.next();
            this->push_back(node->value);
        }
    }

    ~List() {
        while(is_empty() == false) {
            this->pop_front();
        }

        delete this->head;
    }

    bool is_empty();
    int get_size();
    void push_front(T value);
    void push_back(T value);
    T pop_front();
    T pop_back();

    class iterator {

        friend class List;

        List<T>* list;
        Node<T>* current;

        iterator(List<T>* list, Node<T>* current):
        list(list), current(current)
        {}

    public:
        bool has_next();
        Node<T>* next();

    };

    iterator begin() {
        return iterator(this, this->head);
    }

    Node<T>* get_element(int index);
    void swap(int index1, int index2);

};

template <class T>
bool List<T>::is_empty() {
    return head->next == head;
}

template <class T>
int List<T>::get_size() {
    return this->size;
}

template <class T>
void List<T>::push_front(T value) {
    Node<T>* front = this->head->next;
    Node<T>* node = new Node<T>(value);

    node->next = front;
    front->prev = node;

    this->head->next = node;
    node->prev = this->head;

    this->size++;
}

template <class T>
void List<T>::push_back(T value) {
    Node<T>* back = this->head->prev;
    Node<T>* node = new Node<T>(value);

    node->next = this->head;
    this->head->prev = node;

    back->next = node;
    node->prev = back;

    this->size++;;
}

template <class T>
T List<T>::pop_front() {
    if (this->is_empty()) {
        return (T)-1;
    }

    Node<T>* node = this->head->next;

    this->head->next = node->next;
    node->next->prev = this->head;

    this->size--;

    return node->value;
}

template <class T>
T List<T>::pop_back() {
    if (is_empty()) {
        return -1;
    }

    Node<terminate_handler>* node = this->head->prev;

    this->head->prev = node->prev;
    node->prev = this->head;

    this->size--;

    return node->value;
}

template <class T>
bool List<T>::iterator::has_next() {
    return this->current->next != this->list->head;
}

template <class T>
Node<T>* List<T>::iterator::next() {
    if (this->has_next()) {
        this->current = this->current->next;
        return this->current;
    }
    return this->list->head;
}

template <class T>
Node<T>* List<T>::get_element(int index) {
    int i=0;
    for (List<T>::iterator it = this->begin(); it.has_next();) {
        Node<T>* node = it.next();

        if (i == index) {
            return node;
        }

        i++;
    }
}

template <class T>
void List<T>::swap(int index1, int index2) {
    Node<T>* node1 = this->get_element(index1);
    Node<T>* node2 = this->get_element(index2);

    int tmp = node1->value;
    node1->value = node2->value;
    node2->value = tmp;
}

ostream& operator<<(ostream& out, List<int>* list) {
    for (List<int>::iterator it = list->begin(); it.has_next();) {
        Node<int>* node = it.next();
        out << node->value << " ";
    }
    return out;
}

/**
 * Tree Implementation
 */

class Tree {

    int value;
    Tree* left;
    Tree* right;

public:

    Tree(int value):
    value(value) {
        left = 0;
        right = 0;
    }

    void add(int value);
    int get_value();
    Tree* get_left();
    Tree* get_right();
    int get_depth(int depth);
    int get_width(int width);
    bool find(int value);

};

void Tree::add(int value) {
    if (value <= this->value) {
        if (left == 0) {
            left = new Tree(value);
        }
        else {
            this->left->add(value);
        }
    }
    else {
        if (right == 0) {
            right = new Tree(value);
        }
        else {
            this->right->add(value);
        }
    }
}

int Tree::get_value() {
    return this->value;
}

Tree* Tree::get_left() {
    return this->left;
}

Tree* Tree::get_right() {
    return this->right;
}

int Tree::get_depth(int depth) {
    Tree* left = this->left;
    Tree* right = this->right;

    if (left == 0 && right == 0) {
        return depth;
    }

    int left_depth = 0;
    int right_depth = 0;

    if (left != 0) {
        left_depth = left->get_depth(depth + 1);
    }

    if (right != 0) {
        right_depth = right->get_depth(depth + 1);
    }

    return max(left_depth, right_depth);
};

int Tree::get_width(int width) {
    Tree* left = this->get_left();
    Tree* right = this->get_right();

    if (left == 0 && right == 0) {
        return width;
    }

    int left_width = 0;
    int right_width = 0;

    if(left != 0) {
        left_width = left->get_depth(width + 1);
    }

    if(right != 0) {
        right_width = right->get_depth(width + 1);
    }

    return left_width + right_width;
}

bool Tree::find(int value) {
    List<Tree*>* nodes = new List<Tree*>();
    nodes->push_front(this);

    Tree* root;
    while(nodes->is_empty() == false) {
        root = nodes->pop_front();

        if (root->value == value) {
            return true;
        }

        Tree* right = root->get_right();
        if (right != 0) {
            nodes->push_front(right);
        }

        Tree* left = root->get_left();
        if (left != 0) {
            nodes->push_front(left);
        }

    }

    return false;
}

ostream& operator<<(ostream& out, Tree* tree) {
    out << tree->get_value();

    out << "(";
    Tree* left = tree->get_left();
    if (left != 0) {
        out << left << ",";
    }
    else {
        out << "*,";
    }

    Tree* right = tree->get_right();
    if (right != 0) {
        out << right;
    }
    else {
        out << "*";
    }

    out << ")";
    return out;
}

/**
 * Utils
 */

Stack* read_input(char** argv) {
    Stack* stack = new Stack();
    ifstream file(argv[1]);


    if (file.is_open()) {
        int input;

        while(true) {
            file >> input;
            stack->push(input);

            if (file.eof()) {
                break;
            }
        }

        file.close();
    }

    return stack;
}

List<int>* sort_list(List<int>* input) {
    List<int>* list = new List<int>(input);
    int size = list->get_size();

    for (int i=0; i<size-1; ++i) {
        for (int j=0; j<size-i-1; ++j) {
            Node<int>* node1 = list->get_element(j);
            Node<int>* node2 = list->get_element(j+1);

            if (node1->value > node2->value) {
                list->swap(j, j+1);
            }
        }
    }

    return list;
}

List<int>* build_list(Stack* stack) {
    List<int>* list = new List<int>();

    while(stack->is_empty() == false) {
        int value = stack->pop();

        if (value % 2 == 0) {
            list->push_front(value);
        }
        else {
            list->push_back(value);
        }
    }

    return list;
}

Tree* build_tree(List<int>* list) {
    Tree* tree;

    int init = true;
    for (List<int>::iterator it = list->begin(); it.has_next();) {
        Node<int>* node = it.next();

        if (init) {
            tree = new Tree(node->value);
            init = false;
        }
        else {
            tree->add(node->value);
        }
    }

    return tree;
}

void write_output(Tree* tree, char** argv) {
    ofstream file(argv[2]);

    if (file.is_open()) {
        file << tree;
        file.close();
    }
}

const int m = 3;
const int n = 4;

void print_matrix(int matrix[m][n]) {
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            cout << std::setw(3) << matrix[i][j];
        }
        cout << endl;
    }
}

int main(int argc, char** argv) {

    Stack* input = read_input(argv);
    List<int>* list = build_list(input);
    cout << list << endl;

    List<int>* sorted_list = sort_list(list);
    cout << list << endl;
    cout << sorted_list << endl;

    Tree* tree = build_tree(sorted_list);
    cout << tree << endl;

    cout << "depth: " << tree->get_depth(1) << endl;
    cout << "width: " << tree->get_width(1) << endl;
    cout << "find 1: " << tree->find(1) << endl;
    cout << "find 13: " << tree->find(13) << endl;
    cout << "find 54: " << tree->find(54) << endl;

    write_output(tree, argv);

    int matrix[m][n] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 }
    };

    print_matrix(matrix);

    return 0;
}