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

void test_should_dequeue_element_from_list()
{
    Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    int result = queue.dequeue();

    ASSERT_EQ(1, result);
}

void test_should_dequeue_element_from_an_empty_queue()
{
    Queue<int> queue;
    const char *expected = "empty queue";

    try {
        queue.dequeue();
        ASSERT_TRUE(false);
    } catch(const char *result) {
        ASSERT_STREQ(expected, result);
    }
}

void RUN_QUEUE_TEST_SUITE()
{
    test_should_create_queue();
    test_should_add_element_to_queue();
    test_should_dequeue_element_from_list();
    test_should_dequeue_element_from_an_empty_queue();
}
