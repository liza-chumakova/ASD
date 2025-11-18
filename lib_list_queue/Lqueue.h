#ifndef LQUEUE_H
#define LQUEUE_H

#include "../lib_list/list.h"

#include <iostream>

template<typename T>
class QueueList {
private:
    List<T> _list;

public:
    QueueList(std::initializer_list<T> data);

    ~QueueList();

    bool operator==(const QueueList& other) const;
    bool operator!=(const QueueList& other) const;

    void push(const T& value);
    T pop();

    inline T& front() const;
    inline T& back() const;

    inline int count() const noexcept;
    inline bool is_empty() const noexcept;
    void clear() noexcept;
};

template <typename T>
QueueList<T>::QueueList(std::initializer_list<T> data) {
    for (const auto& it : data) {
        this->push(it);
    }
}

template<typename T>
QueueList<T>::~QueueList() {
}

template <typename T>
inline T& QueueList<T>::front() const {
    if (_list.is_empty()) {
        throw std::logic_error("Queue is empty");
    }
    return _list.head()->_value;
}

template <typename T>
inline T& QueueList<T>::back() const {
    if (_list.is_empty()) {
        throw std::logic_error("Queue is empty");
    }
    return _list.tail()->_value;
}

template <typename T>
bool QueueList<T>::operator==(const QueueList& other) const {
    return _list == other._list;
}

template <typename T>
bool QueueList<T>::operator!=(const QueueList& other) const {
    return !(*this == other);
}

template <typename T>
void QueueList<T>::push(const T& value) {
    _list.push_back(value);
}

template <typename T>
T QueueList<T>::pop() {
    if (_list.is_empty()) {
        throw std::logic_error("Queue is empty");
    }
    
    T value = _list.head()->_value;
    _list.pop_front();
    return value;
}

template <typename T>
inline int QueueList<T>::count() const noexcept {
    return _list.count();
}

template <typename T>
inline bool QueueList<T>::is_empty() const noexcept {
    return _list.is_empty();
}

template <typename T>
void QueueList<T>::clear() noexcept {
    while (!_list.is_empty()) {
        _list.pop_front();
    }
}

#endif // LQUEUE_H