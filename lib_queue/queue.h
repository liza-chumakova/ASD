#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template<typename T>
class Queue {
private:
    T* _data;
    int _head;
    int _count;
    int _size;

public:
    Queue();
    explicit Queue(int size);
    Queue(std::initializer_list<T> init_list);
    Queue(const T* arr, int size);
    Queue(const Queue& other);

    ~Queue();

    inline T* data() const;
    inline int head() const; // это индекс следующего добавляемого элемента
    inline int count() const;
    inline int size() const;

    Queue& operator=(const Queue& other);

    bool operator==(const Queue& other) const;
    bool operator!=(const Queue& other) const;

    T& operator[](int index);
    const T& operator[](int index) const;

    void push(const T& value);
    T pop();
    T& front();

    inline bool is_empty() const;
    inline bool is_full() const;
    void clear();
};

template<typename T>
Queue<T>::Queue() : _data(nullptr), _head(0), _count(0), _size(0) {}

template<typename T>
Queue<T>::Queue(int size) : _data(new T[size]()), _head(0), _count(0), _size(size) {}

template<typename T>
Queue<T>::Queue(std::initializer_list<T> init_list) 
    : _data(new T[init_list.size()]()), _head(0), _count(0), _size(init_list.size()) {
    for (const auto& elem : init_list) {
        push(elem);
    }
}

template<typename T>
Queue<T>::Queue(const T* arr, int size) 
    : _data(new T[size]()), _head(0), _count(0), _size(size) {
    for (int i = 0; i < size; ++i) {
        _data[i] = arr[i];
    }
}

template<typename T>
Queue<T>::Queue(const Queue& other) 
    : _data(new T[other._size]()), _head(other._head), _count(other._count), _size(other._size) {
    std::copy(other._data, other._data + other._size, _data);
    for (int i = 0; i < other.size; ++i) {
        _data[i] = other.data[i];
    }
}

template<typename T>
Queue<T>::~Queue() {
    delete[] _data;
}

template<typename T>
inline T* Queue<T>::data() const {
    return _data;
}

template<typename T>
inline int Queue<T>::head() const {
    return _head;
}

template<typename T>
inline int Queue<T>::count() const {
    return _count;
}

template<typename T>
inline int Queue<T>::size() const {
    return _size;
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other) {
    if (this != &other) {
        delete[] _data;
        _size = other._size;
        _head = other._head;
        _count = other._count;
        _data = new T[_size]();
        for (int i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }
    return *this;
}

template<typename T>
bool Queue<T>::operator==(const Queue& other) const {

    if (_size != other._size || _count != other._count) {
        return false;
    }

    if (_count == 0) {
        return true;
    }

    size_t this_index = (_head - _count + 1 + _size) % _size;
    size_t other_index = (other._head - other._count + 1 + other._size) % other._size;
    
    for (size_t i = 0; i < _count; ++i) {
        if (_data[this_index] != other._data[other_index]) {
            return false;
        }
        this_index = (this_index + 1) % _size;
        other_index = (other_index + 1) % other._size;
    }
    
    return true;
}

template<typename T>
bool Queue<T>::operator!=(const Queue& other) const {
    return !(*this == other);
}

template<typename T>
T& Queue<T>::operator[](int index) {
    if (index >= _count) {
        throw std::out_of_range("Queue index out of range");
    }
    int actual_index = (_head - _count + index + _size) % _size;
    return _data[actual_index];
}

template<typename T>
const T& Queue<T>::operator[](int index) const {
    if (index >= _count) {
        throw std::out_of_range("Queue index out of range");
    }
    int actual_index = (_head - _count + index + _size) % _size;
    return _data[actual_index];
}

template<typename T>
inline bool Queue<T>::is_empty() const {
    return _count == 0;
}

template<typename T>
inline bool Queue<T>::is_full() const {
    return _count == _size;
}

template<typename T>
void Queue<T>::push(const T& value) {
    if (is_full()) {
        throw std::runtime_error("Queue is full");
    }

    _data[_head] = value;
    _head = (_head + 1) % _size;
    _count++;
}

template<typename T>
T Queue<T>::pop() {
    if (is_empty()) {
        throw std::runtime_error("Queue is empty");
    }
    const T item = _data[(_head - _count + _size) % _size];
    _count--;
    //_head = (++_head)%_size;

    return item;
}

template<typename T>
T& Queue<T>::front() {
    if (is_empty()) {
        throw std::runtime_error("Queue is empty");
    }
    //printf(">>>>>>>>>>>>>>. %d\n",(_head - _count + _size) % _size);
    return _data[(_head - _count + _size) % _size];
}

template<typename T>
void Queue<T>::clear() {
    _head = 0;
    _count = 0;
}

#endif // QUEUE_H