// main.cpp
#include "Maze_Solver.hpp"
#include "DFS_Solver.hpp"
#include "BFS_Solver.hpp"
#include <iostream>
#include <string>

int main() {
    // 0 = open, 1 = wall
    std::vector<std::vector<int>> maze = {
        {0, 0, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0}
    };

    DFS_Solver dfs(maze, {0, 0}, {3, 3});

    std::stack<Coord> path = dfs.getPath();
    while (!path.empty()) {
        std::cout << "(" << path.top().row << "," << path.top().col << ") ";
        path.pop();
    }
    std::cout << "\n";

    std::cout << "reachable: " << dfs.reachable() << "\n";

    Maze_Solver* solver = &dfs;          // polymorphism check
    std::cout << "via base pointer: " << solver->reachable() << "\n";

    return 0;
}