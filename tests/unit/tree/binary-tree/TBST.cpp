#include <asserts.hpp>
#include <TBST.hpp>

void test_should_create_an_empty_tbst(void)
{
    TBST<int> tree;

    ASSERT_TRUE(tree.isEmpty());
}

void RUN_THREADED_BINARY_SEARCH_TREE_TEST_SUITE()
{
    test_should_create_an_empty_tbst();
}
