#include "../lib_vector/vector.h"

class IslandCounter {
private:
    TVector<TVector<int>> _grid;
    int _rows;
    int _cols;
    
    bool isValid(int row, int col) const;//в пределах ли матрицы индекс
    int flattenIndex(int row, int col) const;//преобразование индексов в одномерный массив для дсу

public:
    IslandCounter(const TVector<TVector<int>>& grid);
    
    int countIslands();
};