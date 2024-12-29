#include <asserts.hpp>
#include <Maze.hpp>

static void test_should_create_a_maze()
{
    Maze maze(100);

    ASSERT_EQ(0, maze.countEdges());
}

void RUN_MAZE_TEST_SUITE()
{
    test_should_create_a_maze();
}
