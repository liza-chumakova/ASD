#include <gtest/gtest.h>
#include "../lib_algorithms/ListCycle.h"


//Заяц и черепаха
TEST(ListCycleTurtleAndRabbit, list_without_cycle) {
    List<int> list = {1, 2, 3, 4, 5};

    EXPECT_FALSE(checkListCycleTurtleAndRabbit(list.head()));
    
}

TEST(ListCycleTurtleAndRabbit, list_with_full_cycle) {
    List<int> list = {1, 2, 3, 4, 5};
    list.tail()->_next = list.head();

    EXPECT_TRUE(checkListCycleTurtleAndRabbit(list.head()));
}

TEST(ListCycleTurtleAndRabbit, list_with_middle_cycle) {
    List<int> list = {1, 2, 3, 4, 5};

    Node<int>* middle_node = list.head()->_next->_next; // Узел со значением 3
    list.tail()->_next = middle_node; // 5 -> 3
    
    EXPECT_TRUE(checkListCycleTurtleAndRabbit(list.head()));
}

//Разворот указателей
TEST(ListCyclePointer, list_without_cycle) {
    List<int> list = {1, 2, 3, 4, 5};

    EXPECT_FALSE(checkListCyclePointer(list.head()));
}

TEST(ListCyclePointer, list_with_full_cycle) {
    List<int> list = {1, 2, 3, 4, 5};
    list.tail()->_next = list.head();

    EXPECT_TRUE(checkListCyclePointer(list.head()));
}

TEST(ListCyclePointer, list_with_middle_cycle) {
    List<int> list = {1, 2, 3, 4, 5};

    Node<int>* middle_node = list.head()->_next->_next; // Узел со значением 3
    list.tail()->_next = middle_node; // 5 -> 3
    
    EXPECT_TRUE(checkListCyclePointer(list.head()));
}

//возврат указателя на место поломки (Node* где список зациклился)

TEST(FindCycleEntryTest, list_without_cycle) {
    List<int> list = {1, 2, 3, 4, 5};

    Node<int>* entry_point = FindProblemNode(list.head());

    EXPECT_EQ(entry_point, nullptr);

    EXPECT_FALSE(checkListCycleTurtleAndRabbit(list.head()));
}

TEST(FindCycleEntryTest, list_with_full_cycle) {
    List<int> list = {1, 2, 3, 4, 5};

    list.tail()->_next = list.head();

    Node<int>* entry_point = FindProblemNode(list.head());

    ASSERT_NE(entry_point, nullptr);

    EXPECT_EQ(entry_point, list.tail());
    EXPECT_EQ(entry_point->_value, 5);
    EXPECT_EQ(entry_point->_next, list.head());

    EXPECT_TRUE(checkListCycleTurtleAndRabbit(list.head()));
}

TEST(FindCycleEntryTest, list_with_middle_cycle) {
    List<int> list = {1, 2, 3, 4, 5};

    Node<int>* middle_node = list.head()->_next->_next; // Узел со значением 3
    list.tail()->_next = middle_node; // 5 -> 3

    Node<int>* entry_point = FindProblemNode(list.head());

    ASSERT_NE(entry_point, nullptr);

    EXPECT_EQ(entry_point, list.tail());
    EXPECT_EQ(entry_point->_value, 5);
    EXPECT_EQ(entry_point->_next, middle_node);

    EXPECT_EQ(middle_node->_value, 3);

    EXPECT_TRUE(checkListCycleTurtleAndRabbit(list.head()));
}