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

void RUN_GRAPH_MATRIX_TEST_SUITE()
{
    test_should_create_an_graph_matrix_with_no_edges();
    test_should_insert_an_edge_into_graph_matrix();
}
