#include <asserts.hpp>

void test_should_assert_true()
{
    ASSERT_TRUE(true);
}

void RUN_STACK_TEST_SUITE()
{
    test_should_assert_true();
}
