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

void test_should_update_edge_value()
{
    PonderedGraphMatrix graph(5);
    graph.insertEdge(0, 1, 0.5);

    graph.insertEdge(0, 1, 0.7);

    ASSERT_EQ(1, graph.countEdges());
}

void test_should_insert_invalid_edge()
{
    PonderedGraphMatrix graph(5);
    char const *expected = "invalid vertex";

    try {
        graph.insertEdge(-1, 4, 0.5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.insertEdge(4, -1, 0.5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.insertEdge(5, 0, 0.5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }
}

void test_should_delete_an_edge_and_inserts_it_again()
{
    PonderedGraphMatrix graph(5);
    graph.insertEdge(1, 0, 0.5);

    graph.deleteEdge(0, 1);
    ASSERT_EQ(0, graph.countEdges());

    graph.insertEdge(1, 0, 0.5);
    ASSERT_EQ(1, graph.countEdges());
}

void test_should_delete_invalid_edge()
{
    PonderedGraphMatrix graph(5);
    char const *expected = "invalid vertex";

    try {
        graph.deleteEdge(-1, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.deleteEdge(5, 0);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.deleteEdge(0, -1);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        graph.deleteEdge(0, 5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }
}

void RUN_PONDERED_GRAPH_MATRIX_TEST_SUITE()
{
    test_should_create_a_pondered_graph_matrix();
    test_should_insert_an_edge_into_pondered_graph_matrix();
    test_should_update_edge_value();
    test_should_insert_invalid_edge();
    test_should_delete_an_edge_and_inserts_it_again();
    test_should_delete_invalid_edge();
}
