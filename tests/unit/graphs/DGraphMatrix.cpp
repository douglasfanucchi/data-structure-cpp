#include <asserts.hpp>
#include <DGraphMatrix.hpp>

void test_should_created_a_dgraph_with_no_edges()
{
    DGraphMatrix graph(5);

    ASSERT_EQ(0, graph.countEdges());
}

void RUN_DGRAPH_MATRIX_TEST_SUITE()
{
    test_should_created_a_dgraph_with_no_edges();
}
