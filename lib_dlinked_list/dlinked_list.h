#pragma once
#include <iostream>

template <typename T>
struct Node {
    T _value;
    Node<T>* _next;
    Node<T>* _prev;
    Node(T value, Node<T>* next = nullptr, Node<T>* prev = nullptr):
        _value(value), _next(next), _prev(prev) {}
};

template <typename T> class DLinkedList;

template <class T>
class DLinkedList {
    Node<T>* _head;
    Node<T>* _tail;
    int _count;

public:
    DLinkedList();
    DLinkedList(const DLinkedList<T>& other) = delete;
    DLinkedList(std::initializer_list<T> data);

    Node<T>* head() const;
    Node<T>* tail() const;
    int count() const;

    DLinkedList<T>& operator=(const DLinkedList<T>& other);

    bool operator==(const DLinkedList& other) const;

    void push_front(const T& val) noexcept;
    void push_back(const T& val) noexcept;
    void insert(int pos, const T& val);
    void insert(Node<T>* node, const T& val);

    void pop_front();
    void pop_back();
    void pop(int pos);
    void pop(Node<T>* node);

    bool is_empty() const;

    Node<T>* find(const T& val);

    class Iterator {
        Node<T>* _current;
    public:
        Iterator() : _current(nullptr) {}
        Iterator(Node<T>* pos) : _current(pos) {}
        Iterator(const Iterator& other) : _current(other._current) {}

        Iterator& operator=(const Iterator& other);
        T& operator*();

        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

        Iterator operator++(int); //x++
        Iterator& operator++();   //++x

        Iterator operator--(int); // x--
        Iterator& operator--();   // --x
    };

    Iterator begin() { return Iterator(_head); }
    Iterator end() {return Iterator(nullptr); }
};

template <class T>
DLinkedList<T>::DLinkedList() : _head(nullptr), _tail(nullptr), _count(0) {}

template <typename T>
DLinkedList<T>::DLinkedList(std::initializer_list<T> data) :
    _head(nullptr), _tail(nullptr), _count(0) {
    // std::initializer_list<T>::const_iterator it;
    for (auto it = data.begin(); it != data.end(); ++it) {
        this->push_back(*it);
    }
}

template <typename T>
Node<T>* DLinkedList<T>::head() const {
    return _head;
}

template <typename T>
Node<T>* DLinkedList<T>::tail() const {
    return _tail;
}

template <typename T>
int DLinkedList<T>::count() const {
    return _count;
}

template <typename T>
DLinkedList<T>& DLinkedList<T>::operator=(const DLinkedList<T>& other) {
    while (!is_empty()) {
        pop_front();
    }

    Node<T>* cur = other.head();
    while (cur != nullptr) {
        push_back(cur->value);
        cur = cur->next;
    }

    return *this;
}

template <typename T>
bool DLinkedList<T>::operator==(const DLinkedList& other) const {
    if(_count != other._count) { return false; }

    Node<T>* cur = _head;
    Node<T>* cur_other = other._head;
    while (cur != nullptr) {
        if (cur->value != cur_other->value) { return false; }
        //допроверка
        cur = cur->next;
        cur_other = cur_other->next;
    }

    return true;
}

template <typename T>
void DLinkedList<T>::push_front(const T& val) noexcept {
    Node<T>* node = new Node<T>(val, _head, nullptr);

    if(is_empty()) {
        _tail = node;
    }
    else {
        _head->_prev = node;
    }

    _head = node;
    ++_count;
}

template <typename T>
void DLinkedList<T>::push_back(const T& val) noexcept {
    Node<T>* const node = new Node<T>(val, nullptr, _tail);

    if(is_empty()) {
        _head = node;
        _tail = node;
        _count = 1;
        return;
    }

    _tail->_next = node;
    _tail = node;
    ++_count;
}

template <typename T>
void DLinkedList<T>::insert(int pos, const T& val) {
    if(pos < 0 || pos >= _count) {
        throw std::logic_error("Index out of range");
    }
    if(pos == 0) {
        push_front(val);
    }
    else if(pos == _count - 1) {
        push_back(val);
    }
    else {
        Node<T>* cur = _head;
        for (int i = 0; i < pos; ++i) {
            cur = cur->_next;
        }
    
        Node<T>* new_node = new Node<T>(val, cur, cur->_prev);
        cur->_prev->_next = new_node;
        cur->_prev = new_node;
        ++_count;
    }
}

template <typename T>
void DLinkedList<T>::insert(Node<T>* node, const T& val) {
    
    if (node == nullptr) {
        throw std::logic_error("Node error");
    }

    if (node == _head) {
        push_front(val);
        return;
    }
    
    Node<T>* new_node = new Node<T>(val, node, node->_prev);
    node->_prev->_next = new_node;
    node->_prev = new_node;
    ++_count;
}

template <typename T>
void DLinkedList<T>::pop_front() {
    if(is_empty()) {
        throw std::logic_error("DLinkedList is empty");
    }

    Node<T>* pr_node = _head;
    _head = _head->_next;

    if(_head != nullptr) {
        _head->_prev = nullptr;
    }
    else {
        _tail = nullptr;
    }
    delete pr_node;
    --_count;
}

template <typename T>
void DLinkedList<T>::pop_back() {
    if(is_empty()) {
        throw std::logic_error("DLinkedList is empty");
    }
    if(_count == 1) {
        pop_front();
    }
    // Node<T>* cur = _head;
    // int cur_pos = 0;
    // while (cur_pos < _count - 2) {
    //     if (cur_pos == _count - 1) {
    //         break;
    //     }
    //     ++cur_pos;
    //     cur = cur->_next;
    // }
    // Node<T>* pr_node = _tail;
    // cur->_next = nullptr;
    // _tail = cur;
    // delete pr_node;
    // --_count;
    else {
        Node<T>* temp = _tail;
        _tail = _tail->_prev;
        _tail->_next = nullptr;
        delete temp;
        --_count;
    }
}

template <typename T>
void DLinkedList<T>::pop(int pos) {
    if(pos < 0 || pos >= _count) {
        throw std::logic_error("Index out of range");
    }
    if(pos == 0) {
        pop_front();
    }
    else if(pos == _count - 1) {
        pop_back();
    }
    else {
        Node<T>* cur = _head;
        for (int i = 0; i < pos; ++i) {
            cur = cur->_next;
        }
    
        pop(cur);
    }
}

template <typename T>
void DLinkedList<T>::pop(Node<T>* node) {
    if (node == nullptr) {
        throw std::logic_error("Node error");
    }

    if (node == _head) {
        pop_front();
    }
    
    else if (node == _tail) {
        pop_back();
    }

    else {
        node->_prev->_next = node->_next;
        node->_next->_prev = node->_prev;
        delete node;
        --_count;
    }
}

template <typename T>
bool DLinkedList<T>::is_empty() const {
    return _head == nullptr;
}

template <typename T>
Node<T>* DLinkedList<T>::find(const T& val) {
    Node<T>* cur = _head;
    while (cur != nullptr) {
        if (cur->_value == val) {
            return cur;
        }
        cur = cur->_next;
    }
    return nullptr;
}

//CLASS ITERATOR
template <typename T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const Iterator& other) {
    this->_current = other._current;
    return *this;
}

template <typename T>
T& DLinkedList<T>::Iterator::operator*() {
    return _current->_value;
}

template <typename T>
bool DLinkedList<T>::Iterator::operator==(const Iterator& other) const {
    return _current == other._current;
}

template <typename T>
bool DLinkedList<T>::Iterator::operator!=(const Iterator& other) const {
    return _current != other._current;
}

template <typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) {
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() {
    if(_current != nullptr) {
        _current = _current->_next;
    }
    return *this;
}

template <typename T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator--(int) {
    Iterator temp = *this;
    --(*this);
    return temp;
}

template <typename T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator--() {
    if (_current != nullptr) {
        _current = _current->_prev;
    }
    return *this;
}