#include <asserts.hpp>
#include <CDLList.hpp>

void test_should_create_circular_doubly_linked_list()
{
    CDLList<int> list;

    ASSERT_TRUE(list.isEmpty());
}

void RUN_CIRCULAR_DOUBLY_LINKED_LIST_SUITE()
{
    test_should_create_circular_doubly_linked_list();
}
