#include <asserts.hpp>
#include <DGraphLinkedList.hpp>

static void test_should_create_a_dgraph_linked_list()
{
    GraphLinkedList *graph = new DGraphLinkedList(5);

    ASSERT_EQ(0, graph->countEdges());

    delete graph;
}

static void test_should_insert_edge_into_dgraph_linked_list()
{
    GraphLinkedList *graph = new DGraphLinkedList(5);

    graph->insertEdge(0, 1);
    graph->insertEdge(1, 0);

    ASSERT_EQ(2, graph->countEdges());

    delete graph;
}

static void test_should_insert_duplicated_edge_into_dgraph_linked_list()
{
    GraphLinkedList *graph = new DGraphLinkedList(5);

    graph->insertEdge(0, 1);
    graph->insertEdge(0, 1);

    ASSERT_EQ(1, graph->countEdges());

    delete graph;
}

static void test_should_insert_invalid_edge()
{
    GraphLinkedList *graph = new DGraphLinkedList(5);
    char const *expected = "invalid vertex";

    try {
        graph->insertEdge(-1, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph->insertEdge(5, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph->insertEdge(0, -1);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph->insertEdge(0, 5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    delete graph;
}

void RUN_DGRAPH_LINKED_LIST_TEST_SUITE()
{
    test_should_create_a_dgraph_linked_list();
    test_should_insert_edge_into_dgraph_linked_list();
    test_should_insert_duplicated_edge_into_dgraph_linked_list();
    test_should_insert_invalid_edge();
}
