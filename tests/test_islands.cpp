#include <gtest/gtest.h>
#include "../lib_algorithms/Islands.h"
//#include "../lib_vector/vector.h"

// Тест пустой матрицы
TEST(IslandCounterTest, EmptyGrid) {
    TVector<TVector<int>> empty_grid;
    IslandCounter counter(empty_grid);
    EXPECT_EQ(counter.countIslands(), 0);
}

// Тест матрицы с нулевыми размерами
TEST(IslandCounterTest, ZeroSizeGrid) {
    TVector<TVector<int>> zero_grid(0);
    IslandCounter counter(zero_grid);
    EXPECT_EQ(counter.countIslands(), 0);
}

// Тест только воды (все нули)
TEST(IslandCounterTest, AllWater) {
    TVector<TVector<int>> water_grid(3);
    water_grid[0] = TVector<int>({0, 0, 0});
    water_grid[1] = TVector<int>({0, 0, 0});
    water_grid[2] = TVector<int>({0, 0, 0});
    
    IslandCounter counter(water_grid);
    EXPECT_EQ(counter.countIslands(), 0);
}

// Тест только суши (все единицы)
TEST(IslandCounterTest, AllLand) {
    TVector<TVector<int>> land_grid(2);
    land_grid[0] = TVector<int>({1, 1});
    land_grid[1] = TVector<int>({1, 1});
    
    IslandCounter counter(land_grid);
    EXPECT_EQ(counter.countIslands(), 1);
}

// Тест одного острова
TEST(IslandCounterTest, SingleIsland) {
    TVector<TVector<int>> grid(3);
    grid[0] = TVector<int>({1, 1, 0});
    grid[1] = TVector<int>({0, 1, 0});
    grid[2] = TVector<int>({0, 0, 0});
    
    IslandCounter counter(grid);
    EXPECT_EQ(counter.countIslands(), 1);
}

// Тест нескольких разделенных островов
TEST(IslandCounterTest, MultipleSeparatedIslands) {
    TVector<TVector<int>> grid(3);
    grid[0] = TVector<int>({1, 0, 1});
    grid[1] = TVector<int>({0, 0, 0});
    grid[2] = TVector<int>({1, 0, 1});
    
    IslandCounter counter(grid);
    EXPECT_EQ(counter.countIslands(), 4);
}

// Тест из условия задачи
TEST(IslandCounterTest, GivenExample) {
    TVector<TVector<int>> grid(5);
    grid[0] = TVector<int>({0, 1, 0, 0, 1});
    grid[1] = TVector<int>({0, 1, 1, 0, 1});
    grid[2] = TVector<int>({1, 1, 0, 1, 1});
    grid[3] = TVector<int>({0, 0, 0, 0, 1});
    grid[4] = TVector<int>({1, 0, 1, 1, 1});
    
    IslandCounter counter(grid);
    EXPECT_EQ(counter.countIslands(), 3);
}

// Тест сложной формы островов
TEST(IslandCounterTest, ComplexShapes) {
    TVector<TVector<int>> grid(4);
    grid[0] = TVector<int>({1, 1, 0, 0, 0});
    grid[1] = TVector<int>({1, 1, 0, 0, 0});
    grid[2] = TVector<int>({0, 0, 1, 0, 0});
    grid[3] = TVector<int>({0, 0, 0, 1, 1});
    
    IslandCounter counter(grid);
    EXPECT_EQ(counter.countIslands(), 3);
}

// Тест что диагональные касания не объединяются
TEST(IslandCounterTest, DiagonalNotConnected) {
    TVector<TVector<int>> grid(3);
    grid[0] = TVector<int>({1, 0, 1});
    grid[1] = TVector<int>({0, 1, 0});
    grid[2] = TVector<int>({1, 0, 1});
    
    IslandCounter counter(grid);
    // Диагональные единицы не должны объединяться
    EXPECT_EQ(counter.countIslands(), 5);
}

// Тест одного острова сложной формы
TEST(IslandCounterTest, SingleComplexIsland) {
    TVector<TVector<int>> grid(4);
    grid[0] = TVector<int>({1, 0, 1, 0});
    grid[1] = TVector<int>({1, 1, 1, 0});
    grid[2] = TVector<int>({0, 1, 1, 1});
    grid[3] = TVector<int>({0, 0, 1, 1});
    
    IslandCounter counter(grid);
    EXPECT_EQ(counter.countIslands(), 1);
}

// Тест граничных случаев с одним рядом
TEST(IslandCounterTest, SingleRow) {
    TVector<TVector<int>> grid(1);
    grid[0] = TVector<int>({1, 0, 1, 1, 0, 1});
    
    IslandCounter counter(grid);
    EXPECT_EQ(counter.countIslands(), 3);
}

// Тест граничных случаев с одним столбцом
TEST(IslandCounterTest, SingleColumn) {
    TVector<TVector<int>> grid(4);
    grid[0] = TVector<int>({1});
    grid[1] = TVector<int>({0});
    grid[2] = TVector<int>({1});
    grid[3] = TVector<int>({1});
    
    IslandCounter counter(grid);
    EXPECT_EQ(counter.countIslands(), 2);
}