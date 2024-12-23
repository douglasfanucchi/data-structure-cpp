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

    ASSERT_EQ(2, graph->countEdges());
    ASSERT_EQ(2, graph->degree(1));

    delete graph;
}

void test_should_insert_edge_with_invalid_vertex_into_dgraph()
{
    GraphMatrix *graph = new DGraphMatrix(5);
    char const *expected = "invalid vertex";

    try {
        graph->insertEdge(-1, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph->insertEdge(0, 5);
        ASSERT_TRUE(false);
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }

    delete graph;
}

void test_should_delete_edge_from_dgraph()
{
    GraphMatrix *graph = new DGraphMatrix(5);
    graph->insertEdge(0, 1);
    graph->insertEdge(1, 0);

    graph->deleteEdge(0, 1);

    ASSERT_TRUE(graph->hasAdjacent(1));
    ASSERT_EQ(1, graph->countEdges());

    delete graph;
}

void test_should_delete_edge_passing_invalid_vertices()
{
    GraphMatrix *graph = new DGraphMatrix(5);
    char const *expected = "invalid vertex";

    try {
        graph->deleteEdge(-1, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph->deleteEdge(0, 5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    delete graph;
}

void test_should_check_for_vertex_degree()
{
    GraphMatrix *graph = new DGraphMatrix(5);
    graph->insertEdge(1, 0);
    graph->insertEdge(0, 1);
    graph->insertEdge(2, 1);
    graph->insertEdge(4, 1);

    ASSERT_EQ(4, graph->degree(1));

    graph->insertEdge(1, 1);
    ASSERT_EQ(6, graph->degree(1));

    delete graph;
}

void test_should_check_degree_of_an_invalid_vertex()
{
    GraphMatrix *graph = new DGraphMatrix(5);
    char const *expected = "invalid vertex";

    try {
        graph->degree(-5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph->degree(5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    delete graph;
}

void RUN_DGRAPH_MATRIX_TEST_SUITE()
{
    test_should_created_a_dgraph_with_no_edges();
    test_should_insert_edge_into_dgraph();
    test_should_insert_edge_with_invalid_vertex_into_dgraph();
    test_should_delete_edge_from_dgraph();
    test_should_delete_edge_passing_invalid_vertices();
    test_should_check_for_vertex_degree();
    test_should_check_degree_of_an_invalid_vertex();
}
