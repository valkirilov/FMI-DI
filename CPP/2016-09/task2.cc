#include <iostream>
#include <queue>

using namespace std;

class Tree {

    int value;

    Tree* children;
    int children_count;
    int children_size;

public:

    Tree() {
        value = 0;
        children_count = 0;
        children_size = 2;
    }

    Tree(int value): value(value) {
        children_count = 0;
        children_size = 2;
        children = new Tree[children_size];
    }

    Tree* add_child(int value) {
        if (children_count+1 >= children_size) {
            Tree* tmp_children = children;
            children_size *= 2;
            children = new Tree[children_size];

            for (int i=0; i < children_count; ++i) {
                children[i] = tmp_children[i];
            }

            delete [] tmp_children;
        }

        // children[children_count].set_value(value);
        // children_count++;

        // return &children[children_count];

        Tree* tree = new Tree(value);
        children[children_count] = *tree;
        children_count++;

        return tree;
    }

    int get_value() const {
        return value;
    }

    void set_value(int value) {

    }

    int get_children_count() const {
        return children_count;
    }

    Tree* get_children() const {
        return children;
    }

};

int* init_array(int size) {
    int* array = new int[size];

    for (int i=0; i < size; ++i) {
        array[i] = i+1;
    }

    return array;
}

void print_array(int* array, int size) {
    for (int i=0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int find_depth(Tree* tree, int depth) {
    cout << "Find depth of " << tree << endl;
    int children_count = tree->get_children_count();
    if (children_count == 0) {
        return depth;
    }

    int max_depth = depth;
    Tree* children = tree->get_children();
    for (int i=0; i < children_count; ++i) {
        int current_depth = find_depth(&children[i], depth + 1);
        if (current_depth > max_depth) {
            max_depth = current_depth;
        }
    }

    return max_depth;
}

ostream& operator<<(ostream& out, const Tree& tree) {
    out << tree.get_value();

    int children_count = tree.get_children_count();
    Tree* children = tree.get_children();

    out << "(";
    for (int i=0; i < children_count; ++i) {
        out << children[i];
        if (i != children_count - 1) {
            cout << ",";
        }
    }
    out << ")";

    return out;
}

Tree* build_tree(int k, int* array, int size) {
    Tree* tree = new Tree(array[0]);

    queue<Tree*> nodes;
    nodes.push(tree);

    Tree* root;
    for (int i = 1; i < size; ++i) {
        if (((i-1) % k) == 0) {
            root = nodes.front();
            nodes.pop();
            cout << "get new root: " << root->get_value() << endl;

        }

        cout << "add child to: " << root->get_value() << " -> " << array[i] << endl;
        nodes.push(root->add_child(array[i]));
    }

    return tree;
}

int main(int argc, char** argv) {

    int size = 10;
    int K = 3;

    int* A = init_array(size);
    print_array(A, size);

    Tree* tree = build_tree(K, A, size);
    cout << *tree << endl;

    cout << "Depth: " << find_depth(tree, 0) << endl;

    return 0;
}