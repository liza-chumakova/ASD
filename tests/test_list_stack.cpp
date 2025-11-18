#include <gtest/gtest.h>
#include "../lib_list_stack/Lstack.h"

TEST(TestStackL, can_create_with_constructor_by_initializer_list) {
    // Arrange & Act
    StackList<int> stack({1, 2, 3, 4, 5});
    //Assert
    EXPECT_EQ(stack.size(), 5);
    EXPECT_EQ(stack.top(), 5);

    int expected_val = 1;

    // for (List<int>::Iterator it = stack.begin(); it != stack.end(); ++it) {
    //     EXPECT_EQ(*it, expected_val);
    //     expected_val++;
    // }
    for (int i = 4; i >= 0; --i)
    {
        EXPECT_EQ(stack.top(), i + 1);
        stack.pop();
    }
}

TEST(TestStackL, is_pop_correct)
{
    StackList<int> stack({1, 2, 3, 4, 5});
    stack.pop();
    //StackList<int> expected({1, 2, 3, 4});

    EXPECT_EQ(stack.top(), 4);
    EXPECT_EQ(stack.size(), 4);
}

TEST(TestStackL, is_pop_correct_exception)
{
    StackList<int> stack({});

    EXPECT_THROW(stack.pop(), std::logic_error);
}

TEST(TestStackL, is_push_correct)
{
    StackList<int> stack({});
    stack.push(1);
    stack.push(2);
    //StackList<int> expected({1, 2});

    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.size(), 2);
}
