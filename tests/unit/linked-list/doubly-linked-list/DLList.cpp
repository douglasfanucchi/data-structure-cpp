#include <asserts.hpp>
#include <DLList.hpp>

void test_should_create_doubly_linked_list()
{
    DLList<std::string> list;

    ASSERT_TRUE(list.isEmpty());
}

void test_should_insert_node_into_the_start_of_one_node_doubly_linked_list()
{
    DLList<std::string> list;
    
    list.addToHead("hello");

    ASSERT_FALSE(list.isEmpty());
}

void test_should_insert_node_into_the_end_of_an_empty_doubly_linked_list()
{
    DLList<std::string> list;

    list.addToTail("hello");

    ASSERT_FALSE(list.isEmpty());
}

void test_should_try_to_delete_a_node_from_an_empty_doubly_linked_list()
{
    DLList<std::string> list;
    const char* expected = "empty list";

    try {
        list.deleteFromTail();
    } catch(char const *result) {
        ASSERT_STREQ(expected, result);
    }
}

void test_should_delete_a_node_from_a_one_node_doubly_linked_list()
{
    DLList<std::string> list;
    const char *expected = "hello";
    list.addToHead("hello");

    std::string result = list.deleteFromTail();

    ASSERT_STREQ(expected, result);
    ASSERT_TRUE(list.isEmpty());
}

void test_should_delete_a_node_from_the_end_of_a_multiple_node_doubly_linked_list()
{
    DLList<std::string> list;
    const char *expected = "world";
    list.addToTail("hello");
    list.addToTail("world");

    std::string result = list.deleteFromTail();
    list.deleteFromTail();

    ASSERT_STREQ(expected, result);
    ASSERT_TRUE(list.isEmpty());
}

void RUN_DOUBLY_LINKED_LIST_SUITE()
{
    test_should_create_doubly_linked_list();
    test_should_insert_node_into_the_start_of_one_node_doubly_linked_list();
    test_should_insert_node_into_the_end_of_an_empty_doubly_linked_list();
    test_should_try_to_delete_a_node_from_an_empty_doubly_linked_list();
    test_should_delete_a_node_from_a_one_node_doubly_linked_list();
    test_should_delete_a_node_from_the_end_of_a_multiple_node_doubly_linked_list();
}
