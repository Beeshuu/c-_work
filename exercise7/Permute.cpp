// Permute.cpp
// CSCI 235 -- Exercise 7: Permutations
// Complete the four functions below by finishing the TODO sections.
// Submit this file (and only this file) to Gradescope.

#include "Permute.hpp"

#include <utility>   // std::swap

// Task A
long long factorial(int n) {
    // TODO: base case, then a recursive call on a smaller n.
    if (n <= 20 && n >= 0) {
        if (n == 0) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    } else {
        return -1;
    }
}

// Task B
void permute(std::vector<int>& v, std::size_t k,
             std::vector<std::vector<int>>& out) {
    // TODO:
    //   * base case: nothing left to arrange.
    //   * otherwise, for each choice for position k: put that choice at
    //     position k, recurse on the rest, then undo what you did so the next
    //     choice starts from the same vector.
    if (k == v.size()) {
        out.push_back(v);
    } else {
        for (std::size_t i = k; i < v.size(); i++) {
            std::swap(v[k], v[i]);
            permute(v, k + 1, out);
            std::swap(v[k], v[i]);
        }
    }
}

// Task C
std::vector<std::vector<int>> allPermutations(std::vector<int> v) {
    // TODO: collect the results of Task B.
    std::vector<std::vector<int>> out;
    permute(v, 0, out);
    return out;
}

// Task D
int countDerangements(std::vector<int>& v, const std::vector<int>& original,
                      std::size_t k) {
    // TODO: like Task B, but count instead of storing, and do not follow a
    // choice that puts an element in its original position
    if (k == v.size()) {
        return 1;
    } else {
        int count = 0;
        for (std::size_t i = k; i < v.size(); i++) {
            if (v[i] != original [k]) {
                std::swap(v[k], v[i]);
                count += countDerangements(v, original, k + 1);
                std::swap(v[k], v[i]);
            }
        }
        return count;
    }
}