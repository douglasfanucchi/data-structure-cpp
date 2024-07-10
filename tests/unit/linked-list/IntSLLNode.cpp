#include <asserts.hpp>
#include <IntSLLNode.hpp>

void test_should_create_a_node()
{
    IntSLLNode node(10);

    ASSERT_EQ(10, node.value);
    ASSERT_TRUE(0 == node.next);
}

void RUN_INT_SLL_NODE_SUITE()
{
    test_should_create_a_node();
}
