#pragma once
#include "../lib_list/list.h"
#include <iostream>

template <class T> class StackList;

template <class T>
class StackList {
protected:
    List<T> _list;

public:
    StackList(std::initializer_list<T> data);
    
    ~StackList();

    inline int size() const noexcept;
    inline bool is_empty() const noexcept;
    inline T top() const;

    bool operator==(const StackList& other) const;
    bool operator!=(const StackList& other) const;

    void pop();
    void push(const T& value);
    void clear() noexcept;

};

template <typename T>
StackList<T>::StackList(std::initializer_list<T> data)
{
    for (auto it = data.begin(); it != data.end(); ++it) {
        this->push(*it);
    }
}

template <typename T>
StackList<T>::~StackList()
{
}

template <typename T>
inline int StackList<T>::size() const noexcept {
    return _list.count();
}

template <typename T>
inline T StackList<T>::top() const {
    if (_list.is_empty()) {
        throw std::logic_error("Stack is empty");
    }
    return _list.head()->_value;
}

// template <typename T>
// StackList<T>& StackList<T>::operator=(const StackList& other) noexcept
// {
//     if (this != other){
//         delete[] _list;
//         this->size() = other._size;
//         _data = new T[_size];
//         for (int i = 0; i < _size; ++i){
//             _data[i] = other._data[i];
//         }
//         _top = other._top;
//     }
//     return *this;
// }

template <typename T>
bool StackList<T>::operator==(const StackList& other) const {
    return _list == other._list;
}

template <typename T>
bool StackList<T>::operator!=(const StackList& other) const {
    return !(*this == other);
}

template <typename T>
void StackList<T>::pop() {
    if (_list.is_empty()) {
        throw std::logic_error("Stack is empty");
    }
    _list.pop_front();
}

template <typename T>
void StackList<T>::push(const T& value) {
    _list.push_front(value);
}

template <typename T>
inline bool StackList<T>::is_empty() const noexcept {
    return _list.is_empty();
}

template <typename T>
void StackList<T>::clear() noexcept {
    while (!_list.is_empty()) {
        _list.pop_front();
    }
}
