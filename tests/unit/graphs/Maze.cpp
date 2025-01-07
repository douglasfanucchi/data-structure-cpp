#include <asserts.hpp>
#include <Maze.hpp>

static void test_should_create_a_maze()
{
    Maze maze(100);

    ASSERT_EQ(0, maze.countEdges());
}

static void test_should_find_path_of_a_simple_maze()
{
    Maze maze(2);
    maze.insertEdge(0, 1);

    IntSLList path = maze.solve(0, 1);

    ASSERT_FALSE(path.isEmpty());
    ASSERT_EQ(0, path.deleteFromHead());
    ASSERT_EQ(1, path.deleteFromHead());
}

static void test_should_try_to_solve_an_impossible_maze()
{
    Maze maze(2);

    IntSLList path = maze.solve(0, 1);

    ASSERT_TRUE(path.isEmpty());
}

static void test_should_find_path_of_a_maze_with_multiple_edges()
{
    Maze maze(5);
    maze.insertEdge(0, 1);
    maze.insertEdge(0, 2);
    maze.insertEdge(0, 3);
    maze.insertEdge(0, 4);
    maze.insertEdge(1, 3);
    maze.insertEdge(3, 2);
    maze.insertEdge(2, 4);

    IntSLList path = maze.solve(0, 4);

    ASSERT_FALSE(path.isEmpty());
    ASSERT_EQ(0, path.deleteFromHead());
    ASSERT_EQ(1, path.deleteFromHead());
    ASSERT_EQ(3, path.deleteFromHead());
    ASSERT_EQ(2, path.deleteFromHead());
    ASSERT_EQ(4, path.deleteFromHead());
}

static void test_should_find_the_minimum_distance_in_a_maze()
{
    Maze maze(5);
    maze.insertEdge(0, 1);
    maze.insertEdge(0, 2);
    maze.insertEdge(0, 3);
    maze.insertEdge(0, 4);
    maze.insertEdge(1, 3);
    maze.insertEdge(3, 2);
    maze.insertEdge(2, 4);

    int result = maze.minDistance(0, 4);

    ASSERT_EQ(1, result);
}

void RUN_MAZE_TEST_SUITE()
{
    test_should_create_a_maze();
    test_should_find_path_of_a_simple_maze();
    test_should_try_to_solve_an_impossible_maze();
    test_should_find_path_of_a_maze_with_multiple_edges();
    test_should_find_the_minimum_distance_in_a_maze();
}
