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

static void test_should_delete_edge_from_dgraph_linked_list()
{
    GraphLinkedList *graph = new DGraphLinkedList(5);
    graph->insertEdge(0, 1);
    graph->insertEdge(1, 0);

    graph->deleteEdge(0, 1);

    ASSERT_FALSE(graph->edgeExists(0, 1));
    ASSERT_TRUE(graph->edgeExists(1, 0));

    delete graph;
}

static void test_should_delete_non_existing_edge()
{
    GraphLinkedList *graph = new DGraphLinkedList(5);

    graph->deleteEdge(0, 1);

    ASSERT_EQ(0, graph->countEdges());

    delete graph;
}

static void test_should_delete_invalid_edge()
{
    GraphLinkedList *graph = new DGraphLinkedList(5);
    char const *expected = "invalid vertex";

    try {
        graph->deleteEdge(-1, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph->deleteEdge(0, 5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph->deleteEdge(0, -1);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph->deleteEdge(0, 5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    delete graph;
}

static void test_should_check_if_graph_with_no_edges_has_cycle()
{
    DGraphLinkedList graph(5);

    ASSERT_FALSE(graph.hasCycle());
}

static void test_should_check_if_a_self_loop_graph_has_cycle()
{
    DGraphLinkedList graph(5);
    graph.insertEdge(0, 0);

    ASSERT_TRUE(graph.hasCycle());
}

static void test_should_check_if_a_graph_with_multiple_edges_has_cycle()
{
    DGraphLinkedList graph(5);
    graph.insertEdge(1, 0);
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(3, 4);
    graph.insertEdge(4, 1);

    ASSERT_TRUE(graph.hasCycle());

    DGraphLinkedList graph2(5);
    graph2.insertEdge(0, 1);
    graph2.insertEdge(0, 2);
    graph2.insertEdge(0, 3);
    graph2.insertEdge(3, 4);
    graph2.insertEdge(2, 4);
    graph2.insertEdge(1, 4);
    graph2.insertEdge(1, 3);
    graph2.insertEdge(2, 3);

    ASSERT_FALSE(graph2.hasCycle());
}

static void test_should_make_a_topological_sort_in_a_graph_with_no_edges()
{
    DGraphLinkedList graph(5);

    IntSLList result = graph.topologicalSort();

    ASSERT_TRUE(result.isEmpty());
}

static void test_should_make_a_topological_sort_in_a_graph_with_one_edge()
{
    DGraphLinkedList graph(2);
    graph.insertEdge(1, 0);

    IntSLList result = graph.topologicalSort();

    ASSERT_EQ(1, result.current());
    result.next();
    ASSERT_EQ(0, result.current());
}

static void test_should_make_a_topological_sort_in_a_graph_with_multiple_edges()
{
    DGraphLinkedList graph(5);
    graph.insertEdge(0, 1);
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(2, 4);
    graph.insertEdge(4, 3);

    IntSLList result = graph.topologicalSort();

    ASSERT_EQ(0, result.current());
    result.next();
    ASSERT_EQ(1, result.current());
    result.next();
    ASSERT_EQ(2, result.current());
    result.next();
    ASSERT_EQ(4, result.current());
    result.next();
    ASSERT_EQ(3, result.current());
}

void RUN_DGRAPH_LINKED_LIST_TEST_SUITE()
{
    test_should_create_a_dgraph_linked_list();
    test_should_insert_edge_into_dgraph_linked_list();
    test_should_insert_duplicated_edge_into_dgraph_linked_list();
    test_should_insert_invalid_edge();
    test_should_delete_edge_from_dgraph_linked_list();
    test_should_delete_non_existing_edge();
    test_should_delete_invalid_edge();
    test_should_check_if_graph_with_no_edges_has_cycle();
    test_should_check_if_a_self_loop_graph_has_cycle();
    test_should_check_if_a_graph_with_multiple_edges_has_cycle();
    test_should_make_a_topological_sort_in_a_graph_with_no_edges();
    test_should_make_a_topological_sort_in_a_graph_with_one_edge();
    test_should_make_a_topological_sort_in_a_graph_with_multiple_edges();
}
