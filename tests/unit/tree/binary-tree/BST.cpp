#include <asserts.hpp>
#include <BST.hpp>

void test_should_create_a_bst(void)
{
    BST<int> tree;

    ASSERT_TRUE(tree.isEmpty());
}

void test_should_insert_node_into_bst(void)
{
    BST<int> tree;

    tree.insert(13);

    ASSERT_FALSE(tree.isEmpty());
}

void test_should_insert_node_into_left_subtree(void)
{
    BST<int> tree;
    tree.insert(13);

    tree.insert(10);

    ASSERT_FALSE(tree.isEmpty());
}

void RUN_BINARY_SEARCH_TREE_TEST_SUITE()
{
    test_should_create_a_bst();
    test_should_insert_node_into_bst();
    test_should_insert_node_into_left_subtree();
}