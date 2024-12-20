#include <asserts.hpp>
#include <GraphMatrix.hpp>

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

void RUN_GRAPH_MATRIX_TEST_SUITE()
{
    test_should_create_an_graph_matrix_with_no_edges();
    test_should_insert_an_edge_into_graph_matrix();
    test_should_sert_an_invalid_edge_into_graph_matrix();
    test_should_insert_self_loop_edge_into_graph_matrix();
    test_should_duplicate_edge_and_assert_total_edges_is_keept();
}
