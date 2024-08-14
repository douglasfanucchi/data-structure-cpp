#include <asserts.hpp>
#include <TBST.hpp>
#include <queue>

void test_should_create_an_empty_tbst(void)
{
    TBST<int> tree;

    ASSERT_TRUE(tree.isEmpty());
}

void test_should_insert_element_into_tbst(void)
{
    TBST<int> tree;

    tree.insert(1);

    ASSERT_FALSE(tree.isEmpty());
}

void test_should_traverse_tbst_deepthFirst_inorder(void)
{
    TBST<int> tree;
    tree.insert(2);
    tree.insert(3);
    tree.insert(1);
    std::queue<int> expected;
    expected.push(1);
    expected.push(2);
    expected.push(3);

    std::queue<int> result = tree.inorder();

    ASSERT_TRUE(expected == result);

    {
        TBST<int> tree;
        tree.insert(1);
        tree.insert(0);
        tree.insert(3);
        tree.insert(2);
        std::queue<int> expected;
        expected.push(0);
        expected.push(1);
        expected.push(2);
        expected.push(3);

        result = tree.inorder();

        ASSERT_TRUE(expected == result);
    }
}

void RUN_THREADED_BINARY_SEARCH_TREE_TEST_SUITE()
{
    test_should_create_an_empty_tbst();
    test_should_insert_element_into_tbst();
    test_should_traverse_tbst_deepthFirst_inorder();
}
