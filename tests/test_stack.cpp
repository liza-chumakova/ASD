#include <gtest/gtest.h>
#include "../lib_stack/stack.h"

TEST(TestStack, can_create_with_default_construct) {
    // Arrange & Act
    Stack<int> stack;
    //ASSERT_NO_THROW(Stack<int> stack);

    //Assert
    EXPECT_EQ(stack.size(), 0);
    EXPECT_EQ(stack.top(), 0);
    EXPECT_EQ(stack.data(), nullptr);
}

TEST(TestStack, can_create_with_constructor_by_size) {
    // Arrange & Act
    Stack<int> stack(18);

    //Assert
    EXPECT_EQ(stack.size(), 18);
    EXPECT_EQ(stack.top(), 17);
    EXPECT_NE(stack.data(), nullptr);
}

TEST(TestStack, can_create_with_copying_constructor) {
    // Arrange & Act
    Stack<int> stack({1, 2, 3, 4, 5});
    Stack<int> stack1(stack);

    //Assert
    EXPECT_EQ(stack.size(), 5);
    EXPECT_EQ(stack, stack1);
}

TEST(TestStack, can_create_with_constructor_by_initializer_list) {
    // Arrange & Act
    Stack<int> stack({1, 2, 3, 4, 5});
    //Assert
    EXPECT_EQ(stack.size(), 5);
    EXPECT_EQ(stack.top(), 4);
    EXPECT_NE(stack.data(), nullptr);

    for (int i = 0; i < stack.size(); ++i)
    {
        EXPECT_EQ(stack[i], i + 1);
    }
}

TEST(TestStack, is_pop_correct)
{
    Stack<int> stack({1, 2, 3, 4, 5});
    stack.pop();
    Stack<int> expected({1, 2, 3, 4});

    EXPECT_EQ(stack, expected);
}

TEST(TestStack, is_pop_correct_exception)
{
    Stack<int> stack({1, 2, 3, 4, 5});
    stack.pop();
    Stack<int> expected({1, 2, 3, 4});

    EXPECT_EQ(stack, expected);
}

TEST(TestStack, is_push_correct)
{
    Stack<int> stack(4);
    stack.push(1);
    stack.push(2);
    Stack<int> expected({1, 2});

    EXPECT_EQ(stack, expected);
}

TEST(TestStack, is_push_correct_exception)
{
    Stack<int> stack(1);
    stack.push(1);
    stack.push(2);
    Stack<int> expected({1, 2});

    EXPECT_NE(stack, expected);
}