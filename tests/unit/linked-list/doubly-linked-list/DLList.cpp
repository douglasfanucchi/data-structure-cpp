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

void test_should_delete_a_node_from_the_start_of_an_empty_doubly_linked_list()
{
    DLList<std::string> list;
    const char *expected = "empty list";

    try {
        list.deleteFromHead();
    } catch (const char *result) {
        ASSERT_STREQ(expected, result);
    }
}

void test_should_delete_a_node_from_the_start_of_a_one_node_doubly_linked_list()
{
    DLList<std::string> list;
    const char *expected = "hello";
    list.addToHead("hello");

    std::string result = list.deleteFromHead();

    ASSERT_STREQ(expected, result);
}

void test_should_delete_a_node_from_the_start_of_a_multiple_node_doubly_linked_list()
{
    DLList<std::string> list;
    const char *expected = "hello";
    list.addToTail("hello");
    list.addToTail("world");

    std::string result = list.deleteFromHead();
    list.deleteFromHead();

    ASSERT_STREQ(expected, result);
    ASSERT_TRUE(list.isEmpty());
}

void test_should_delete_a_node_that_is_not_present_in_a_doubly_linked_list()
{
    DLList<std::string> list;
    list.addToTail("hello");

    list.deleteNode("hi");

    try {
        list.deleteFromTail();

        ASSERT_TRUE(true);
    } catch(const char *err){
        ASSERT_TRUE(false);
    }
}

void test_should_delete_a_node_from_the_middle_of_a_multiple_node_doubly_linked_list()
{
    DLList<std::string> list;
    list.addToTail("hello");
    list.addToTail("world");
    list.addToTail("!");

    list.deleteNode("world");

    ASSERT_STREQ("hello", list.deleteFromHead());
    ASSERT_STREQ("!", list.deleteFromHead());
}

void test_should_delete_a_node_from_the_start_of_a_multiple_node_doubly_linked_list_using_deleteNode()
{
    DLList<std::string> list;
    list.addToTail("hello");
    list.addToTail("world");
    list.addToTail("!");

    list.deleteNode("hello");

    ASSERT_STREQ("world", list.deleteFromHead());
    ASSERT_STREQ("!", list.deleteFromHead());
}

void test_should_delete_a_node_from_the_start_of_a_one_node_doubly_linked_list_using_deleteNode()
{
    DLList<std::string> list;
    list.addToTail("hello");

    list.deleteNode("hello");

    ASSERT_TRUE(list.isEmpty());
}

void test_should_delete_a_node_from_the_end_of_a_multiple_node_doubly_linked_list_using_deleteNode()
{
    DLList<std::string> list;
    list.addToTail("hello");
    list.addToTail("world");
    list.addToTail("!");

    list.deleteNode("!");

    ASSERT_STREQ("world", list.deleteFromTail());
    ASSERT_STREQ("hello", list.deleteFromTail());
}

void test_should_search_for_a_node_in_the_doubly_linked_list()
{
    DLList<std::string> list;
    list.addToTail("hello");
    list.addToTail("world");
    list.addToTail("!");

    bool result = list.isInList("world");

    ASSERT_TRUE(result);
}

void RUN_DOUBLY_LINKED_LIST_SUITE()
{
    test_should_create_doubly_linked_list();
    test_should_insert_node_into_the_start_of_one_node_doubly_linked_list();
    test_should_insert_node_into_the_end_of_an_empty_doubly_linked_list();
    test_should_try_to_delete_a_node_from_an_empty_doubly_linked_list();
    test_should_delete_a_node_from_a_one_node_doubly_linked_list();
    test_should_delete_a_node_from_the_end_of_a_multiple_node_doubly_linked_list();
    test_should_delete_a_node_from_the_start_of_an_empty_doubly_linked_list();
    test_should_delete_a_node_from_the_start_of_a_one_node_doubly_linked_list();
    test_should_delete_a_node_from_the_start_of_a_multiple_node_doubly_linked_list();
    test_should_delete_a_node_that_is_not_present_in_a_doubly_linked_list();
    test_should_delete_a_node_from_the_middle_of_a_multiple_node_doubly_linked_list();
    test_should_delete_a_node_from_the_start_of_a_multiple_node_doubly_linked_list_using_deleteNode();
    test_should_delete_a_node_from_the_start_of_a_one_node_doubly_linked_list_using_deleteNode();
    test_should_delete_a_node_from_the_end_of_a_multiple_node_doubly_linked_list_using_deleteNode();
    test_should_search_for_a_node_in_the_doubly_linked_list();
}
