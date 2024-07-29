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

void test_should_insert_node_into_right_subtree(void)
{
    BST<int> tree;
    tree.insert(13);
    tree.insert(10);

    tree.insert(31);

    ASSERT_FALSE(tree.isEmpty());
}

void test_should_insert_two_nodes_with_same_value(void)
{
    BST<int> tree;
    tree.insert(13);

    try {
        tree.insert(13);
        ASSERT_TRUE(false);
    } catch(const char *result) {
        ASSERT_STREQ("value already exists", result);
    }
}

void RUN_BINARY_SEARCH_TREE_TEST_SUITE()
{
    test_should_create_a_bst();
    test_should_insert_node_into_bst();
    test_should_insert_node_into_left_subtree();
    test_should_insert_node_into_right_subtree();
    test_should_insert_two_nodes_with_same_value();
}