#include <iostream>

using namespace std;

const int SIZE = 2;
const int CHUNK = 2;

struct Node {
    int value;

    Node* children;
    int children_count;
    int size;

public:
    Node() {}

    Node(int value) {
        this->value = value;

        this->children = new Node[SIZE];
        this->size = SIZE;
        this->children_count = -1;
    }

    int get_value() const {
        return this->value;
    }

    int get_children_count() const {
        return this->children_count + 1;
    }

    Node* get_children() {
        return this->children;
    }

    void add_node(Node node) {
        if (this->children_count+1 == this->size) {
            // todo resize
            cout << "Please resize" << endl;
        }

        this->children_count++;
        this->children[this->children_count] = node;
    }

    void resize() {
        Node* tmp_children;
        tmp_children = this->children;

        this->size *= CHUNK;
        this->children = new Node[this->size];

        for (int i=0; i < this->children_count; i++) {
            this->children[i] = tmp_children[i];
        }

        delete [] tmp_children;
    }

    void clear() {
        Node* tmp_children;
        tmp_children = this->children;

        this->children = new Node[this->size];
        this->children_count = 0;

        // delete [] tmp_children;
    }

    void remove(int index) {
        for (int i=index; i < this->children_count; ++i) {
            this->children[i] = this->children[i+1];
        }
        this->children_count--;
    }
};

ostream& operator<<(ostream& out, const Node& node) {
    out << node.get_value() << "(" << node.get_children_count() << ")";
    return out;
}

bool member(Node root, int x) {
    if (root.get_value() == x) {
        return true;
    }

    Node* nodes = root.get_children();
    for (int i=0; i < root.get_children_count(); i++) {
        if (member(nodes[i], x)) {
            return true;
        }
    }

    return false;
}

void filterOdd(Node* root) {
    Node* nodes = root->get_children();
    for (int i=0; i < root->get_children_count(); i++) {
        if (nodes[i].get_value() % 2 == 1) {
            root->remove(i);
        }
        else {
            filterOdd(&nodes[i]);
        }
    }
}

int main(int argc, char** argv) {

    Node root8 = Node(8);
    Node element2 = Node(2);
    Node element3 = Node(3);
    Node element4 = Node(4);
    Node element5 = Node(5);
    Node element6 = Node(6);
    Node element7 = Node(7);

    element3.add_node(element4);
    element3.add_node(element5);
    element3.add_node(element6);
    element3.add_node(element7);

    root8.add_node(element2);
    root8.add_node(element3);

    cout << "root8: " << root8 << endl;
    cout << "element2: " << element2 << endl;
    cout << "element3: " << element3 << endl;

    cout << member(root8, 8) << " -> true" << endl;
    cout << member(root8, 2) << " -> true" << endl;
    cout << member(root8, 6) << " -> true" << endl;
    cout << member(element2, 8) << " -> false" << endl;
    cout << member(element2, 2) << " -> true" << endl;
    cout << member(element3, 8) << " -> false" << endl;
    cout << member(element3, 3) << " -> true" << endl;
    cout << member(element3, 4) << " -> true" << endl;

    filterOdd(&root8);

    cout << "root8: " << root8 << endl;

    return 0;
}