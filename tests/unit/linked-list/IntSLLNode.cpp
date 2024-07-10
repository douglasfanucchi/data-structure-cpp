#include <asserts.hpp>
#include <IntSLLNode.hpp>

void test_should_create_a_node()
{
    IntSLLNode node(10);

    ASSERT_EQ(10, node.value);
    ASSERT_TRUE(0 == node.next);
}

void test_should_create_two_nodes_and_link_them()
{
    IntSLLNode *p = new IntSLLNode(
        10,
        new IntSLLNode(
            8,
            new IntSLLNode(
                50
            )
        )
    );

    ASSERT_EQ(10, p->value);
    ASSERT_EQ(8, p->next->value);
    ASSERT_EQ(50, p->next->next->value);

    delete p->next->next;
    delete p->next;
    delete p;
}

void RUN_INT_SLL_NODE_SUITE()
{
    test_should_create_a_node();
    test_should_create_two_nodes_and_link_them();
}
