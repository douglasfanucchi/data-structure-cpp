#include <asserts.hpp>
#include <PonderedGraphMatrix.hpp>

void test_should_create_a_pondered_graph_matrix()
{
    PonderedGraphMatrix graph(5);

    ASSERT_EQ(0, graph.countEdges());
}

void test_should_insert_an_edge_into_pondered_graph_matrix()
{
    PonderedGraphMatrix graph(5);

    graph.insertEdge(0, 1, 0.5);
    graph.insertEdge(1, 0, 0.5);

    ASSERT_EQ(1, graph.countEdges());
}

void test_should_insert_update_edge_value()
{
    PonderedGraphMatrix graph(5);
    graph.insertEdge(0, 1, 0.5);

    graph.insertEdge(0, 1, 0.7);

    ASSERT_EQ(1, graph.countEdges());
}

void RUN_PONDERED_GRAPH_MATRIX_TEST_SUITE()
{
    test_should_create_a_pondered_graph_matrix();
    test_should_insert_an_edge_into_pondered_graph_matrix();
    test_should_insert_update_edge_value();
}
