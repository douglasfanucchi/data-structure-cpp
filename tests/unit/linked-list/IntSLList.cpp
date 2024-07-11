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

void test_should_delete_node_from_the_end_of_linked_list_when_list_has_one_element()
{
    IntSLList list;
    list.addToTail(25);

    int result = list.deleteFromTail();

    ASSERT_EQ(25, result);
    ASSERT_TRUE(list.isEmpty());
}

void test_should_delete_node_from_the_end_of_linked_list_with_multiple_elements()
{
    IntSLList list;
    list.addToTail(1);
    list.addToTail(2);
    list.addToTail(3);

    int result = list.deleteFromTail();

    ASSERT_EQ(3, result);
}

void test_should_delete_node_from_the_middle_of_linked_lists()
{
    IntSLList list;
    list.addToTail(1);
    list.addToTail(2);
    list.addToTail(3);
    list.addToTail(4);

    list.deleteNode(3);
    list.deleteFromTail();
    int result = list.deleteFromTail();

    ASSERT_EQ(2, result);
}

void test_should_delete_node_from_empty_linked_list()
{
    IntSLList list;

    try {
        list.deleteNode(3);
    } catch(char const *str) {
        ASSERT_STREQ("empty list", str);
    }
}

void RUN_INT_SLLIST_SUITE()
{
    test_should_create_an_empty_linked_list();
    test_should_insert_node_into_linked_list_head();
    test_should_insert_node_into_the_end_of_linked_list();
    test_should_delete_node_from_the_start_of_linked_list();
    test_should_delete_node_from_the_end_of_linked_list_when_list_has_one_element();
    test_should_delete_node_from_the_end_of_linked_list_with_multiple_elements();
    test_should_delete_node_from_the_middle_of_linked_lists();
    test_should_delete_node_from_empty_linked_list();
}
