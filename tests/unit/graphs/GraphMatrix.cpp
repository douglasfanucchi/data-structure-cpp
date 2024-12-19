#include <asserts.hpp>
#include <GraphMatrix.hpp>

void test_should_create_an_graph_matrix_with_no_edges()
{
    GraphMatrix graph(5);

    ASSERT_FALSE(graph.hasEdges());
}

void RUN_GRAPH_MATRIX_TEST_SUITE()
{
    test_should_create_an_graph_matrix_with_no_edges();
}
