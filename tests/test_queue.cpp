#include <gtest/gtest.h>
#include "../lib_queue/queue.h"

TEST(QueueTest, can_push) {
    Queue<int> queue(5);
    
    queue.push(10);
    EXPECT_EQ(queue.count(), 1);
    EXPECT_EQ(queue.front(), 10);
    EXPECT_FALSE(queue.is_empty());
    
    queue.push(20);
    EXPECT_EQ(queue.count(), 2);
    EXPECT_EQ(queue.front(), 10);
}

TEST(QueueTest, hard_push) {
    Queue<int> queue({1, 2, 3});
    EXPECT_EQ(queue.count(), 3);
    EXPECT_EQ(queue.front(), 1);

    queue.pop();
    queue.push(4);
    
    EXPECT_EQ(queue.count(), 3);
    EXPECT_EQ(queue.front(), 2);
}

TEST(QueueTest, is_push_exception) {
    Queue<int> queue(3);
    
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    EXPECT_TRUE(queue.is_full());
    EXPECT_THROW(queue.push(4), std::runtime_error);
}

TEST(QueueTest, is_pop_correct) {
    Queue<int> queue(5);
    
    queue.push(10);
    queue.push(20);
    queue.push(30);
    
    int item1 = queue.pop();
    EXPECT_EQ(item1, 10);
    EXPECT_EQ(queue.count(), 2);
    //std::cout << ">>>>>>>>>>>>>>>>>>>>>>" << queue.front() << std::endl;
    EXPECT_EQ(queue.front(), 20);
    
    int item2 = queue.pop();
    EXPECT_EQ(item2, 20);
    EXPECT_EQ(queue.count(), 1);
    EXPECT_EQ(queue.front(), 30);
    
    int item3 = queue.pop();
    EXPECT_EQ(item3, 30);
    EXPECT_EQ(queue.count(), 0);
    EXPECT_TRUE(queue.is_empty());
}

TEST(QueueTest, is_pop_exception) {
    Queue<int> queue(3);
    
    EXPECT_TRUE(queue.is_empty());
    EXPECT_THROW(queue.pop(), std::runtime_error);
}

TEST(QueueTest, push_and_pop) {
    Queue<int> queue(4);
    EXPECT_EQ(queue.count(), 0);
    
    EXPECT_EQ(queue.head(), 0);
    queue.push(1);
    EXPECT_EQ(queue.head(), 1);
    queue.push(2);
    EXPECT_EQ(queue.head(), 2);
    EXPECT_EQ(queue[0], 1);
    EXPECT_EQ(queue[1], 2);
    queue.pop();
    EXPECT_EQ(queue[0], 2);
    queue.push(3);
    queue.push(4);
    EXPECT_EQ(queue[0], 2);
    EXPECT_EQ(queue[1], 3);
    EXPECT_EQ(queue[2], 4);
    queue.pop();
    queue.push(5);

    //5   3 4
    //_ _ _ _
    //2   0 1

    EXPECT_EQ(queue.count(), 3);
    EXPECT_EQ(queue.front(), 3);
    EXPECT_EQ(queue[0], 3);
    EXPECT_EQ(queue[1], 4);
    EXPECT_EQ(queue[2], 5);
}


//добавить тесты с эксепшнами