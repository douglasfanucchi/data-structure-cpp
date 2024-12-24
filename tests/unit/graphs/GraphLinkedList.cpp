#include <asserts.hpp>
#include <GraphLinkedList.hpp>

void test_should_create_graph()
{
    GraphLinkedList graph(5);

    ASSERT_EQ(0, graph.countEdges());
}

void RUN_GRAPH_LINKED_LIST_TEST_SUITE()
{
    test_should_create_graph();
}
