//--------------------------------------------
// NAME: Valentn Kirilov
// CLASS: XIa
// NUMBER: 6
// PROBLEM: #1
// FILE NAME: list.cc
// FILE PURPOSE:
// Програмата цели да реализира list от стандартната библиотека
//---------------------------------------------


#include <iostream>
#include <stdlib.h>
using namespace std;

class ListException {};

template<class T>
class List
{

private:

    struct Elem {
        T data_;
        Elem* next_;
        Elem* prev_;

        Elem(T val)
        : data_(val),
          next_(0),
          prev_(0)
        {}

        Elem()
        : next_(0),
          prev_(0)
        {}

    };

    Elem* head_;
    Elem* tail_;


public:

    List();
    List(const List& other);
    ~List();
    List& operator=(const List& other);

    void push_back(const T& val);
    void pop_back();
    void push_front(const T& val);
    void pop_front();
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    int size() const;
    bool empty() const;
    void clear();
    void swap(List& other);

    class iterator {

    private:

        friend class List;

        Elem* head_;
        Elem* tail_;
        Elem* current_;

        iterator(Elem* head, Elem* current)
        : current_(current),
          head_(head)
        {}

    public:

        //--------------------------------------------
        // OPERATOR: ++
        // Префиксен оператор за инкрементиране
        // PARAMETERS:
        // -
        //----------------------------------------------
        iterator& operator++() {
            current_ = current_->next_;
            return *this;
        }

        //--------------------------------------------
        // OPERATOR: ++(int)
        // Постфикесн оператор за инкрементиране
        // PARAMETERS:
        // -
        //----------------------------------------------
        iterator operator++(int) {
            iterator res = *this;
            this->operator++();
            return res;
        }

        //--------------------------------------------
        // OPERATOR: ==(const iterator& other)
        // Оператор за проверка за равенстно
        // PARAMETERS:
        // const iterator& other - итератора, с който сравняваме
        //----------------------------------------------
        bool operator==(const iterator& other) const {
            return current_ == other.current_;
        }

        //--------------------------------------------
        // OPERATOR: !=(const iteraor& other)
        // Оператор за проверка за различие
        // PARAMETERS:
        // comst iterator& other - елемента, с който сравняваме
        //----------------------------------------------
        bool operator!=(const iterator& other) const {
            return !operator==(other);
        }

        //--------------------------------------------
        // OPERATOR: *
        // Оператор за указател сочещ към итератора
        // PARAMETERS:
        // -
        //----------------------------------------------
        T& operator*() {
            return current_->data_;
        }

        //--------------------------------------------
        // OPERATOR: ->
        // Оператор за указател сочещ към итератора
        // PARAMETERS:
        // -
        //----------------------------------------------
        iterator operator->() {
            return *current_;
        }

        Elem* next() {
            return current_->next_;
        }

        Elem* prev() {
            return current_->prev_;
        }

        Elem* curr() {
            return current_;
        }

    };

    //--------------------------------------------
    // FUNCTION: begin()
    // Метода връща итератор насочен към първия елемент на списъка
    // PARAMETERS:
    // -
    //----------------------------------------------
    iterator begin() {
        return iterator(head_, head_->next_);
    }

    //--------------------------------------------
    // FUNCTION: end()
    // Метода връща итератор насочен към последния елемент на списъка
    // PARAMETERS:
    // -
    //----------------------------------------------
    iterator end() {
        return iterator(head_, tail_->prev_->next_);
    }

    iterator insert(iterator pos, const T& x) {

        List<T>::iterator it = begin();
        for(; it != pos; ++it)
            ;

        Elem* new_element = new Elem(x);
        Elem* front = it.prev();
        Elem* back = it.curr();

        new_element->next_ = back;
        new_element->prev_ = front;

        front->next_ = new_element;
        back->prev_ = new_element;

        return begin();
    }


    iterator erase(iterator pos) {
        List<T>::iterator it = begin();
        for(; it != pos; ++it)
            ;

        // Delete element
        if(size() > 1) {
            Elem* front = it.prev();
            Elem* back = it.next();

            front->next_ = back;
            back->prev_ = front;

            //it++;
            return it;
        }
        else {
            head_->next_ = tail_;
            head_->prev_ = tail_;

            tail_->next_ = head_;
            tail_->prev_ = head_;

            throw ListException();
        }
    }

    iterator erase(iterator first, iterator last) {
        for(; first != last; ++first)
            erase(first);

        return first;
    }


    class const_iterator {

    private:

        friend class List;

        Elem* head_;
        Elem* tail_;
        Elem* current_;

        const_iterator(Elem* head, Elem* current)
        : current_(current),
          head_(head)
        {}

    public:
        //--------------------------------------------
        // OPERATOR: ++
        // Префиксен оператор за инкрементиране
        // PARAMETERS:
        // -
        //----------------------------------------------
        const_iterator& operator++() {
            current_ = current_->next_;
            return *this;
        }

        //--------------------------------------------
        // OPERATOR: ++(int)
        // Постфикесн оператор за инкрементиране
        // PARAMETERS:
        // -
        //----------------------------------------------
        const_iterator operator++(int) {
            iterator res = *this;
            this->operator++();
            return res;
        }

        //--------------------------------------------
        // OPERATOR: ==(const iterator& other)
        // Оператор за проверка за равенстно
        // PARAMETERS:
        // const iterator& other - итератора, с който сравняваме
        //----------------------------------------------
        bool operator==(const const_iterator& other) const {
            return current_ == other.current_;
        }

        //--------------------------------------------
        // OPERATOR: !=(const iteraor& other)
        // Оператор за проверка за различие
        // PARAMETERS:
        // comst iterator& other - елемента, с който сравняваме
        //----------------------------------------------
        bool operator!=(const const_iterator& other) const {
            return !operator==(other);
        }

        //--------------------------------------------
        // OPERATOR: *
        // Оператор за указател сочещ към итератора
        // PARAMETERS:
        // -
        //----------------------------------------------
        const T& operator*() {
            return current_->data_;
        }

        //--------------------------------------------
        // OPERATOR: ->
        // Оператор за указател сочещ към итератора
        // PARAMETERS:
        // -
        //----------------------------------------------
        const T* operator->() {
            return current_->data_;
        }
    };


    //--------------------------------------------
    // FUNCTION: begin() const
    // Метода връща констанен итератор насочен към първия елемент на списъка. Кностантна функция
    // PARAMETERS:
    // -
    //----------------------------------------------
    const_iterator begin() const {
        return const_iterator(head_, head_->next_);
    }

    //--------------------------------------------
    // FUNCTION: end() const
    // Метода връща константен итератор насочен към последния елемент на списъка. Константна функция
    // PARAMETERS:
    // -
    //----------------------------------------------
    const_iterator end() const {
        return const_iterator(head_, tail_->prev_->next_);
    }


    //////////////////////////////////////////
    ////////////////////////////////////////
    ///////////////////////////////////////////
    ///////////////////////////////////////////
    /////////////////////////////////////////////////

    class reverse_iterator {

    private:

        friend class List;

        Elem* head_;
        Elem* tail_;
        Elem* current_;

        reverse_iterator(Elem* head, Elem* current)
        : current_(current),
          head_(head)
        {}

    public:

        //--------------------------------------------
        // OPERATOR: ++
        // Префиксен оператор за инкрементиране
        // PARAMETERS:
        // -
        //----------------------------------------------
        reverse_iterator& operator++() {
            current_ = current_->prev_;
            return *this;
        }

        //--------------------------------------------
        // OPERATOR: ++(int)
        // Постфикесн оператор за инкрементиране
        // PARAMETERS:
        // -
        //----------------------------------------------
        reverse_iterator operator++(int) {
            reverse_iterator res = *this;
            this->operator++();
            return res;
        }

        //--------------------------------------------
        // OPERATOR: ==(const iterator& other)
        // Оператор за проверка за равенстно
        // PARAMETERS:
        // const iterator& other - итератора, с който сравняваме
        //----------------------------------------------
        bool operator==(const reverse_iterator& other) const {
            return current_ == other.current_;
        }

        //--------------------------------------------
        // OPERATOR: !=(const iteraor& other)
        // Оператор за проверка за различие
        // PARAMETERS:
        // comst iterator& other - елемента, с който сравняваме
        //----------------------------------------------
        bool operator!=(const reverse_iterator& other) const {
            return !operator==(other);
        }

        //--------------------------------------------
        // OPERATOR: *
        // Оператор за указател сочещ към итератора
        // PARAMETERS:
        // -
        //----------------------------------------------
        T& operator*() {
            return current_->data_;
        }

        //--------------------------------------------
        // OPERATOR: ->
        // Оператор за указател сочещ към итератора
        // PARAMETERS:
        // -
        //----------------------------------------------
        T* operator->() {
            return current_->data_;
        }

    };

    //--------------------------------------------
    // FUNCTION: begin()
    // Метода връща итератор насочен към първия елемент на списъка
    // PARAMETERS:
    // -
    //----------------------------------------------
    reverse_iterator rbegin() {
        return reverse_iterator(head_, tail_->prev_);
    }

    //--------------------------------------------
    // FUNCTION: end()
    // Метода връща итератор насочен към последния елемент на списъка
    // PARAMETERS:
    // -
    //----------------------------------------------
    reverse_iterator rend() {
        return reverse_iterator(head_, head_);
    }

    class const_reverse_iterator {

    private:

        friend class List;

        Elem* head_;
        Elem* tail_;
        Elem* current_;

        const_reverse_iterator(Elem* head, Elem* current)
        : current_(current),
          head_(head)
        {}

    public:
        //--------------------------------------------
        // OPERATOR: ++
        // Префиксен оператор за инкрементиране
        // PARAMETERS:
        // -
        //----------------------------------------------
        const_reverse_iterator& operator++() {
            current_ = current_->prev_;
            return *this;
        }

        //--------------------------------------------
        // OPERATOR: ++(int)
        // Постфикесн оператор за инкрементиране
        // PARAMETERS:
        // -
        //----------------------------------------------
        const_reverse_iterator operator++(int) {
            const_reverse_iterator res = *this;
            this->operator++();
            return res;
        }

        //--------------------------------------------
        // OPERATOR: ==(const iterator& other)
        // Оператор за проверка за равенстно
        // PARAMETERS:
        // const iterator& other - итератора, с който сравняваме
        //----------------------------------------------
        bool operator==(const const_reverse_iterator& other) const {
            return current_ == other.current_;
        }

        //--------------------------------------------
        // OPERATOR: !=(const iteraor& other)
        // Оператор за проверка за различие
        // PARAMETERS:
        // comst iterator& other - елемента, с който сравняваме
        //----------------------------------------------
        bool operator!=(const const_reverse_iterator& other) const {
            return !operator==(other);
        }

        //--------------------------------------------
        // OPERATOR: *
        // Оператор за указател сочещ към итератора
        // PARAMETERS:
        // -
        //----------------------------------------------
        const T& operator*() {
            return current_->data_;
        }

        //--------------------------------------------
        // OPERATOR: ->
        // Оператор за указател сочещ към итератора
        // PARAMETERS:
        // -
        //----------------------------------------------
        const T* operator->() {
            return current_->data_;
        }
    };


    //--------------------------------------------
    // FUNCTION: begin() const
    // Метода връща констанен итератор насочен към първия елемент на списъка. Кностантна функция
    // PARAMETERS:
    // -
    //----------------------------------------------
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(head_, tail_->prev_);
    }

    //--------------------------------------------
    // FUNCTION: end() const
    // Метода връща константен итератор насочен към последния елемент на списъка. Константна функция
    // PARAMETERS:
    // -
    //----------------------------------------------
    const_reverse_iterator rend() const {
        return const_reverse_iterator(head_, head_);
    }


};

//--------------------------------------------
// CONSTRUCTOR: List()
// Коструктор на класа
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
List<T>::List()
: head_(new Elem()),
  tail_(new Elem())
{
    head_->next_ = tail_;
    head_->prev_ = tail_;

    tail_->next_ = head_;
    tail_->prev_ = head_;
}

//--------------------------------------------
// CONSTRUCTOR: List(const List& other)
// Копиращ коструктор на класа
// PARAMETERS:
// const List& other - листа, чието копие създаваме с този консруктор
//----------------------------------------------
template<class T>
List<T>::List(const List& other)
: head_(new Elem()),
  tail_(new Elem())
{
    head_->next_ = tail_;
    head_->prev_ = tail_;

    tail_->next_ = head_;
    tail_->prev_ = head_;

    List<T>::const_iterator it = other.begin();
    for(; it != other.end(); ++it)
    {
        int val = (*it);
        push_back(val);
    }
}

//--------------------------------------------
// OPERATOR: =(const List& other)
// Оператор за присвояване
// PARAMETERS:
// const List& other - списъкът, който ще присвоим към нашия обект
//----------------------------------------------
template<class T>
List<T>& List<T>::operator=(const List& other) {
    if (this != &other ) {
        while(!empty())
            pop_back();

        List<T>::iterator it = other.begin();
        for(; it != other.end(); ++it)
        {
            int val = (*it);
            push_back(val);
        }
    }

    return *this ;
}

//--------------------------------------------
// DESTRUCTOR: ~List()
// Деструктор на класа
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
List<T>::~List()
{
    while(!empty())
    {
        pop_back();
    }

    delete head_;
    delete tail_;
}

//--------------------------------------------
// FUNCTION: empty()
// Метода проверява дали листа е празен
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
bool List<T>::empty() const
{
    return size() == 0;
}

//--------------------------------------------
// FUNCTION: clear()
// Метода изтрива елементите на списъка
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
void List<T>::clear()
{
    while(!empty())
        pop_back();
}

//--------------------------------------------
// FUNCTION: swap(List& other)
// Метода разменя елементите на два списъка
// PARAMETERS:
// List& other - списъка, чиито елементи трябва да се разменят
//----------------------------------------------
template<class T>
void List<T>::swap(List& other)
{
    List<T> lh;

    // Add to helper from other
    while(!other.empty()) {
        T other_val = other.back();
        lh.push_front(other_val);
        other.pop_back();
    }

    // Add to other from this
    while(!empty()) {
        T this_val = back();
        other.push_front(this_val);
        pop_back();
    }

    // Add to this from helper
    while(!lh.empty()) {
        T helper_val = lh.back();
        push_front(helper_val);
        lh.pop_back();
    }
}

//--------------------------------------------
// FUNCTION: push_front(const T& val)
// Метода добавя елемент в началото на списъка
// PARAMETERS:
// const T& val - стойността на добавяния елемент
//----------------------------------------------
template<class T>
void List<T>::push_front(const T& val)
{
    Elem* new_node = new Elem(val);

    new_node->next_ = head_->next_;
    head_->next_->prev_ = new_node;

    head_->next_ = new_node;
    new_node->prev_ = head_;
}

//--------------------------------------------
// FUNCTION: push_back(const T& val)
// Метода добавя елемент в края на списъка
// PARAMETERS:
// const T& val - стойността на добавяния елемент
//----------------------------------------------
template<class T>
void List<T>::push_back(const T& val)
{
    Elem* new_node = new Elem(val);

    new_node->next_ = tail_;
    new_node->prev_ = tail_->prev_;

    tail_->prev_->next_ = new_node;
    tail_->prev_ = new_node;
}

// FUNCTION: pop_front()
// Метода изтрива елемент от началото на списъка
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
void List<T>::pop_front()
{
    if(empty())
    {
        throw ListException();
    }

    Elem* front = head_->next_;

    head_->next_ = front->next_;
    front->next_->prev_ = head_;

    delete(front);
}

//--------------------------------------------
// FUNCTION: pop_back()
// Метода изтрива елемент от края на списъка
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
void List<T>::pop_back()
{
    if(empty())
    {
        throw ListException();
    }

    Elem* back = tail_->prev_;

    tail_->prev_ = back->prev_;
    back->prev_->next_ = tail_;
    delete(back);
}

//--------------------------------------------
// FUNCTION: front()
// Метода връща стойността на елемента в началото на списъка
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
T& List<T>::front()
{
    if (empty())
    {
        throw ListException();
    }

    return head_->next_->data_;
}

//--------------------------------------------
// FUNCTION: front() const
// Метода връща стойността на елемента в началото на списъка. Константен метод
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
const T& List<T>::front() const
{
    if (empty())
    {
        throw ListException();
    }

    return head_->next_->data_;
}

//--------------------------------------------
// FUNCTION: back()
// Метода връща стойността на елемента в края на списъка
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
T& List<T>::back()
{
    if (empty())
    {
        throw ListException();
    }

    return tail_->prev_->data_;
}

//--------------------------------------------
// FUNCTION: back() const
// Метода връща стойността на елемента в края на списъка. Констанет метод.
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
const T& List<T>::back() const
{
    if (empty())
    {
        throw ListException();
    }

    return tail_->prev_->data_;
}

//--------------------------------------------
// FUNCTION: size()
// Метода връща броя на елементите в списъка
// PARAMETERS:
// -
//----------------------------------------------
template<class T>
int List<T>::size() const
{
    int size = 0;
    List<T>::const_iterator it = this->begin();
    for(; it != this->end(); ++it)
        size++;

    return size;
}

void print_list(List<int> list)
{
    List<int>::iterator it = list.begin();
    for(; it != list.end(); ++it)
        cout << (*it) << ",";
    cout << endl;
}

int main(int argc, char* argv[])
{
    List<int> l1;
    List<int> l2;

    int from = atoi(argv[1]);
    int to = atoi(argv[2]);
    for(int first_counter = from; first_counter < to; first_counter++) {
        l1.push_back(first_counter);
    }

    from = atoi(argv[3]);
    to = atoi(argv[4]);
    for(int second_counter = from; second_counter < to; second_counter++)
        l2.push_back(second_counter);

    cout << "l1: ";
    print_list(l1);

    cout << "l2: ";
    print_list(l2);
    cout << endl;

    int equal_elements = 0;
    List<int>::iterator it1 = l1.begin();
    List<int>::iterator it2 = l2.begin();
    for(; it1 != l1.end(); ++it1)
    {
        it2 = l2.begin();
        for(; it2 != l2.end(); ++it2)
        {
            if((*it1) == (*it2)) {
                equal_elements++;
                break;
            }
        }

    }
    cout << "equal elemets in l1 and l2: " << equal_elements  << endl;
    l1.push_back(-100);
    l2.push_back(-100);

    cout << "l1: ";
    print_list(l1);

    cout << "l2: ";
    print_list(l2);
    cout << endl;

    List<int> l(l2);
    cout << "l: ";
    print_list(l);

    List<int>::reverse_iterator rit = l1.rbegin();
    for (; rit != l1.rend(); ++rit) {
        int val = (*rit);
        l.push_front(val);
    }
    cout << "l: ";
    print_list(l);
    cout << endl;

    List<int>::iterator bitl = l.begin();
    List<int>::iterator bit = l.begin();

    for(; bitl != l.end(); ++bitl) {
        if((*bitl) == -100) {
            bit = bitl;
            break;
        }
    }
    l.erase(bit, l.end());
    cout << "l: ";
    print_list(l);
    cout << endl;



    return 0;
}