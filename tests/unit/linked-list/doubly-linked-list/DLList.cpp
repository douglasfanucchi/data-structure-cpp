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

void test_should_insert_node_into_the_end_of_an_empty_double_linked_list()
{
    DLList<std::string> list;

    list.addToTail("hello");

    ASSERT_FALSE(list.isEmpty());
}

void test_should_try_to_delete_a_node_from_an_empty_double_linked_list()
{
    DLList<std::string> list;
    const char* expected = "empty list";

    try {
        list.deleteFromTail();
    } catch(char const *result) {
        ASSERT_STREQ(expected, result);
    }
}

void RUN_DOUBLE_LINKED_LIST_SUITE()
{
    test_should_create_double_linked_list();
    test_should_insert_node_into_the_start_of_one_node_double_linked_list();
    test_should_insert_node_into_the_end_of_an_empty_double_linked_list();
    test_should_try_to_delete_a_node_from_an_empty_double_linked_list();
}
