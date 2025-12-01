#include <gtest/gtest.h>
#include "../lib_DSU/DSU.h"

TEST(TestDSU, can_create_default) {
    const size_t SIZE = 5;
    DSU dsu(SIZE);

    for (int i = 0; i < SIZE; ++i) {
        EXPECT_EQ(dsu.find(i), i); //все для себя родители
    }
}

TEST(TestDSU, can_simple_unite) {
    DSU dsu(5);

    dsu.unite(0, 1);
    EXPECT_EQ(dsu.find(0), dsu.find(1));
    EXPECT_TRUE(dsu.connected(0, 1));
    
    //Другое не сондинено
    EXPECT_NE(dsu.find(0), dsu.find(2));
    EXPECT_FALSE(dsu.connected(0, 2));
}

TEST(TestDSU, can_hard_unite) {
    DSU dsu(6);
    
    //{0,1,2} {3,4,5}
    dsu.unite(0, 1);
    dsu.unite(1, 2);
    dsu.unite(3, 4);
    dsu.unite(4, 5);

    EXPECT_TRUE(dsu.connected(0, 2));
    EXPECT_TRUE(dsu.connected(3, 5));
    EXPECT_FALSE(dsu.connected(0, 3));
    EXPECT_FALSE(dsu.connected(2, 4));

    dsu.unite(2, 3);
    EXPECT_TRUE(dsu.connected(0, 5));
    EXPECT_TRUE(dsu.connected(1, 4));
}

TEST(TestDSU, can_find) {
    DSU dsu(10);
    
    // 0->1->2->3->4
    for (int i = 0; i < 4; ++i) {
        dsu.unite(i, i + 1);
    }

    int root = dsu.find(4);

    for (int i = 0; i <= 4; ++i) {
        EXPECT_EQ(dsu.find(i), root);
    }
}

TEST(TestDSU, can_find_same_trees) {
    DSU dsu(6);
    
    //два дерева одинаковой высоты
    dsu.unite(0, 1);
    dsu.unite(0, 2); //дерево с корнем 0
    
    dsu.unite(3, 4);
    dsu.unite(3, 5); // дерево с корнем 3

    dsu.unite(0, 3);

    EXPECT_TRUE(dsu.connected(1, 4));
    EXPECT_TRUE(dsu.connected(2, 5));

    int common_root = dsu.find(0);
    EXPECT_EQ(dsu.find(1), common_root);
    EXPECT_EQ(dsu.find(2), common_root);
    EXPECT_EQ(dsu.find(3), common_root);
    EXPECT_EQ(dsu.find(4), common_root);
    EXPECT_EQ(dsu.find(5), common_root);
}