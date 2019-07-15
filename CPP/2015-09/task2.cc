#include <iostream>

using namespace std;

const int SIZE = 1000;

class G {
    int* v;
    int v_top;
    int v_size;

    bool e[SIZE][SIZE];

public:
    G() {
        v_top = -1;
        v_size = 2;
        v = new int[v_size];

        for (int i=0; i < SIZE; i++) {
            for (int j=0; j < SIZE; j++) {
                e[i][j] = false;
            }
        }
    }

    void add_v(int value) {
        // cout << "Add " << value << "; top: " << v_top << "; size: " << v_size << endl;
        if (v_top + 1 >= v_size) {
            int* v_tmp = v;
            v_size *= 2;
            v = new int[v_size];

            for (int i=0; i <= v_top; i++) {
                v[i] = v_tmp[i];
            }

            delete [] v_tmp;
        }


        v_top++;
        v[v_top] = value;
    }

    void add_e(int v1, int v2) {
        e[v1][v2] = true;
    }

    void print_v() {
        cout << "V: ";
        for (int i=0; i <= v_top; ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

    void print_e() {
        for (int i=0; i < SIZE; ++i) {
            for (int j=0; j < SIZE; ++j) {
                if (e[i][j]) {
                    cout << i << " -> " << v[i] << endl;
                }
            }
        }
    }

    bool find_path(int v1, int v2) {
        if (e[v1][v2]) {
            return true;
        }

        for (int i=0; i < SIZE; i++) {
            if (e[v1][i]) {
                return find_path(v1, i);
            }
        }

        return false;
    }

    bool is_connected() {
        for (int i=0; i < v_top; ++i) {
            for (int j=i+1; j < v_top; ++j) {
                if (!find_path(v[i], v[j]) && !find_path(v[i], v[j])) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {

    G g1;

    g1.add_v(1);
    g1.add_v(2);
    g1.add_v(3);

    g1.add_e(1, 2);
    g1.add_e(2, 3);

    cout << "G1" << endl;
    g1.print_v();
    g1.print_e();
    cout << "is_connected: " << g1.is_connected() << endl;

    G g2;

    g2.add_v(1);
    g2.add_v(2);
    g2.add_v(3);

    g2.add_e(2, 1);
    g2.add_e(2, 3);

    cout << "G2" << endl;
    g2.print_v();
    g2.print_e();
    cout << "is_connected: " << g2.is_connected() << endl;

    G g3;

    g3.add_v(1);
    g3.add_v(2);
    g3.add_v(3);
    g3.add_v(4);
    g3.add_v(5);

    g3.add_e(1, 2);
    g3.add_e(2, 3);
    g3.add_e(3, 4);
    g3.add_e(4, 3);
    g3.add_e(4, 5);

    cout << "G3" << endl;
    g3.print_v();
    g3.print_e();
    cout << "is_connected: " << g3.is_connected() << endl;

    return 0;
}