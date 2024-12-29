#include <asserts.hpp>
#include <DGraphLinkedList.hpp>

static void test_should_create_a_dgraph_linked_list()
{
    GraphLinkedList *graph = new DGraphLinkedList(5);

    ASSERT_EQ(0, graph->countEdges());

    delete graph;
}

void RUN_DGRAPH_LINKED_LIST_TEST_SUITE()
{
    test_should_create_a_dgraph_linked_list();
}
