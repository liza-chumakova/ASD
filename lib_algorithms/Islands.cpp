#include "Islands.h"

#include "../lib_DSU/DSU.h"

IslandCounter::IslandCounter(const TVector<TVector<int>>& grid) 
    : _grid(grid), _rows(grid.size()), _cols(grid.size() > 0 ? grid[0].size() : 0) {}

bool IslandCounter::isValid(int row, int col) const {
    return row >= 0 && row < _rows && col >= 0 && col < _cols;
}

int IslandCounter::flattenIndex(int row, int col) const {
    return row * _cols + col;
}

int IslandCounter::countIslands() {
    if (_rows == 0 || _cols == 0) {
        return 0;
    }

    DSU dsu(_rows * _cols);
    
    // Направления для проверки соседей (только горизонтальные и вертикальные)
    const int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    // Первый проход: объединение соседних ячеек суши
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            if (_grid[i][j] == 1) {
                int currentIndex = flattenIndex(i, j);
                
                // Проверяем всех соседей
                for (int k = 0; k < 4; ++k) {
                    int ni = i + directions[k][0];
                    int nj = j + directions[k][1];
                    
                    if (isValid(ni, nj) && _grid[ni][nj] == 1) {
                        int neighborIndex = flattenIndex(ni, nj);
                        dsu.unite(currentIndex, neighborIndex);
                    }
                }
            }
        }
    }
    
    // Второй проход: подсчет уникальных корней для ячеек суши
    TVector<bool> isRoot(_rows * _cols);
    for (int i = 0; i < isRoot.size(); ++i) {
        isRoot[i] = false;
    }
    
    int islandCount = 0;
    
    for (int i = 0; i < _rows; ++i) {
        for (int j = 0; j < _cols; ++j) {
            if (_grid[i][j] == 1) {
                int index = flattenIndex(i, j);
                int root = dsu.find(index);
                
                if (!isRoot[root]) {
                    isRoot[root] = true;
                    islandCount++;
                }
            }
        }
    }
    
    return islandCount;
}