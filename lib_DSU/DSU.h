#pragma once
#include <iostream>

class DSU {
protected:
    int* _parent;
    size_t _size;
    int* _rank;

public:
    DSU(size_t size);
    ~DSU();

    inline size_t size() const;

    void unite(int x1, int x2);
    int find(int x);

    bool connected(int x1, int x2);
};