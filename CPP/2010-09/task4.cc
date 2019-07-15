#include <iostream>

using namespace std;

class Stack {

private:

    const static int CHUNK = 2;

    int size;
    char* data;
    int top;

public:

    Stack():
    size(CHUNK),
    data(new char[CHUNK]),
    top(-1)
    {}

    ~Stack() {
        delete [] data;
    }

    void push(char value) {
        if (top >= (size-1)) {
            resize();
        }

        data[++top] = value;
    }

    char pop() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return ' ';
        }

        return data[top--];
    }

    char head() {
        if (top < 0) {
            cout << "Stack is empty" << endl;
            return ' ';
        }

        return data[top];
    }

    void resize() {
        cout << "Resize called" << endl;

        char *temp = data;
        data = new char[size + CHUNK];

        for (int i=0; i<size; i++) {
            data[i] = temp[i];
        }

        delete [] temp;
        size += CHUNK;
    }

    bool is_empty() {
        return top == -1;
    }

};

bool validate_brackets_string(string str) {
    Stack stack;

    for (int i=0; i < str.length(); ++i) {
        char current = str[i];

        if (current == '(') {
            stack.push(current);
        }
        else if (current == ')') {
            if (stack.head() == '(') {
                stack.pop();
            }
            else {
                return false;
            }
        }
    }

    return stack.is_empty();
}

int main(int argc, char** argv) {

    // Stack stack = Stack();

    // cout << "PUSH: (" << endl;
    // stack.push('(');
    // cout << "PUSH: )" << endl;
    // stack.push(')');
    // cout << "PUSH: )" << endl;
    // stack.push(')');

    // cout << "POP: " << stack.pop() << endl;
    // cout << "POP: " << stack.pop() << endl;
    // cout << "POP: " << stack.pop() << endl;

    string validInput1 = "((()))";
    string validInput2 = "()()()";
    string validInput3 = "(()())((()()))";

    string invalidInput1 = "((()";
    string invalidInput2 = "(((";
    string invalidInput3 = ")))";
    string invalidInput4 = ")()()(";
    string invalidInput5 = "()())";

    cout << validInput1 << ": " << validate_brackets_string(validInput1) << endl;
    cout << validInput2 << ": " << validate_brackets_string(validInput2) << endl;
    cout << validInput3 << ": " << validate_brackets_string(validInput3) << endl;

    cout << invalidInput1 << ": " << validate_brackets_string(invalidInput1) << endl;
    cout << invalidInput2 << ": " << validate_brackets_string(invalidInput2) << endl;
    cout << invalidInput3 << ": " << validate_brackets_string(invalidInput3) << endl;
    cout << invalidInput4 << ": " << validate_brackets_string(invalidInput4) << endl;
    cout << invalidInput5 << ": " << validate_brackets_string(invalidInput5) << endl;

}