#include <asserts.hpp>
#include <PonderedGraphMatrix.hpp>

void test_should_create_a_pondered_graph_matrix()
{
    PonderedGraphMatrix graph(5);

    ASSERT_EQ(0, graph.countEdges());
}

void RUN_PONDERED_GRAPH_MATRIX_TEST_SUITE()
{
    test_should_create_a_pondered_graph_matrix();
}
