// DFS_Solver.cpp
#include "DFS_Solver.hpp"
#include <stack>
#include <vector>
#include <string>

std::stack<Coord> findPath(const std::vector<std::vector<int>>& grid, std::vector<std::vector<bool>>& visited, const Coord& cur, const Coord& end) {
    if(!Maze_Solver::isOpen(grid, cur)){
        return std::stack<Coord>();
    }

    if(visited[cur.row][cur.col]){
        return std::stack<Coord>();
    }
    visited[cur.row][cur.col] = true;

    if ((cur.row == end.row) && (cur.col == end.col)) {
        std::stack<Coord> s;
        s.push(cur);
        return s;
    }

    const Coord next[4] = {
        {cur.row, cur.col - 1},
        {cur.row, cur.col + 1},
        {cur.row - 1, cur.col},
        {cur.row + 1, cur.col}
    };

    for (const Coord& n : next) {
        std::stack<Coord> result = findPath(grid, visited, n, end);
        if (!result.empty()) {
            result.push(cur);
            return result;
        }
    }
    return std::stack<Coord>();
}

std::stack<Coord> DFS_Solver::getPath() const {
    const std::vector<std::vector<int>> grid = getMaze();

    std::vector<std::vector<bool>> visited(grid.size());
    for (size_t i = 0; i < grid.size(); i++){
        visited[i].assign(grid[i].size(), false);
    }
    return findPath(grid, visited, getStart(), getEnd());
}

DFS_Solver::DFS_Solver() : Maze_Solver() {}
DFS_Solver::DFS_Solver(const std::vector<std::vector<int>>& maze,
                       const Coord& start, const Coord& end)
    : Maze_Solver(maze, start, end) {}

std::string DFS_Solver::toString() const {
    return "Use Depth First Search\n" + Maze_Solver::toString();
}