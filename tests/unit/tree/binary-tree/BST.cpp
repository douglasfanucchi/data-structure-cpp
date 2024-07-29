#include <asserts.hpp>
#include <BST.hpp>

void test_should_create_a_bst(void)
{
    BST<int> tree;

    ASSERT_TRUE(tree.isEmpty());
}

void RUN_BINARY_SEARCH_TREE_TEST_SUITE()
{
    test_should_create_a_bst();
}