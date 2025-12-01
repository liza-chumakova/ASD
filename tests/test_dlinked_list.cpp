#include <gtest/gtest.h>
#include "../lib_dlinked_list/dlinked_list.h"

TEST(TestDLinkedList, can_create_default) {
    DLinkedList<int> list;

    EXPECT_EQ(list.head(), nullptr);
    EXPECT_EQ(list.tail(), nullptr);
    EXPECT_EQ(list.count(), 0);
    EXPECT_TRUE(list.is_empty());
}

TEST(TestDLinkedList, can_create_by_init_list) {
    DLinkedList<int> list{1, 2, 3, 4, 5};
    
    EXPECT_FALSE(list.is_empty());
    EXPECT_EQ(list.count(), 5);
    EXPECT_EQ(list.head()->_value, 1);
    EXPECT_EQ(list.tail()->_value, 5);
}

TEST(TestDLinkedList, can_push_back) {
    DLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.push_back(i + 1);
    }

    EXPECT_EQ((list.head())->_value, 1);
    EXPECT_EQ((list.tail())->_value, 10);
    EXPECT_EQ(list.count(), 10);
}

TEST(TestDLinkedList, can_push_front) {
    DLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.push_back(i + 1);
    }
    list.push_front(100);

    EXPECT_EQ((list.head())->_value, 100);
    EXPECT_EQ((list.tail())->_value, 10);
    EXPECT_EQ(list.count(), 11);
}

TEST(TestDLinkedList, error_insert) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    
    EXPECT_THROW(list.insert(-1, 10), std::logic_error);
    EXPECT_THROW(list.insert(10, 10), std::logic_error);
}

TEST(TestDLinkedList, is_front_insert_correct) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.insert(0, 0);
    
    EXPECT_EQ(list.count(), 3);
    EXPECT_EQ((list.head())->_value, 0);
}

TEST(TestDLinkedList, is_insert_correct) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.insert(2, 3);
    
    EXPECT_EQ(list.count(), 6);
    int expected_val = 1;

    for (DLinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected_val);
        expected_val++;
    }
}

TEST(TestDLinkedList, is_node_insert_correct) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    Node<int>* node = list.head()->_next;
    list.insert(node, 10);
    
    EXPECT_EQ(list.count(), 4);
    EXPECT_EQ(node->_prev->_value, 10);
}

TEST(TestDLinkedList, pop_from_empty_list) {
    DLinkedList<int> list;
    EXPECT_THROW(list.pop_front(), std::logic_error);
    EXPECT_THROW(list.pop_back(), std::logic_error);
}

TEST(TestDLinkedList, is_pop_front_correct) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ((list.head())->_value, 2);
    EXPECT_EQ((list.head())->_prev, nullptr);
}

TEST(TestDLinkedList, is_pop_back_correct) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ((list.tail())->_value, 2);
    EXPECT_EQ((list.tail())->_next, nullptr);
}

TEST(TestDLinkedList, is_pop_correct) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop(1);
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ(list.head()->_next, list.tail());
    EXPECT_EQ(list.tail()->_prev, list.head());
}

TEST(TestDLinkedList, is_pop_from_front_correct) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop(0);
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ((list.head())->_value, 2);
    EXPECT_EQ((list.head())->_prev, nullptr);
}

TEST(TestDLinkedList, is_pop_from_back_correct) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop(2);
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ((list.tail())->_value, 2);
    EXPECT_EQ((list.tail())->_next, nullptr);
}

TEST(TestDLinkedList, is_pop_node_correct) {
    DLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    Node<int>* node = list.head()->_next;
    list.pop(node);
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ(list.head()->_next, list.tail());
    EXPECT_EQ(list.tail()->_prev, list.head());
}

TEST(TestDLinkedList, is_empty) {
    DLinkedList<int> list;
    EXPECT_TRUE(list.is_empty());
    list.push_back(1);
    EXPECT_FALSE(list.is_empty());
    list.pop_back();
    EXPECT_TRUE(list.is_empty());
}

TEST(TestDLinkedListIt, can_read) {
    DLinkedList<int> list;

    for (int i = 0; i < 10; ++i) {
        list.push_back(i + 1);
    }

    int expected_val = 1;

    for (DLinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected_val);
        expected_val++;
    }
}

TEST(TestDLinkedListIt, can_write) {
    DLinkedList<int> list;
    list.push_back(2);
    list.push_back(3);
    list.push_back(6);
    list.push_back(9);
    list.push_back(0);
    EXPECT_EQ(list.count(), 5);

    int expected_val = 1;
    for (DLinkedList<int>::Iterator it = list.begin(); it != list.end(); it++) {
        *it = expected_val++;
    }
    EXPECT_EQ(list.count(), 5);

    expected_val = 1;

    for (DLinkedList<int>::Iterator it = list.begin(); it != list.end(); it++) {
        EXPECT_EQ(*it, expected_val);
        ++expected_val;
    }
    EXPECT_EQ(list.count(), 5);
}

TEST(TestDLinkedListIt, is_empty_correct) {
    DLinkedList<int> list;

    int number_of_iterations = 0;

    EXPECT_NO_THROW (
        for (DLinkedList<int>::Iterator it = list.begin(); it != list.end(); it++) {
            *it = 0;
            ++number_of_iterations;
        }
    );
    EXPECT_EQ(number_of_iterations, 0);
}

TEST(TestDLinkedListIt, is_reiterator_correct) {
    DLinkedList<int> list{1, 2, 3, 4, 5};
    
    DLinkedList<int>::Iterator it = list.begin();
    ++it;
    EXPECT_EQ(*it, 2);
    
    --it;
    EXPECT_EQ(*it, 1);
    
    ++it; ++it;
    EXPECT_EQ(*it, 3);
    
    --it;
    EXPECT_EQ(*it, 2);
}