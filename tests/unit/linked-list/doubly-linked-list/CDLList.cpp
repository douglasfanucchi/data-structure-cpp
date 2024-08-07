#include <asserts.hpp>
#include <CDLList.hpp>

void test_should_create_circular_doubly_linked_list()
{
    CDLList<int> list;

    ASSERT_TRUE(list.isEmpty());
}

void test_should_insert_node_into_the_end_of_a_circular_doubly_linked_list()
{
    CDLList<int> list;

    list.addToTail(10);

    ASSERT_FALSE(list.isEmpty());
}

void test_should_insert_node_into_the_start_of_a_circular_doubly_linked_list()
{
    CDLList<int> list;

    list.addToHead(25);

    ASSERT_FALSE(list.isEmpty());
}

void test_should_delete_from_the_end_of_the_circular_doubly_linked_list()
{
    CDLList<int> list;
    int expected = 25;
    list.addToTail(15);
    list.addToTail(20);
    list.addToTail(25);

    int result = list.deleteFromTail();

    ASSERT_EQ(expected, result);
}

void test_should_delete_node_from_the_end_of_a_one_node_circular_doubly_linked_list()
{
    CDLList<int> list;
    list.addToHead(1);
    int expected = 1;

    int result = list.deleteFromTail();

    ASSERT_EQ(expected, result);
    ASSERT_TRUE(list.isEmpty());
}

void test_should_delete_node_from_an_empty_circular_doubly_linked_list()
{
    CDLList<int> list;
    const char* expected = "empty list";

    try {
        list.deleteFromTail();
    } catch(const char* result) {
        ASSERT_STREQ(expected, result);
    }
}

void test_should_delete_node_from_the_start_of_a_circular_doubly_linked_list()
{
    CDLList<int> list;
    int expected = 1;
    list.addToTail(1);
    list.addToTail(2);
    list.addToTail(3);

    int result = list.deleteFromHead();

    ASSERT_EQ(expected, result);
}

void test_should_delete_node_from_the_start_of_a_one_node_circular_doubly_linked_list()
{
    CDLList<int> list;
    int expected = 1;
    list.addToTail(1);

    int result = list.deleteFromHead();

    ASSERT_EQ(expected, result);
}

void test_should_delete_node_from_start_of_an_empty_circular_doubly_linked_list()
{
    CDLList<int> list;
    const char *expected = "empty list";

    try {
        list.deleteFromHead();
    } catch(const char *result) {
        ASSERT_STREQ(expected, result);
    }
}

void test_should_search_for_an_element_in_the_circular_doubly_linked_list()
{
    CDLList<int> list;
    list.addToTail(1);
    list.addToTail(2);
    list.addToTail(3);
    list.addToTail(4);

    bool result = list.isInList(3);

    ASSERT_TRUE(result);
}

void test_should_search_for_an_element_in_an_empty_circular_doubly_linked_list()
{
    CDLList<int> list;
    
    bool result = list.isInList(4);

    ASSERT_FALSE(result);
}

void test_should_search_forn_an_unexistence_element_in_a_non_empty_circular_doubly_linked_list()
{
    CDLList<int> list;
    list.addToTail(1);
    list.addToTail(2);
    list.addToTail(3);
    list.addToTail(4);

    bool result = list.isInList(5);

    ASSERT_FALSE(result);
}

void RUN_CIRCULAR_DOUBLY_LINKED_LIST_SUITE()
{
    test_should_create_circular_doubly_linked_list();
    test_should_insert_node_into_the_end_of_a_circular_doubly_linked_list();
    test_should_insert_node_into_the_start_of_a_circular_doubly_linked_list();
    test_should_delete_from_the_end_of_the_circular_doubly_linked_list();
    test_should_delete_node_from_the_end_of_a_one_node_circular_doubly_linked_list();
    test_should_delete_node_from_an_empty_circular_doubly_linked_list();
    test_should_delete_node_from_the_start_of_a_circular_doubly_linked_list();
    test_should_delete_node_from_the_start_of_a_one_node_circular_doubly_linked_list();
    test_should_delete_node_from_start_of_an_empty_circular_doubly_linked_list();
    test_should_search_for_an_element_in_the_circular_doubly_linked_list();
    test_should_search_for_an_element_in_an_empty_circular_doubly_linked_list();
    test_should_search_forn_an_unexistence_element_in_a_non_empty_circular_doubly_linked_list();
}
