#include <gtest/gtest.h>
#include "../lib_list_queue/Lqueue.h"

TEST(TestQueueL, can_push) {
    QueueList<int> queue({});
    
    queue.push(10);
    EXPECT_EQ(queue.count(), 1);
    EXPECT_EQ(queue.front(), 10);
    EXPECT_FALSE(queue.is_empty());
    
    queue.push(20);
    EXPECT_EQ(queue.count(), 2);
    EXPECT_EQ(queue.front(), 10);
}

TEST(TestQueueL, hard_push) {
    QueueList<int> queue({1, 2, 3});
    EXPECT_EQ(queue.count(), 3);
    EXPECT_EQ(queue.front(), 1);

    queue.pop();
    queue.push(4);
    
    EXPECT_EQ(queue.count(), 3);
    EXPECT_EQ(queue.front(), 2);
    EXPECT_EQ(queue.back(), 4);
}

TEST(TestQueueL, is_pop_correct) {
    QueueList<int> queue({});
    
    queue.push(10);
    queue.push(20);
    queue.push(30);
    
    int item1 = queue.pop();
    EXPECT_EQ(item1, 10);
    EXPECT_EQ(queue.count(), 2);
    EXPECT_EQ(queue.front(), 20);
    EXPECT_EQ(queue.back(), 30);
    
    int item2 = queue.pop();
    EXPECT_EQ(item2, 20);
    EXPECT_EQ(queue.count(), 1);
    EXPECT_EQ(queue.front(), 30);
    EXPECT_EQ(queue.back(), 30);
    
    int item3 = queue.pop();
    EXPECT_EQ(item3, 30);
    EXPECT_EQ(queue.count(), 0);
    EXPECT_TRUE(queue.is_empty());
}

TEST(TestQueueL, is_pop_exception) {
    QueueList<int> queue({});
    
    EXPECT_TRUE(queue.is_empty());
    EXPECT_THROW(queue.pop(), std::logic_error);
}

TEST(TestQueueL, push_and_pop) {
    QueueList<int> queue({});
    EXPECT_EQ(queue.count(), 0);

    queue.push(1);
    EXPECT_EQ(queue.front(), 1);
    queue.push(2);
    EXPECT_EQ(queue.front(), 1);
    queue.pop();
    queue.push(3);
    queue.push(4);
    queue.pop();
    queue.push(5);

    //5   3 4
    //_ _ _ _
    //2   0 1

    EXPECT_EQ(queue.count(), 3);
    EXPECT_EQ(queue.front(), 3);
}


//добавить тесты с эксепшнами