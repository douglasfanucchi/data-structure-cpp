#include <asserts.hpp>
#include <GraphLinkedList.hpp>

void test_should_create_graph()
{
    GraphLinkedList graph(5);

    ASSERT_EQ(0, graph.countEdges());
}

void test_should_insert_edge_into_graph()
{
    GraphLinkedList graph(5);

    graph.insertEdge(0, 1);
    graph.insertEdge(1, 0);

    ASSERT_EQ(1, graph.countEdges());
}

static void test_should_insert_invalid_edge()
{
    GraphLinkedList graph(5);
    char const *expected = "invalid vertex";

    try {
        graph.insertEdge(-1, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.insertEdge(0, -1);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.insertEdge(5, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.insertEdge(0, 5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }
}

void RUN_GRAPH_LINKED_LIST_TEST_SUITE()
{
    test_should_create_graph();
    test_should_insert_edge_into_graph();
    test_should_insert_invalid_edge();
}
