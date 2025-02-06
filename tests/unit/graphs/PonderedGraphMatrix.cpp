#include <asserts.hpp>
#include <PonderedGraphMatrix.hpp>
#include <iostream>

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

void test_should_check_if_an_edge_exists()
{
    PonderedGraphMatrix graph(5);

    graph.insertEdge(0, 1, 0.5);

    ASSERT_TRUE(graph.edgeExists(1, 0));
    ASSERT_FALSE(graph.edgeExists(1, 1));
}

void test_should_check_if_an_invalid_edge_exists()
{
    PonderedGraphMatrix graph(5);
    char const *expected = "invalid vertex";

    try {
        ASSERT_FALSE(graph.edgeExists(-1, 0));
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        ASSERT_FALSE(graph.edgeExists(5, 0));
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        ASSERT_FALSE(graph.edgeExists(0, -1));
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }

    try {
        ASSERT_FALSE(graph.edgeExists(0, 5));
    } catch(const char *err) {
        ASSERT_STREQ(expected, err);
    }
}

void test_should_check_if_a_vertex_has_adjacent()
{
    PonderedGraphMatrix graph(5);
    graph.insertEdge(0, 1, 0.5);

    ASSERT_TRUE(graph.hasAdjacent(0));
    ASSERT_TRUE(graph.hasAdjacent(1));
    ASSERT_FALSE(graph.hasAdjacent(2));
}

void test_should_chekc_if_an_invalid_vertex_has_adjacent()
{
    PonderedGraphMatrix graph(5);
    char const *expected = "invalid vertex";

    try {
        graph.hasAdjacent(-1);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }
    try {
        graph.hasAdjacent(5);
        ASSERT_TRUE(false);
    } catch(char const *err) {
        ASSERT_STREQ(expected, err);
    }
}

void test_should_check_vertex_degree()
{
    PonderedGraphMatrix graph(5);

    graph.insertEdge(0, 1, 0.5);
    graph.insertEdge(1, 0, 0.5);
    graph.insertEdge(1, 2, 1);
    graph.insertEdge(1, 3, 0.7);

    ASSERT_EQ(1, graph.degree(0));
    ASSERT_EQ(3, graph.degree(1));
    ASSERT_EQ(1, graph.degree(2));
    ASSERT_EQ(1, graph.degree(3));
}

static void test_should_generate_minimum_spanning_tree_using_prim_algorithm()
{
    PonderedGraphMatrix graph(6);
    graph.insertEdge(0, 1, 6.0);
    graph.insertEdge(0, 2, 1.0);
    graph.insertEdge(0, 3, 3.5);
    graph.insertEdge(1, 2, 2.5);
    graph.insertEdge(1, 4, 5.0);
    graph.insertEdge(4, 2, 6.0);
    graph.insertEdge(4, 5, 3.0);
    graph.insertEdge(5, 2, 4.5);
    graph.insertEdge(5, 3, 4.0);
    graph.insertEdge(3, 2, 2.0);

    PonderedGraphMatrix mst = graph.mst();
    float cost = mst.getCost();

    ASSERT_TRUE(12.5 - cost < 0.001);
    ASSERT_TRUE(mst.edgeExists(0, 2));
    ASSERT_TRUE(mst.edgeExists(2, 1));
    ASSERT_TRUE(mst.edgeExists(2, 3));
    ASSERT_TRUE(mst.edgeExists(3, 5));
    ASSERT_TRUE(mst.edgeExists(4, 5));
}

void RUN_PONDERED_GRAPH_MATRIX_TEST_SUITE()
{
    test_should_create_a_pondered_graph_matrix();
    test_should_insert_an_edge_into_pondered_graph_matrix();
    test_should_update_edge_value();
    test_should_insert_invalid_edge();
    test_should_delete_an_edge_and_inserts_it_again();
    test_should_delete_invalid_edge();
    test_should_check_if_an_edge_exists();
    test_should_check_if_an_invalid_edge_exists();
    test_should_check_if_a_vertex_has_adjacent();
    test_should_chekc_if_an_invalid_vertex_has_adjacent();
    test_should_check_vertex_degree();
    test_should_generate_minimum_spanning_tree_using_prim_algorithm();
}
