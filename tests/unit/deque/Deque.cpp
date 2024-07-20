#include <asserts.hpp>
#include <Deque.hpp>

void test_should_create_a_deque()
{
    Deque<int> deque;

    ASSERT_TRUE(deque.isEmpty());
}

void RUN_DEQUE_TEST_SUITE()
{
    test_should_create_a_deque();
}
