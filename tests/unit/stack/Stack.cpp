#include <asserts.hpp>
#include <Stack.hpp>

void test_should_create_empty_stack()
{
    Stack<int> stack;

    ASSERT_TRUE(stack.isEmpty());
}

void RUN_STACK_TEST_SUITE()
{
    test_should_create_empty_stack();
}
