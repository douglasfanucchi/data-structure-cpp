#include <asserts.hpp>
#include <IntSLLNode.hpp>
#include <IntSLList.hpp>

void test_should_create_an_empty_linked_list()
{
    IntSLList list;

    ASSERT_TRUE(list.isEmpty());
}

void RUN_INT_SLLIST_SUITE()
{
    test_should_create_an_empty_linked_list();
}
