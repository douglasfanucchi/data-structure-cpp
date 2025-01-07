#include <Maze.hpp>
#include <Queue.hpp>

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

int Maze::minDistance(int start, int end) const {
    Queue<int> queue;
    if (!this->isValidVertex(start) || !this->isValidVertex(end)) {
        throw "invalid vertex";
    }
    bool *visited = new bool[this->_n];
    int *distance = new int[this->_n];
    int result = -1;
    for (int v = 0; v < this->_n; v++) {
        visited[v] = false;
        distance[v] = 0;
    }
    queue.enqueue(start);
    visited[start] = true;
    while (!queue.isEmpty()) {
        int v = queue.dequeue();
        IntSLList *adjacents = this->_adjacents[v];
        if (adjacents->isEmpty()) {
            continue;
        }
        do
        {
            int w = adjacents->current();
            if (visited[w]) {
                continue;
            }
            distance[w] = distance[v] + 1;
            queue.enqueue(w);
            visited[w] = true;
        } while (adjacents->next());
    }
    result = distance[end];
    delete[] visited;
    delete[] distance;
    return result;
}
