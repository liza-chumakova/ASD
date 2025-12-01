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

DSU::DSU(size_t size) : _size(size) {
    _parent = new int[_size];
    _rank = new int[_size];
    for(size_t i = 0; i < _size; ++i) {
        _parent[i] = i;
        _rank[i] = 0;
    }
}

DSU::~DSU() {
    delete[] _parent;
    delete[] _rank;
}

inline size_t DSU::size() const {
    return _size;
}

void DSU::unite(int x1, int x2) {
    int root1 = find(x1);
    int root2 = find(x2);
    
    if (root1 == root2) return;

    if (_rank[root1] < _rank[root2]) {
        _parent[root1] = root2;
    }
    else if (_rank[root1] > _rank[root2]) {
        _parent[root2] = root1;
    }
    else {
        _parent[root2] = root1;
        _rank[root1]++;
    }
}

int DSU::find(int x) {
    if (_parent[x] != x) {
        _parent[x] = find(_parent[x]);
    }
    return _parent[x];
}

bool DSU::connected(int x1, int x2) {
    return find(x1) == find(x2);
}

//6 тестов 3 на юнайты, 3 на файнды, и чтобы (чтото там) вызывалось