#include <gtest/gtest.h>
#include "../lib_queue/queue.h"

TEST(QueueTest, can_push) {
    Queue<int> queue(5);
    
    queue.push(10);
    EXPECT_EQ(queue.count(), 1);
    EXPECT_EQ(queue.front(), 10);
    EXPECT_EQ(queue.back(), 10);
    EXPECT_FALSE(queue.is_empty());
    
    queue.push(20);
    EXPECT_EQ(queue.count(), 2);
    EXPECT_EQ(queue.front(), 10);
    EXPECT_EQ(queue.back(), 20);
}

TEST(QueueTest, is_push_exception) {
    Queue<int> queue(3);
    
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    EXPECT_TRUE(queue.is_full());
    EXPECT_THROW(queue.push(4), std::runtime_error);
}

TEST(QueueTest, hard_push) {
    Queue<int> queue({1, 2, 3});

    queue.pop();
    queue.push(4);
    
    EXPECT_EQ(queue.count(), 3);
    EXPECT_EQ(queue.front(), 2);
    EXPECT_EQ(queue.back(), 4);

    queue.pop();
    queue.push(5);
    
    EXPECT_EQ(queue.count(), 3);
    EXPECT_EQ(queue.front(), 3);
    EXPECT_EQ(queue.back(), 5);
}

TEST(QueueTest, is_pop_correct) {
    Queue<int> queue(5);
    
    queue.push(10);
    queue.push(20);
    queue.push(30);
    
    queue.pop();
    EXPECT_EQ(queue.count(), 2);
    EXPECT_EQ(queue.front(), 20);
    EXPECT_EQ(queue.back(), 30);
    
    queue.pop();
    EXPECT_EQ(queue.count(), 1);
    EXPECT_EQ(queue.front(), 30);
    EXPECT_EQ(queue.back(), 30);
    
    queue.pop();
    EXPECT_EQ(queue.count(), 0);
    EXPECT_TRUE(queue.is_empty());
}

TEST(QueuePopTest, is_pop_exception) {
    Queue<int> queue(3);
    
    EXPECT_TRUE(queue.is_empty());
    EXPECT_THROW(queue.pop(), std::runtime_error);
}

// Дополнительные интеграционные тесты

TEST(QueueIntegrationTest, PushPopSequence) {
    Queue<int> queue(4);
    
    // Sequence of push and pop operations
    queue.push(1);
    queue.push(2);
    queue.pop();
    queue.push(3);
    queue.push(4);
    queue.pop();
    queue.push(5);
    
    EXPECT_EQ(queue.count(), 3);
    EXPECT_EQ(queue.front(), 3);
    EXPECT_EQ(queue.back(), 5);
    EXPECT_EQ(queue[0], 3);
    EXPECT_EQ(queue[1], 4);
    EXPECT_EQ(queue[2], 5);
}
