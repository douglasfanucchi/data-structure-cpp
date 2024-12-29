#include <Maze.hpp>

Maze::Maze(int n) : GraphLinkedList(n) {}

bool Maze::solveRecursive(int v, int end, IntSLList &path, bool* visited) const {
    visited[v] = true;
    if (v == end) {
        path.addToHead(v);
        return true;
    }
    IntSLList *adjacents = this->_adjacents[v];
    while (!adjacents->isEmpty()) {
        int w  = adjacents->deleteFromHead();
        if (visited[w] || !Maze::solveRecursive(w, end, path, visited)) {
            continue;
        }
        path.addToHead(v);
        return true;
    }
    return false;
}

IntSLList Maze::solve(int start, int end) const {
    IntSLList path;
    bool *visited = new bool[this->_n];
    for (int i = 0; i < this->_n; i++)
        visited[i] = false;
    Maze::solveRecursive(start, end, path, visited);
    delete[] visited;
    return path;
}
