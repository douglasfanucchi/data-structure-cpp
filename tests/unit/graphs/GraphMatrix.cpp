#include <asserts.hpp>
#include <GraphMatrix.hpp>
#include <Deque.hpp>

void test_should_create_an_graph_matrix_with_no_edges()
{
    GraphMatrix graph(5);

    ASSERT_FALSE(graph.hasEdges());
    ASSERT_EQ(5, graph.countVertices());
    ASSERT_EQ(0, graph.countEdges());
}

void test_should_insert_an_edge_into_graph_matrix()
{
    GraphMatrix graph(5);

    graph.insertEdge(0, 1);

    ASSERT_EQ(1, graph.countEdges());
}

void test_should_sert_an_invalid_edge_into_graph_matrix()
{
    GraphMatrix graph(5);
    const char *expected = "invalid vertex";

    try {
        graph.insertEdge(-1, 0);
        ASSERT_TRUE(false);
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.insertEdge(5, 0);
        ASSERT_TRUE(false);
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }
}

void test_should_insert_self_loop_edge_into_graph_matrix()
{
    GraphMatrix graph(5);

    const char *expected = "invalid edge";

    try {
        graph.insertEdge(0, 0);
        ASSERT_TRUE(false);
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }
}

void test_should_duplicate_edge_and_assert_total_edges_is_keept()
{
    GraphMatrix graph(5);
    int expected = 1;

    graph.insertEdge(0, 1);
    graph.insertEdge(1, 0);
    int result = graph.countEdges();

    ASSERT_EQ(expected, result);
}

void test_should_remove_edge_from_graph_matrix()
{
    GraphMatrix graph(5);
    graph.insertEdge(0, 1);
    int expected = 0;

    graph.deleteEdge(0, 1);
    int result = graph.countEdges();

    ASSERT_EQ(expected, result);
}

void test_should_delete_an_invalid_edge()
{
    GraphMatrix graph(5);
    const char *expected = "invalid vertex";

    try {
        graph.deleteEdge(0, 5);
        ASSERT_TRUE(false);
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.deleteEdge(-1, 0);
        ASSERT_TRUE(false);
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }
}

void test_should_check_if_edge_exists()
{
    GraphMatrix graph(5);
    ASSERT_FALSE(graph.edgeExists(0, 1));

    graph.insertEdge(0, 1);
    ASSERT_TRUE(graph.edgeExists(0, 1));
}

void test_should_check_if_vertex_has_adjacents_vertices()
{
    GraphMatrix graph(5);
    ASSERT_FALSE(graph.hasAdjacent(0));

    graph.insertEdge(0, 1);
    ASSERT_TRUE(graph.hasAdjacent(0));
    ASSERT_TRUE(graph.hasAdjacent(1));
}

void test_should_check_by_vertex_degree()
{
    GraphMatrix graph(5);
    ASSERT_EQ(0, graph.degree(0));

    graph.insertEdge(0, 1);
    graph.insertEdge(0, 2);
    ASSERT_EQ(2, graph.degree(0));
    ASSERT_EQ(1, graph.degree(1));
    ASSERT_EQ(1, graph.degree(2));
}

void test_should_travel_graph_deepth_first()
{
    GraphMatrix graph(5);
    graph.insertEdge(0, 1);
    graph.insertEdge(0, 2);
    graph.insertEdge(1, 2);
    graph.insertEdge(2, 4);
    graph.insertEdge(4, 3);

    Deque<int> visited = graph.deepthFirst(0);

    ASSERT_EQ(0, visited[0]);
    ASSERT_EQ(1, visited[1]);
    ASSERT_EQ(2, visited[2]);
    ASSERT_EQ(4, visited[3]);
    ASSERT_EQ(3, visited[4]);
}

void test_should_travel_disconnected_graph()
{
    GraphMatrix graph(2);

    Deque<int> visited = graph.deepthFirst(0);

    ASSERT_EQ(0, visited[0]);
    ASSERT_EQ(1, visited[1]);
}

void RUN_GRAPH_MATRIX_TEST_SUITE()
{
    test_should_create_an_graph_matrix_with_no_edges();
    test_should_insert_an_edge_into_graph_matrix();
    test_should_sert_an_invalid_edge_into_graph_matrix();
    test_should_insert_self_loop_edge_into_graph_matrix();
    test_should_duplicate_edge_and_assert_total_edges_is_keept();
    test_should_remove_edge_from_graph_matrix();
    test_should_delete_an_invalid_edge();
    test_should_check_if_edge_exists();
    test_should_check_if_vertex_has_adjacents_vertices();
    test_should_check_by_vertex_degree();
    test_should_travel_graph_deepth_first();
    test_should_travel_disconnected_graph();
}
