#include <asserts.hpp>
#include <DLList.hpp>

void test_should_create_double_linked_list()
{
    DLList<std::string> list;

    ASSERT_TRUE(list.isEmpty());
}

void test_should_insert_node_into_the_start_of_one_node_double_linked_list()
{
    DLList<std::string> list;
    
    list.addToHead("hello");

    ASSERT_FALSE(list.isEmpty());
}

void RUN_DOUBLE_LINKED_LIST_SUITE()
{
    test_should_create_double_linked_list();
    test_should_insert_node_into_the_start_of_one_node_double_linked_list();
}
