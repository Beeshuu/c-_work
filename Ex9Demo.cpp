// Ex9Demo.cpp
// CSCI 235 -- Exercise 9: Sorting Trace
//
// Provided file -- do not submit this. Build it with:
//
//     g++ -std=c++17 -g Sorting.cpp Ex9Demo.cpp -o ex9demo
//     ./ex9demo
//
// The expected output is in demo_output.txt. Your output should match it
// exactly once all four tasks are done.

#include "Sorting.hpp"

#include <iostream>
#include <string>
#include <vector>

static std::string show(const std::vector<int>& a) {
    std::string s;
    for (std::size_t i = 0; i < a.size(); ++i) {
        if (i > 0) { s += " "; }
        s += std::to_string(a[i]);
    }
    return s;
}

static std::string showCards(const std::vector<Card>& c) {
    std::string s;
    for (std::size_t i = 0; i < c.size(); ++i) {
        if (i > 0) { s += " "; }
        s += std::to_string(c[i].rank);
        s += c[i].suit;
    }
    return s;
}

static void runInt(const char* name, SortStats (*sorter)(std::vector<int>&),
                   std::vector<int> a) {
    std::cout << "  " << name << ": " << show(a) << "  ->  ";
    SortStats st = sorter(a);
    std::cout << show(a) << "   comparisons=" << st.comparisons
              << " moves=" << st.moves << "\n";
}

int main() {
    const std::vector<int> start = {5, 2, 4, 6, 1, 3};
    const std::vector<int> sorted = {1, 2, 3, 4, 5, 6};
    const std::vector<int> reversed = {6, 5, 4, 3, 2, 1};

    std::cout << "=== Task A: selectionSort ===\n";
    runInt("start   ", selectionSort, start);
    runInt("sorted  ", selectionSort, sorted);
    runInt("reversed", selectionSort, reversed);

    std::cout << "\n=== Task B: bubbleSort ===\n";
    runInt("start   ", bubbleSort, start);
    runInt("sorted  ", bubbleSort, sorted);
    runInt("reversed", bubbleSort, reversed);

    std::cout << "\n=== Task C: insertionSort ===\n";
    runInt("start   ", insertionSort, start);
    runInt("sorted  ", insertionSort, sorted);
    runInt("reversed", insertionSort, reversed);

    std::cout << "\n=== Task D: stableSortCards ===\n";
    std::vector<Card> cards = {{5, 'H'}, {3, 'S'}, {5, 'C'}, {2, 'D'}, {3, 'H'}};
    std::cout << "  before: " << showCards(cards) << "\n";
    stableSortCards(cards);
    std::cout << "  after : " << showCards(cards) << "\n";
    return 0;
}