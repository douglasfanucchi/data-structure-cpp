#include <asserts.hpp>
#include <BTNode.hpp>

void test_should_create_binary_tree_node_with_no_value(void)
{
    BTNode<int> node;
    
    ASSERT_TRUE(node.left == 0);
    ASSERT_TRUE(node.right == 0);
}

void test_should_create_binary_tree_node_with_value()
{
    BTNode<int> node(1);
    
    ASSERT_TRUE(node.value == 1);
    ASSERT_TRUE(node.left == 0);
    ASSERT_TRUE(node.right == 0);
}

void RUN_BINARY_TREE_NODE_TEST_SUITE()
{
    test_should_create_binary_tree_node_with_no_value();
    test_should_create_binary_tree_node_with_value();
}
