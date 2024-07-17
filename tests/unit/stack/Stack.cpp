#include <asserts.hpp>
#include <Stack.hpp>

void test_should_create_empty_stack()
{
    Stack<int> stack;

    ASSERT_TRUE(stack.isEmpty());
}

void test_should_push_values_to_stack()
{
    Stack<int> stack;
    
    stack.push(5);

    ASSERT_FALSE(stack.isEmpty());
}

void test_should_pop_values_from_stack()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    int result = stack.pop();
    ASSERT_EQ(3, result);

    result = stack.pop();
    ASSERT_EQ(2, result);

    result = stack.pop();
    ASSERT_EQ(1, result);
    ASSERT_TRUE(stack.isEmpty());
}

void test_should_pop_value_from_empty_stack()
{
    Stack<int> stack;
    const char *expected = "empty stack";

    try {
        stack.pop();
    } catch (const char *result) {
        ASSERT_STREQ(expected, result);
    }
}

void test_should_check_for_top_element()
{
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    int result = stack.topEl();

    ASSERT_EQ(3, result);
}

void RUN_STACK_TEST_SUITE()
{
    test_should_create_empty_stack();
    test_should_push_values_to_stack();
    test_should_pop_values_from_stack();
    test_should_pop_value_from_empty_stack();
    test_should_check_for_top_element();
}
