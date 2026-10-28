// BFS_Solver.cpp
#include "BFS_Solver.hpp"
#include <queue>
#include <stack>
#include <vector>
#include <string>

std::stack<Coord> BFS_Solver::getPath() const{
    const std::vector<std::vector<int>> grid = getMaze();
    const Coord start = getStart();
    const Coord end = getEnd();
    std::stack<Coord> path;

    if (!isOpen(grid, start) || !isOpen(grid, end)){
        return path;
    }

    if (start.row == end.row && start.col == end.col){
        path.push(start);
        return path;
    }

    std::vector<std::vector<bool>> visited(grid.size());
    std::vector<std::vector<Coord>> parent(grid.size());
    for (size_t i = 0; i < grid.size(); i++) {
        visited[i].assign(grid[i].size(), false);
        parent[i].assign(grid[i].size(), Coord{-1, -1});
    }

    std::queue<Coord> q;
    visited[start.row][start.col] = true;
    q.push(start);

    bool found = false;
    while (!q.empty() && !found) {
        Coord cur = q.front();
        q.pop();

        const Coord next[4] = {
            {cur.row, cur.col - 1},
            {cur.row, cur.col + 1},
            {cur.row - 1, cur.col},
            {cur.row + 1, cur.col}
        };

        for (const Coord& n : next) {
            if (!isOpen(grid, n) || visited[n.row][n.col]){
                continue;
            }

            visited[n.row][n.col] = true;
            parent[n.row][n.col] = cur;

            if (n.row == end.row && n.col == end.col) {
                found = true;
                break;
            }
            q.push(n);
        }
    }
    if (!found) {
        return path;
    }
    Coord c = end;
    while(true) {
        path.push(c);
        if (c.row == start.row && c.col == start.col){
            break;
        }
        c = parent[c.row][c.col];
    }
    return path;
}

BFS_Solver::BFS_Solver() : Maze_Solver() {}
BFS_Solver::BFS_Solver(const std::vector<std::vector<int>>& maze,
                       const Coord& start, const Coord& end)
    : Maze_Solver(maze, start, end) {}

std::string BFS_Solver::toString() const {
    return "Use Breadth First Search\n" + Maze_Solver::toString();
}
