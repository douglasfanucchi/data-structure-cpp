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

void test_should_delete_node_from_one_node_linked_list()
{
    IntSLList list;
    list.addToHead(3);

    list.deleteNode(3);

    ASSERT_TRUE(list.isEmpty());
}

void test_should_delete_node_from_start_of_a_non_one_node_linked_list()
{
    IntSLList list;
    list.addToTail(10);
    list.addToTail(20);

    list.deleteNode(10);

    ASSERT_EQ(20, list.deleteFromHead());
}

void test_should_delete_node_from_end_of_a_non_one_node_linked_list()
{
    IntSLList list;
    list.addToTail(10);
    list.addToTail(20);

    list.deleteNode(20);

    ASSERT_EQ(10, list.deleteFromTail());
}

void test_should_delete_node_that_doesnt_belong_to_linked_list()
{
    IntSLList list;
    list.addToTail(10);

    list.deleteNode(5);

    ASSERT_FALSE(list.isEmpty());
}

void test_should_search_for_an_existing_element_in_the_linked_list()
{
    IntSLList list;
    list.addToTail(1);
    list.addToTail(2);
    list.addToTail(3);
    list.addToTail(4);

    bool result = list.isInList(3);

    ASSERT_TRUE(result);
}

void test_should_search_for_a_non_existing_element_in_the_linked_list()
{
    IntSLList list;
    list.addToTail(1);
    list.addToTail(2);

    bool result = list.isInList(3);

    ASSERT_FALSE(result);
}

void test_should_search_for_a_element_in_to_an_empty_linked_list()
{
    IntSLList list;
    
    bool result = list.isInList(1);

    ASSERT_FALSE(result);
}

static void test_should_check_list_size()
{
    IntSLList list;
    ASSERT_EQ(0, list.size());

    list.addToHead(123);
    ASSERT_EQ(1, list.size());
}

static void test_should_check_for_element_on_the_head_of_an_empty_list()
{
    IntSLList list;
    char const *expected = "empty list";

    try {
        list.current();
        ASSERT_TRUE(false);
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }
}

static void test_should_check_for_element_on_the_head_of_a_list()
{
    IntSLList list;
    list.addToHead(10);

    int el = list.current();

    ASSERT_EQ(10, el);
}

static void test_should_check_for_the_second_element_on_the_list()
{
    IntSLList list;
    list.addToTail(1);
    list.addToTail(2);

    bool hasNext = list.next();
    int el = list.current();

    ASSERT_TRUE(hasNext);
    ASSERT_EQ(2, el);
}

static void test_should_check_for_an_non_existing_element()
{
    IntSLList list;
    list.addToHead(1);

    ASSERT_FALSE(list.next());
    ASSERT_FALSE(list.next());

    IntSLList list2;
    char const *expected = "empty list";

    try {
        list.next();
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }
}

static void test_should_check_head_element_when_it_is_deleted()
{
    IntSLList list;
    list.addToTail(1);
    list.addToTail(2);
    list.deleteFromHead();

    int el = list.current();

    ASSERT_EQ(2, el);
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
    test_should_delete_node_from_one_node_linked_list();
    test_should_delete_node_from_start_of_a_non_one_node_linked_list();
    test_should_delete_node_from_end_of_a_non_one_node_linked_list();
    test_should_delete_node_that_doesnt_belong_to_linked_list();
    test_should_search_for_an_existing_element_in_the_linked_list();
    test_should_search_for_a_non_existing_element_in_the_linked_list();
    test_should_search_for_a_element_in_to_an_empty_linked_list();
    test_should_check_list_size();
    test_should_check_for_element_on_the_head_of_an_empty_list();
    test_should_check_for_element_on_the_head_of_a_list();
    test_should_check_for_the_second_element_on_the_list();
    test_should_check_for_an_non_existing_element();
    test_should_check_head_element_when_it_is_deleted();
}
