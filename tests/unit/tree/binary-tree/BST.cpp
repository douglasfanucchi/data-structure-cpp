#include <asserts.hpp>
#include <DummyUser.hpp>
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

void test_should_search_for_a_value_in_the_binary_tree()
{
    BST<user> tree;
    tree.insert(user(2, "admin"));
    tree.insert(user(1, "user1"));
    tree.insert(user(3, "user2"));
    user expected = user(1, "user1");

    user *result = tree.search(expected);

    ASSERT_FALSE(result == NULL);
    ASSERT_STREQ(expected.name, result->name);
    ASSERT_EQ(expected.id, result->id);
}

void test_should_clear_the_binary_search_tree()
{
    BST<int> tree;
    tree.insert(1);

    tree.clear();

    ASSERT_TRUE(tree.isEmpty());
}

void test_should_clear_the_binary_search_tree_and_its_subtrees()
{
    BST<int> tree;
    tree.insert(3);
    tree.insert(1);
    tree.insert(2);
    tree.insert(0);
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);

    tree.clear();

    ASSERT_TRUE(tree.isEmpty());
}

void RUN_BINARY_SEARCH_TREE_TEST_SUITE()
{
    test_should_create_a_bst();
    test_should_insert_node_into_bst();
    test_should_insert_node_into_left_subtree();
    test_should_insert_node_into_right_subtree();
    test_should_insert_two_nodes_with_same_value();
    test_should_search_for_a_value_in_the_binary_tree();
    test_should_clear_the_binary_search_tree();
    test_should_clear_the_binary_search_tree_and_its_subtrees();
}