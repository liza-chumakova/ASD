#include <gtest/gtest.h>
#include "../lib_list/list.h"


TEST(TestList, can_create_default) {
    List<int> list;

    EXPECT_EQ(list.head(), nullptr);
    EXPECT_EQ(list.tail(), nullptr);
    EXPECT_EQ(list.count(), 0);
}

TEST(TestList, can_create_by_init_list) {
    List<int> list{1, 2, 3, 4, 5};
    EXPECT_FALSE(list.is_empty());
    EXPECT_EQ(list.count(), 5);
}

TEST(TestList, can_push_back) {
    List<int> list;

    for (int i = 0; i < 10; ++i) {
        list.push_back(i + 1);
    }
    int exh = (list.head())->_value;
    int ext = (list.tail())->_value;
    int ex_count = list.count();

    EXPECT_EQ(exh, 1);
    EXPECT_EQ(ext, 10);
    EXPECT_EQ(ex_count, 10);
}

TEST(TestList, can_push_front) {
    List<int> list;

    for (int i = 0; i < 10; ++i) {
        list.push_back(i + 1);
    }
    list.push_front(100);
    int exh = (list.head())->_value;
    int ext = (list.tail())->_value;
    int ex_count = list.count();

    EXPECT_EQ(exh, 100);
    EXPECT_EQ(ext, 10);
    EXPECT_EQ(ex_count, 11);
}

TEST(TestList, error_insert) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    
    EXPECT_THROW(list.insert(-1, 10), std::logic_error);
    EXPECT_THROW(list.insert(10, 10), std::logic_error);
}

TEST(TestList, is_front_insert_correct) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.insert(0, 0);
    
    EXPECT_EQ(list.count(), 3);
    EXPECT_EQ((list.head())->_value, 0);
}

TEST(TestList, is_insert_correct) {
     List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.insert(2, 3);
    
    EXPECT_EQ(list.count(), 6);
    int expected_val = 1;

    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected_val);
        expected_val++;
    }
}

TEST(TestList, is_node_insert_correct) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    Node<int>* node = list.head();
    list.insert(node, 10);
    
    EXPECT_EQ(list.count(), 4);
}

TEST(TestList, pop_from_empty_list) {
    List<int> list;
    EXPECT_THROW(list.pop_front(), std::logic_error);
    EXPECT_THROW(list.pop_back(), std::logic_error);
}

TEST(TestList, is_pop_front_correct) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_front();
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ((list.head())->_value, 2);
}

TEST(TestList, is_pop_back_correct) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop_back();
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ((list.tail())->_value, 2);
}

TEST(TestList, is_pop_correct) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop(1);
    
    EXPECT_EQ(list.count(), 2);
}

TEST(TestList, is_pop_from_front_correct) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop(0);
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ((list.head())->_value, 2);
}

TEST(TestList, is_pop_from_back_correct) {
    List<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.pop(2);
    
    EXPECT_EQ(list.count(), 2);
    EXPECT_EQ((list.tail())->_value, 2);
}

TEST(TestList, is_empty) {
    List<int> list;
    EXPECT_TRUE(list.is_empty());
    list.push_back(1);
    EXPECT_FALSE(list.is_empty());
    list.pop_back();
    EXPECT_TRUE(list.is_empty());
}

TEST(TestListIt, can_read) {
    List<int> list;

    for (int i = 0; i < 10; ++i) {
        list.push_back(i + 1);
    }

    int expected_val = 1;

    for (List<int>::Iterator it = list.begin(); it != list.end(); ++it) {
        EXPECT_EQ(*it, expected_val);
        expected_val++;
    }
}

TEST(TestListIt, can_write) {
    //List<int> list = {2, 3, 4, 2, 5, 6, 6, 3, 4, 9};
    List<int> list;
    list.push_back(2);
    list.push_back(3);
    list.push_back(6);
    list.push_back(9);
    list.push_back(0);
    EXPECT_EQ(list.count(), 5);

    int expected_val = 1;
    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
        *it = expected_val++;
    }
    EXPECT_EQ(list.count(), 5);

    expected_val = 1;

    for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
        EXPECT_EQ(*it, expected_val);
        ++expected_val;
    }
    EXPECT_EQ(list.count(), 5);
}

TEST(TestListIt, is_empty_correct) {
    List<int> list;

    int number_of_iterations = 0;

    EXPECT_NO_THROW (
        for (List<int>::Iterator it = list.begin(); it != list.end(); it++) {
            *it = 0;
            ++number_of_iterations;
        }
    );
    EXPECT_EQ(number_of_iterations, 0);
}
