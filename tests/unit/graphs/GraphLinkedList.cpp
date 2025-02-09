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

static void test_should_check_if_edge_exists()
{
    GraphLinkedList graph(5);

    graph.insertEdge(0, 1);

    ASSERT_TRUE(graph.edgeExists(0, 1));
    ASSERT_FALSE(graph.edgeExists(0, 2));
}

static void test_should_delete_edge()
{
    GraphLinkedList graph(5);
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 2);

    graph.deleteEdge(1, 0);
    ASSERT_EQ(1, graph.countEdges());

    graph.insertEdge(0, 1);
    ASSERT_EQ(2, graph.countEdges());

    graph.deleteEdge(1, 2);
    ASSERT_EQ(2, graph.countEdges());
}

static void test_should_delete_invalid_edge()
{
    GraphLinkedList graph(5);
    char const *expected = "invalid vertex";

    try {
        graph.deleteEdge(-1, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.deleteEdge(5, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.deleteEdge(0, -1);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.deleteEdge(0, 5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }
}

static void test_should_check_vertex_degree()
{
    GraphLinkedList graph(5);

    ASSERT_EQ(0, graph.degree(0));

    graph.insertEdge(0, 1);
    graph.insertEdge(0, 2);
    graph.insertEdge(0, 3);
    graph.insertEdge(0, 4);

    ASSERT_EQ(4, graph.degree(0));
    ASSERT_EQ(1, graph.degree(1));
}

static void test_should_travel_fully_disconnected_graph()
{
    GraphLinkedList graph(5);

    Deque<int> result = graph.deepthFirst();

    ASSERT_FALSE(result.isEmpty());
    ASSERT_EQ(0, result[0]);
    ASSERT_EQ(1, result[1]);
    ASSERT_EQ(2, result[2]);
    ASSERT_EQ(3, result[3]);
    ASSERT_EQ(4, result[4]);
}

static void test_should_travel_non_empty_graph_going_deepth_first()
{
    GraphLinkedList graph(5);
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 2);
    graph.insertEdge(1, 2);
    graph.insertEdge(1, 3);
    graph.insertEdge(2, 4);
    graph.insertEdge(3, 4);

    Deque<int> result = graph.deepthFirst();

    ASSERT_EQ(0, result[0]);
    ASSERT_EQ(1, result[1]);
    ASSERT_EQ(2, result[2]);
    ASSERT_EQ(4, result[3]);
    ASSERT_EQ(3, result[4]);
}

void test_should_travel_disconnected_graph_going_deepth_first()
{
    GraphLinkedList graph(5);
    graph.insertEdge(0, 1);
    graph.insertEdge(1, 4);
    graph.insertEdge(2, 3);

    Deque<int> result = graph.deepthFirst();

    ASSERT_EQ(0, result[0]);
    ASSERT_EQ(1, result[1]);
    ASSERT_EQ(4, result[2]);
    ASSERT_EQ(2, result[3]);
    ASSERT_EQ(3, result[4]);
}

static void test_should_check_cycle_into_graph_with_no_edges()
{
    GraphLinkedList graph(5);

    ASSERT_FALSE(graph.hasCycle());
}

static void test_should_check_cycle_into_graph_with_one_edge()
{
    GraphLinkedList graph(2);
    graph.insertEdge(0, 1);

    ASSERT_FALSE(graph.hasCycle());
}

static void test_should_check_cycle_into_graph_with_simplest_cycle()
{
    GraphLinkedList graph(3);
    graph.insertEdge(0, 1);
    graph.insertEdge(1, 2);
    graph.insertEdge(2, 0);

    ASSERT_TRUE(graph.hasCycle());
}

static void test_should_check_cycle_into_graph_with_cycle()
{
    GraphLinkedList graph(5);
    graph.insertEdge(0, 1);
    graph.insertEdge(1, 2);
    graph.insertEdge(2, 3);
    graph.insertEdge(3, 4);
    graph.insertEdge(4, 0);

    ASSERT_TRUE(graph.hasCycle());
}

static void test_should_check_cycle_into_disconnected_graph()
{
    GraphLinkedList graph(4);
    graph.insertEdge(1, 2);
    graph.insertEdge(2, 3);
    graph.insertEdge(3, 1);

    ASSERT_TRUE(graph.hasCycle());
}

static void test_should_get_connected_components_from_a_graph_with_no_edges()
{
    GraphLinkedList graph(2);

    IntSLList components = graph.connectedComponents();

    ASSERT_EQ(1, components.current());
    components.next();
    ASSERT_EQ(2, components.current());
}

static void test_should_get_connected_component_from_a_fully_connected_graph()
{
    GraphLinkedList graph(5);
    graph.insertEdge(0, 1);
    graph.insertEdge(1, 2);
    graph.insertEdge(2, 3);
    graph.insertEdge(3, 4);
    graph.insertEdge(4, 0);

    IntSLList components = graph.connectedComponents();

    ASSERT_EQ(1, components.size());
    ASSERT_EQ(1, components.current());
}

static void test_should_travel_breadth_first()
{
    GraphLinkedList graph(4);
    graph.insertEdge(0, 1);
    graph.insertEdge(1, 3);
    graph.insertEdge(0, 2);
    graph.insertEdge(2, 3);

    Deque<int> result = graph.breadthFirst();

    ASSERT_EQ(0, result[0]);
    ASSERT_EQ(1, result[1]);
    ASSERT_EQ(2, result[2]);
    ASSERT_EQ(3, result[3]);
}

static void test_should_travel_disconnected_graph_in_breadth_first()
{
    GraphLinkedList graph(2);

    Deque<int> result = graph.breadthFirst();

    ASSERT_EQ(0, result[0]);
    ASSERT_EQ(1, result[1]);
}

void RUN_GRAPH_LINKED_LIST_TEST_SUITE()
{
    test_should_create_graph();
    test_should_insert_edge_into_graph();
    test_should_insert_invalid_edge();
    test_should_check_if_edge_exists();
    test_should_delete_edge();
    test_should_delete_invalid_edge();
    test_should_check_vertex_degree();
    test_should_travel_fully_disconnected_graph();
    test_should_travel_non_empty_graph_going_deepth_first();
    test_should_travel_disconnected_graph_going_deepth_first();
    test_should_check_cycle_into_graph_with_no_edges();
    test_should_check_cycle_into_graph_with_one_edge();
    test_should_check_cycle_into_graph_with_simplest_cycle();
    test_should_check_cycle_into_graph_with_cycle();
    test_should_check_cycle_into_disconnected_graph();
    test_should_get_connected_components_from_a_graph_with_no_edges();
    test_should_get_connected_component_from_a_fully_connected_graph();
    test_should_travel_breadth_first();
    test_should_travel_disconnected_graph_in_breadth_first();
}
