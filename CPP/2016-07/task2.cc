#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int SIZE = 2;

class Tree {

    int root;

    Tree* children;
    int children_count;
    int children_size;

public:

    Tree() {
        root = 0;

        children_count = -1;
        children_size = SIZE;
    }

    Tree(int value):
    root(value) {
        children_count = -1;
        children_size = SIZE;
        children = new Tree[children_size];
    }

    int get_root() const {
        return root;
    }

    void add_child(Tree* tree) {
        if (children_count + 1 >= children_size) {
            Tree* tmp_children = children;

            children_size *= 2;
            children = new Tree[children_size];

            for (int i=0; i <= children_count; i++) {
                children[i] = tmp_children[i];
            }

            delete [] tmp_children;
        }

        children_count++;
        children[children_count] = *tree;
    }

    Tree* get_children() const {
        return children;
    }

    int get_children_count() const {
        return children_count + 1;
    }

};

Tree* build_tree(string input) {
    Tree* tree;

    for (int i=0; i < input.length(); ++i) {
        if (input[i] == '(') {

        }
    }

    return tree;
}

ostream& operator<<(ostream& out, const Tree* tree) {
    out << "(" << tree->get_root() << "(";

    int children_count = tree->get_children_count();
    Tree* children = tree->get_children();

    for (int i=0; i < children_count; ++i) {
        out << children+i;
        if (i != children_count-1) {
            out << ", ";
        }
    }

    out << "))";
    return out;
}

string read_file(const char* filename) {
    ifstream inFile(filename);

    stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    string str = strStream.str(); //str holds the content of the file

    return str;
}

int dfs(Tree* tree, int depth) {
    if (tree->get_children_count() == 0) {
        return depth + tree->get_root();
    }

    int children_count = tree->get_children_count();
    Tree* children = tree->get_children();

    int max_depth = tree->get_root();
    for (int i=0; i < children_count; ++i) {
        int current_depth = dfs(children+i, tree->get_root() + depth);
        if (current_depth > max_depth) {
            max_depth = current_depth;
        }
    }

    return max_depth;
}

int main(int argc, char** argv) {

    // (5(
    //     (9()),
    //     (1(
    //         (4()),
    //         (12()),
    //         (42())
    //     ))
    // )

    Tree* root5 = new Tree(5);
    Tree* leaf9 = new Tree(9);
    Tree* root1 = new Tree(1);
    Tree* leaf4 = new Tree(4);
    Tree* leaf12 = new Tree(12);
    Tree* leaf42 = new Tree(42);

    root1->add_child(leaf4);
    root1->add_child(leaf12);
    root1->add_child(leaf42);

    root5->add_child(leaf9);
    root5->add_child(root1);

    cout << root5 << endl;
    cout << leaf9 << endl;
    cout << root1 << endl;

    cout << dfs(root5, 0) << endl;

    // const char* filename = "tree.txt";
    // string input = read_file(filename);
    // cout << input << endl;
    // Tree* tree = build_tree(input);

    // cout << tree << endl;

    return 0;
}