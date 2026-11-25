// Sorting.cpp
// CSCI 235 -- Exercise 9: Sorting Trace
// Complete the four functions below by finishing the TODO sections.
// Submit this file (and only this file) to Gradescope.
// You may add your own helper functions here, but do not change the
// signatures of the four required functions.

#include "Sorting.hpp"

#include <cstddef>
#include <utility>   // std::swap

// Task A
SortStats selectionSort(std::vector<int>& a) {
    SortStats stats = {0, 0};
    // TODO: for each position i, keep the INDEX of the smallest element
    // seen so far in a variable named minIdx (start with minIdx = i).
    //   * count one comparison for every test a[j] < a[minIdx];
    //   * after the inner loop, swap only if minIdx != i, and count that swap.
    (void)a;
    return stats;
}

// Task B
SortStats bubbleSort(std::vector<int>& a) {
    SortStats stats = {0, 0};
    // TODO: for i = n-1 down to 1, one pass over j = 0 .. i-1.
    //   * count one comparison for every test a[j] > a[j+1];
    //   * swap the neighbours when they are out of order, and count the swap;
    //   * remember in a bool named swapped whether this pass swapped anything,
    //     and stop after a pass with no swap.
    (void)a;
    return stats;
}

// Task C
SortStats insertionSort(std::vector<int>& a) {
    SortStats stats = {0, 0};
    // TODO: for i = 1 .. n-1, save a[i] in toInsert and let j start at i-1.
    //   * while j >= 0, count one comparison for the test a[j] > toInsert;
    //   * if it is true, shift: a[j+1] = a[j], count one move, decrease j;
    //   * if it is false, stop;
    //   * finally write toInsert into a[j+1].
    (void)a;
    return stats;
}

// Task D
void stableSortCards(std::vector<Card>& cards) {
    // TODO: sort by rank only. Equal ranks must stay in their original order.
    (void)cards;
}