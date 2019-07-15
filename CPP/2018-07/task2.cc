#include <iostream>
#include <iostream>
#include <fstream>
#include <list>
#include <queue>

using namespace std;

class Tree {

    char value;

    Tree** children;
    int children_index;

public:

    Tree() {
        this->value = '*';
        this->children_index = -1;
        this->children = new Tree*[3];
    };

    Tree(char value) {
        this->value = value;
        this->children_index = -1;
        this->children = new Tree*[3];

        for (int i=0; i<3; ++i) {
            this->children[i] = new Tree;
        }
    }

    char get_value() const {
        return value;
    }

    Tree** get_children() const {
        return this->children;
    }

    void add_child(int child_index, char value) {
        if (child_index < 0 || child_index > 2) {
            return;
        }

        Tree* tree = new Tree(value);
        this->children[child_index] = tree;
    }

    Tree* get_child(int child_index) {
        if (child_index < 0 || child_index > 2) {
            return 0;
        }

        return this->children[child_index];
    }

    int get_depth(int depth) {
        if (this->value == '*') {
            return depth;
        }

        int child1_depth = this->children[0]->get_depth(depth + 1);
        int child2_depth = this->children[1]->get_depth(depth + 1);
        int child3_depth = this->children[2]->get_depth(depth + 1);

        return max(child1_depth, max(child2_depth, child3_depth));
    }

};

// (b (x (p * * *) (q * * *) (r (c * * *) * (a * * *))) (y * * (s * (t * * *) *)) *)
ostream& operator<<(ostream& out, const Tree tree) {
    char value = tree.get_value();

    if (value != '*') {
        out << '(';
    }

    out << value;

    if (value != '*') {
        Tree** children = tree.get_children();
        cout << " ";

        for (int i=0; i<3; ++i) {
            out << *children[i];
            if (i != 2) {
                out << " ";
            }
        }
    }

    if (value != '*') {
        out << ')';
    }

    return out;
}

void readLast(Tree* tree) {
    int max_depth = tree->get_depth(0);
    int depth = 0;
    list<Tree*> nodes;
    queue<Tree*> letters;

    nodes.push_front(tree);
    Tree* root;

    while (!nodes.empty()) {
        root = nodes.front();
        nodes.pop_front();

        depth++;
        cout << root->get_value() << "->" << root->get_depth(0) << "(" << depth << ")" << " ";

        if (root->get_depth(0) == 1) {
            if (depth == max_depth) {
                cout << "add ";
                letters.push(root);
                // cout << root->get_value() << " ";
            }
            depth--;
        }

        for (int i=2; i>=0; --i) {
            Tree* child = root->get_child(i);
            if (child->get_value() != '*') {
                nodes.push_front(child);
            }
        }
    }

    cout << endl;
    while (!letters.empty()) {
        cout << letters.front()->get_value() << " ";
        letters.pop();
    }
}

void serialize(Tree tree, char* filename) {
    ofstream file;
    file.open(filename);
    file << tree;
    file.close();
}

int main(int argc, char** argv) {

    Tree* tree = new Tree('b');
    tree->add_child(0, 'x');
    tree->add_child(1, 'y');

    Tree* treeX = tree->get_child(0);
    treeX->add_child(0, 'p');
    treeX->add_child(1, 'q');
    treeX->add_child(2, 'r');

    Tree* treeR = treeX->get_child(2);
    treeR->add_child(0, 'c');
    treeR->add_child(2, 'a');

    Tree* treeY = tree->get_child(1);
    treeY->add_child(2, 's');

    Tree* treeS = treeY->get_child(2);
    treeS->add_child(1, 't');

    cout << *tree << endl;
    cout << "Depth: " << tree->get_depth(0) << endl;
    readLast(tree);

    char* filename = "tree.txt";
    serialize(*tree, filename);

    // (b
    //     (x
    //         (p * * *)
    //         (q * * *)
    //         (r
    //             (c * * *)
    //             *
    //             (a * * *)
    //         )
    //     )
    //     (y
    //         *
    //         *
    //         (s
    //             *
    //             (t * * *)
    //             *
    //         )
    //     )
    //     *
    // )

    return 0;
}