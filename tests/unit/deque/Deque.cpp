#include <asserts.hpp>
#include <Deque.hpp>

void test_should_create_a_deque()
{
    Deque<int> deque;

    ASSERT_TRUE(deque.isEmpty());
}

void test_should_insert_element_into_deque()
{
    Deque<int> deque;

    deque.pushFront(1);

    ASSERT_FALSE(deque.isEmpty());
}

void RUN_DEQUE_TEST_SUITE()
{
    test_should_create_a_deque();
    test_should_insert_element_into_deque();
}
