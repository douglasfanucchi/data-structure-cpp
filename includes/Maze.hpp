#ifndef MAZE_H
# define MAZE

#include <GraphLinkedList.hpp>
#include <IntSLList.hpp>

class Maze : public GraphLinkedList {
    public:
        Maze(int);
        IntSLList solve(int, int) const;
        int minDistance(int, int) const;
    protected:
        bool solveRecursive(int, int, IntSLList&, bool*) const;
};

#endif
