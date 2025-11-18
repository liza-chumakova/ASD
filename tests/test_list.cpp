#include <gtest/gtest.h>
#include "../lib_list/list.h"


TEST(TestList, can_create_default) {
    List<int> list;

    EXPECT_EQ(list.head(), nullptr);
    EXPECT_EQ(list.tail(), nullptr);
    EXPECT_EQ(list.count(), 0);
}

TEST(TestList, can_push) {
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

// TEST(TestList, is_empty) {
//     List<int> list;
//     EXPECT_TRUE(list.is_empty());
//     list.push_back(1);
//     //EXPECT_FALSE(list.is_empty());
//     list.pop_back();
//     //EXPECT_TRUE(list.is_empty());
// }