#include <iostream>

using namespace std;

class ListError {

    const char *const message_;

public:

    ListError(const char *const message=0)
    : message_(message)
    {}

    const char *const get_message() const {
        return message_;
    }

};

class List {

    struct Node {
        Node* next_;
        Node* prev_;
        int data_;

        Node(int value): next_(0), prev_(0), data_(value) {}
    };

    Node* head_;

public:

    List(): head_(new Node(0)) {
        head_->next_ = head_->prev_ = head_;
    }

    ~List() {
        while(!is_empty()) {
            pop_front();
        }

        delete head_;
    }

    bool is_empty() const {
        return head_ == head_->next_;
    }

    void push_front(int value) {
        Node* front = head_->next_;

        Node* ptr = new Node(value);
        head_->next_ = ptr;
        ptr->prev_ = head_;

        front->prev_ = ptr;
        ptr->next_ = front;
    }

    void push_back(int value) {
        Node* back = head_->prev_;

        Node* ptr = new Node(value);
        head_->prev_ = ptr;
        ptr->next_ = head_;

        back->next_ = ptr;
        ptr->prev_ = back;
    }

    int front() const {
        if (is_empty()) {
            throw ListError("front(): list is empty");
        }

        return head_->next_->data_;
    }

    void pop_front() {
        if (is_empty()) {
            throw ListError("pop_front(): list empty...");
        }

        Node* front = head_->next_;
        Node* new_front = front->next_;

        head_->next_ = new_front;
        new_front->prev_ = head_;

        delete front;
    }

    int back() const {
        if (is_empty()) {
            throw ListError("back(): list is empty");
        }

        return head_->prev_->data_;
    }

    void pop_back() {
        if (is_empty()) {
            throw ListError("pop_back(): list empty...");
        }

        Node* back = head_->prev_;
        Node* new_back = back->prev_;

        head_->prev_ = new_back;
        new_back->next_ = head_;

        delete back;
    }

    class iterator {
        friend class List;

        List*  list_;
        Node* current_;

        iterator(const List* l,Node* current)
        : list_(const_cast<List*>(l)),
        current_(current)
        {}
    public:
        bool has_next() const {
            return current_->next_!=list_->head_;
        }

        int next() {
            current_=current_->next_;
            return current_->data_;
        }

        int get_data() const {
            if(current_!=list_->head_) {
                return current_->data_;
            }
            throw ListError("iterator::get_data()...");
        }
    };

};

int main(int argc, char** argv) {
    List list = List();

    cout << "Is Empty: " << list.is_empty() << endl;
    //cout << "Front: " << list.front() << endl;
    //cout << "Back: " << list.back() << endl;

    list.push_front(1);

    cout << "Is Empty: " << list.is_empty() << endl;
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;

    list.push_front(2);
    list.push_back(3);

    cout << "Is Empty: " << list.is_empty() << endl;
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;

    list.pop_front();

    cout << "Is Empty: " << list.is_empty() << endl;
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;

    list.pop_back();

    cout << "Is Empty: " << list.is_empty() << endl;
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;

    list.pop_back();

    cout << "Is Empty: " << list.is_empty() << endl;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);

    for(List::iterator it = list.get_iterator(); it.has_next(); ) {
        cout << it.next() << ", ";
    }
    cout << endl;

    return 0;
}