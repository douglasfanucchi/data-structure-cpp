#include <asserts.hpp>
#include <DGraphMatrix.hpp>

void test_should_created_a_dgraph_with_no_edges()
{
    DGraphMatrix graph(5);

    ASSERT_EQ(0, graph.countEdges());
}

void test_should_insert_edge_into_dgraph()
{
    GraphMatrix *graph = new DGraphMatrix(5);

    graph->insertEdge(0, 1);
    graph->insertEdge(1, 0);
    graph->insertEdge(1, 1);

    ASSERT_EQ(3, graph->countEdges());
    ASSERT_EQ(2, graph->degree(1));

    delete graph;
}

void RUN_DGRAPH_MATRIX_TEST_SUITE()
{
    test_should_created_a_dgraph_with_no_edges();
    test_should_insert_edge_into_dgraph();
}
