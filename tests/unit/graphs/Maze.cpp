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

void RUN_MAZE_TEST_SUITE()
{
    test_should_create_a_maze();
    test_should_find_path_of_a_simple_maze();
}
