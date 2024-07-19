#include <asserts.hpp>
#include <Queue.hpp>

void test_should_create_queue()
{
    Queue<int> queue;

    ASSERT_TRUE(queue.isEmpty());
}

void RUN_QUEUE_TEST_SUITE()
{
    test_should_create_queue();
}
