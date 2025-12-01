#include <gtest/gtest.h>
#include "../lib_algorithms/ListCycle.h"

TEST(ListCycle, list_without_cycle) {
    List<int> list = {1, 2, 3, 4, 5};

    EXPECT_FALSE(checkListCycle(list.head()));
    
}

// TEST(ListCycle, list_with_full_cycle) {
//     List<int> list = {1, 2, 3, 4, 5};
//     list.tail()->_next = list.head();

//     EXPECT_TRUE(checkListCycle(list.head()));
// }