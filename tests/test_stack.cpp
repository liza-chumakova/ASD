#include <gtest/gtest.h>
#include "../lib_stack/stack.h"

TEST(TestStack, can_create_with_constructor_by_size) {
    // Arrange & Act
    Stack<int> stack(18);

    //Assert
    EXPECT_EQ(stack.size(), 18);
    EXPECT_EQ(stack.get_top(), -1);
    EXPECT_NE(stack.data(), nullptr);
}

TEST(TestStack, can_create_with_constructor_by_initializer_list) {
    // Arrange & Act
    Stack<int> stack({1, 2, 3, 4, 5});
    //Assert
    EXPECT_EQ(stack.size(), 5);
    EXPECT_EQ(stack.top(), 5);
    EXPECT_NE(stack.data(), nullptr);

    for (int i = 4; i >= 0; --i)
    {
        EXPECT_EQ(stack.top(), i + 1);
        stack.pop();
    }
}

TEST(TestStack, can_create_with_copying_constructor) {
    // Arrange & Act
    Stack<int> stack({1, 2, 3, 4, 5});
    Stack<int> stack1(stack);

    //Assert
    EXPECT_EQ(stack1.size(), 5);
    for (int i = 0; i < stack1.size(); ++i)
    {
        EXPECT_EQ(stack1.top(), i + 1);
        stack1.pop();
    }
}

TEST(TestStack, is_pop_correct)
{
    Stack<int> stack({1, 2, 3, 4, 5});
    stack.pop();

    EXPECT_EQ(stack.top(), 4);
    EXPECT_EQ(stack.size(), 5);
}

TEST(TestStack, is_push_correct)
{
    Stack<int> stack(4);
    stack.push(1);
    stack.push(2);

    EXPECT_EQ(stack.top(), 2);
    EXPECT_EQ(stack.size(), 4);
}

TEST(TestStack, is_push_correct_exception)
{
    Stack<int> stack(1);
    stack.push(1);

    EXPECT_THROW(stack.push(2), std::logic_error);
}