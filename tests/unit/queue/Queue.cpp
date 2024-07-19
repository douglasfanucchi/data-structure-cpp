#include <asserts.hpp>
#include <Queue.hpp>

void test_should_create_queue()
{
    Queue<int> queue;

    ASSERT_TRUE(queue.isEmpty());
}

void test_should_add_element_to_queue()
{
    Queue<int> queue;

    queue.enqueue(1);
    
    ASSERT_FALSE(queue.isEmpty());
}

void RUN_QUEUE_TEST_SUITE()
{
    test_should_create_queue();
    test_should_add_element_to_queue();
}
