#include <asserts.hpp>
#include <DummyUser.hpp>
#include <BST.hpp>
#include <queue>

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

void test_should_insert_nodes_into_bst_forming_a_linked_list()
{
    BST<int> tree;
    tree.insert(1);
    tree.insert(2);
    tree.insert(3);

    ASSERT_FALSE(tree.isEmpty());

    BST<int> secondTree;
    secondTree.insert(1);
    secondTree.insert(2);
    secondTree.insert(3);
    secondTree.insert(4);

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

void test_should_traverse_bst_in_a_breadthFirst_way()
{
    BST<int> tree;
    std::queue<int> expected;
    tree.insert(13);
    tree.insert(10);
    tree.insert(2);
    tree.insert(12);
    tree.insert(25);
    tree.insert(20);
    tree.insert(31);
    tree.insert(29);
    expected.push(13);
    expected.push(10);
    expected.push(25);
    expected.push(2);
    expected.push(12);
    expected.push(20);
    expected.push(31);
    expected.push(29);

    std::queue<int> result = tree.breadthFirst();

    ASSERT_TRUE(expected == result);
}

void test_should_traverse_empty_bst_in_a_breadthFirst_way()
{
    BST<int> tree;
    
    std::queue<int> result = tree.breadthFirst();

    ASSERT_TRUE(result.empty());
}

void test_should_traverse_bst_in_a_deepthFirst_way_inorder()
{
    BST<int> tree;
    std::queue<int> expected;
    tree.insert(13);
    tree.insert(10);
    tree.insert(2);
    tree.insert(12);
    tree.insert(25);
    tree.insert(20);
    tree.insert(31);
    tree.insert(29);
    expected.push(2);
    expected.push(10);
    expected.push(12);
    expected.push(13);
    expected.push(20);
    expected.push(25);
    expected.push(29);
    expected.push(31);

    std::queue<int> result = tree.inorder();

    ASSERT_TRUE(expected == result);
}

void test_should_traverse_an_empty_bst_in_a_deepthFirst_inorder_way()
{
    BST<int> tree;

    std::queue<int> result = tree.inorder();

    ASSERT_TRUE(result.empty());
}

void test_should_traverse_bst_in_a_deepthFirst_preorder_way()
{
    BST<int> tree;
    std::queue<int> expected;
    tree.insert(13);
    tree.insert(10);
    tree.insert(2);
    tree.insert(12);
    tree.insert(25);
    tree.insert(20);
    tree.insert(31);
    tree.insert(29);
    expected.push(13);
    expected.push(10);
    expected.push(2);
    expected.push(12);
    expected.push(25);
    expected.push(20);
    expected.push(31);
    expected.push(29);

    std::queue<int> result = tree.preorder();
    std::queue<int> iterativeResult = tree.iterativePreorder();

    ASSERT_TRUE(expected == result);
    ASSERT_TRUE(expected == iterativeResult);
}

void test_should_traverse_an_empty_bst_in_a_deepthFirst_preorder_way()
{
    BST<int> tree;

    std::queue<int> result = tree.preorder();
    std::queue<int> iterativeResult = tree.iterativePreorder();

    ASSERT_TRUE(result.empty());
    ASSERT_TRUE(iterativeResult.empty());
}

void test_should_traverse_a_bst_in_a_deepthFirst_postorder_way()
{
    BST<int> tree;
    std::queue<int> expected;
    tree.insert(13);
    tree.insert(10);
    tree.insert(2);
    tree.insert(12);
    tree.insert(25);
    tree.insert(20);
    tree.insert(31);
    tree.insert(29);
    expected.push(2);
    expected.push(12);
    expected.push(10);
    expected.push(20);
    expected.push(29);
    expected.push(31);
    expected.push(25);
    expected.push(13);

    std::queue<int> result = tree.postorder();
    std::queue<int> iterativeResult = tree.iterativePostorder();

    ASSERT_TRUE(expected == result);
    ASSERT_TRUE(expected == iterativeResult);
}

void test_should_traverse_an_empty_bst_in_a_deepthFirst_postorder_way()
{
    BST<int> tree;

    std::queue<int> result = tree.postorder();
    std::queue<int> iterativeResult = tree.iterativePostorder();

    ASSERT_TRUE(result.empty());
    ASSERT_TRUE(iterativeResult.empty());
}

void RUN_BINARY_SEARCH_TREE_TEST_SUITE()
{
    test_should_create_a_bst();
    test_should_insert_node_into_bst();
    test_should_insert_nodes_into_bst_forming_a_linked_list();
    test_should_insert_node_into_left_subtree();
    test_should_insert_node_into_right_subtree();
    test_should_insert_two_nodes_with_same_value();
    test_should_search_for_a_value_in_the_binary_tree();
    test_should_clear_the_binary_search_tree();
    test_should_clear_the_binary_search_tree_and_its_subtrees();
    test_should_traverse_bst_in_a_breadthFirst_way();
    test_should_traverse_empty_bst_in_a_breadthFirst_way();
    test_should_traverse_bst_in_a_deepthFirst_way_inorder();
    test_should_traverse_an_empty_bst_in_a_deepthFirst_inorder_way();
    test_should_traverse_bst_in_a_deepthFirst_preorder_way();
    test_should_traverse_an_empty_bst_in_a_deepthFirst_preorder_way();
    test_should_traverse_a_bst_in_a_deepthFirst_postorder_way();
    test_should_traverse_an_empty_bst_in_a_deepthFirst_postorder_way();
}