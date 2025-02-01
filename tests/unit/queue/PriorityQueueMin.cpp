#include <asserts.hpp>
#include <PriorityQueueMin.hpp>

static void test_should_create_an_empty_priority_queue()
{
    PriorityQueueMin<int> queue(0);

    ASSERT_TRUE(queue.isEmpty());
}

static void test_should_enqueue_element()
{
    PriorityQueueMin<int> queue(1);

    queue.enqueue(0, 1);

    ASSERT_FALSE(queue.isEmpty());
}

static void test_should_dequeue_an_element()
{
    PriorityQueueMin<int> queue(1);
    queue.enqueue(0, 1);

    int result = queue.dequeue();

    ASSERT_EQ(1, result);
    ASSERT_TRUE(queue.isEmpty());
}

static void test_should_try_to_dequeue_from_an_empty_queue()
{
    PriorityQueueMin<int> queue(1);
    
    try {
        queue.dequeue();
    } catch(const char *result) {
        ASSERT_STREQ("empty queue", result);
    }
}

static void test_should_dequeue_an_element_with_lower_priority_first()
{
    PriorityQueueMin<int> queue(2);
    queue.enqueue(1, 50);
    queue.enqueue(0, 100);

    int result = queue.dequeue();

    ASSERT_EQ(100, result);
}

void RUN_TEST_PRIORITY_QUEUE_MIN()
{
    test_should_create_an_empty_priority_queue();
    test_should_enqueue_element();
    test_should_dequeue_an_element();
    test_should_dequeue_an_element_with_lower_priority_first();
    test_should_try_to_dequeue_from_an_empty_queue();
}
