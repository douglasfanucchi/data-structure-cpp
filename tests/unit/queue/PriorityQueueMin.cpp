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
    PriorityQueueItem<int> item(0, 1);

    queue.enqueue(item);

    ASSERT_FALSE(queue.isEmpty());
    ASSERT_EQ(0, item.index);
}

static void test_should_dequeue_an_element()
{
    PriorityQueueMin<int> queue(1);
    PriorityQueueItem<int> item(0, 1);
    queue.enqueue(item);

    int result = queue.dequeue();

    ASSERT_EQ(1, result);
    ASSERT_TRUE(queue.isEmpty());
    ASSERT_EQ(-1, item.index);
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
    PriorityQueueItem<int> item_1(1, 50);
    PriorityQueueItem<int> item_2(0, 100);

    queue.enqueue(item_1);
    queue.enqueue(item_2);

    int result = queue.dequeue();

    ASSERT_EQ(100, result);
    ASSERT_EQ(50, queue[0].item);
    ASSERT_EQ(-1, item_2.index);
    ASSERT_EQ(1, item_1.index);
}

static void test_should_dequeue_specifying_node_value()
{
    PriorityQueueMin<int> queue(7);
    PriorityQueueItem<int> items[7];
    items[0].priority = 1;
    items[0].item = 50;
    items[1].priority = 3;
    items[1].item = 200;
    items[2].priority = 0;
    items[2].item = 100;
    items[3].priority = 2;
    items[3].item = 150;
    items[4].priority = 3;
    items[4].item = 250;
    items[5].priority = 3;
    items[5].item = 300;
    items[6].priority = 4;
    items[6].item = 350;
    queue.enqueue(items[0]);
    queue.enqueue(items[1]);
    queue.enqueue(items[2]);
    queue.enqueue(items[3]);
    queue.enqueue(items[4]);
    queue.enqueue(items[5]);
    queue.enqueue(items[6]);

    queue.dequeue(items[0]);

    ASSERT_EQ(-1, items[0].index);
    ASSERT_EQ(2, items[5].index);
    ASSERT_EQ(5, items[6].index);
}

static void test_should_dequeue_an_empty_queue_specifying_node_value()
{
    PriorityQueueMin<int> queue(0);
    PriorityQueueItem<int> item(0, 50);

    try {
        queue.dequeue(item);
        ASSERT_TRUE(false);
    } catch(const char *result) {
        ASSERT_STREQ("empty queue", result);
    }
}

static void test_should_dequeue_an_element_that_is_not_in_the_queue()
{
    PriorityQueueMin<int> queue(1);
    PriorityQueueItem<int> item(0, 50);
    PriorityQueueItem<int> itemNotPresent(100, 100);
    PriorityQueueItem<int> itemNotPresent2(0, 100);
    queue.enqueue(item);
    itemNotPresent2.index = 0;

    try {
        queue.dequeue(itemNotPresent);
        ASSERT_TRUE(false);
    } catch(char const *result) {
        ASSERT_STREQ("element not present", result);
    }

    try {
        queue.dequeue(itemNotPresent2);
        ASSERT_TRUE(false);
    } catch(const char *result) {
        ASSERT_STREQ("element not present", result);
    }
}

static void test_should_decrease_item_priority()
{
    PriorityQueueMin<int> queue(4);
    PriorityQueueItem<int> items[4];
    items[0].priority = 1;
    items[0].item = 50;
    items[1].priority = 2;    
    items[1].item = 100;
    items[2].priority = 3;
    items[2].item = 150;
    items[3].priority = 4;
    items[3].item = 200;
    queue.enqueue(items[0]);
    queue.enqueue(items[1]);
    queue.enqueue(items[2]);
    queue.enqueue(items[3]);

    queue.decreasePriority(items[3], 0);

    ASSERT_EQ(0, items[3].index);
    ASSERT_EQ(0, items[3].priority);
    ASSERT_EQ(1, items[0].index);
    ASSERT_EQ(3, items[1].index);
}

static void test_should_try_to_decrease_priority_of_a_non_existing_item()
{
    PriorityQueueMin<int> queue(1);
    PriorityQueueMin<int> queue_2(2);
    PriorityQueueItem<int> item(0, 1);
    PriorityQueueItem<int> item_2(1, 1);
    queue_2.enqueue(item);
    queue_2.enqueue(item_2);

    try {
        queue.decreasePriority(item_2, -1);
        ASSERT_TRUE(false);
    } catch(char const *result) {
        ASSERT_STREQ("element not present", result);
    }
}

static void test_should_try_to_decrease_priority_passing_a_higher_priority_value()
{
    PriorityQueueMin<int>queue(1);
    PriorityQueueItem<int> item(0, 1);
    queue.enqueue(item);

    try {
        queue.decreasePriority(item, 1);
        ASSERT_TRUE(false);
    } catch(char const *result) {
        ASSERT_STREQ("priority should be lower or equal than the current one", result);
    }
}

void RUN_TEST_PRIORITY_QUEUE_MIN()
{
    test_should_create_an_empty_priority_queue();
    test_should_enqueue_element();
    test_should_dequeue_an_element();
    test_should_dequeue_an_element_with_lower_priority_first();
    test_should_try_to_dequeue_from_an_empty_queue();
    test_should_dequeue_specifying_node_value();
    test_should_dequeue_an_empty_queue_specifying_node_value();
    test_should_dequeue_an_element_that_is_not_in_the_queue();
    test_should_decrease_item_priority();
    test_should_try_to_decrease_priority_of_a_non_existing_item();
    test_should_try_to_decrease_priority_passing_a_higher_priority_value();
}
