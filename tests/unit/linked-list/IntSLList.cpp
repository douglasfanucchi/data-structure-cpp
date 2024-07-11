#include <asserts.hpp>
#include <IntSLLNode.hpp>
#include <IntSLList.hpp>

void test_should_create_an_empty_linked_list()
{
    IntSLList list;

    ASSERT_TRUE(list.isEmpty());
}

void test_should_insert_node_into_linked_list_head()
{
    IntSLList list;

    list.addToHead(5);

    ASSERT_FALSE(list.isEmpty());
}

void test_should_insert_node_into_the_end_of_linked_list()
{
    IntSLList list;

    list.addToTail(5);

    ASSERT_FALSE(list.isEmpty());
}

void test_should_delete_node_from_the_start_of_linked_list()
{
    IntSLList list;
    list.addToHead(25);

    int result = list.deleteFromHead();

    ASSERT_EQ(25, result);
    ASSERT_TRUE(list.isEmpty());
}

void RUN_INT_SLLIST_SUITE()
{
    test_should_create_an_empty_linked_list();
    test_should_insert_node_into_linked_list_head();
    test_should_insert_node_into_the_end_of_linked_list();
    test_should_delete_node_from_the_start_of_linked_list();
}
