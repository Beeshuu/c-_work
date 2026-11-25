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
    const std::size_t n = a.size();
    for (std::size_t i = 0; i < n; i++) {
        std::size_t minIdx = i;
        for (std::size_t j = i + 1; j < n; j++) {
            stats.comparisons++;
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            std::swap(a[i], a[minIdx]);
            stats.moves++;
        }
    }
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
    const std::size_t n = a.size();
    for (std::size_t i = n; i > 1; i--) {
        bool swapped = false;
        for (std::size_t j = 0; j < i - 1; j++) {
            stats.comparisons++;
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                stats.moves++;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
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
    const std::size_t n = a.size();
    for (std::size_t i = 1; i < n; i++) {
        const int toInsert = a[i];
        std::ptrdiff_t j = static_cast<std::ptrdiff_t>(i) - 1;
        while (j >= 0) {
            stats.comparisons++;
            if (a[static_cast<std::size_t>(j)] > toInsert) {
                a[static_cast<std::size_t>(j + 1)] = a[static_cast<std::size_t>(j)];
                stats.moves++;
                j--;
            } else {
                break;
            }
        }
        a[static_cast<std::size_t>(j + 1)] = toInsert;
    }
    return stats;
}

// Task D
void stableSortCards(std::vector<Card>& cards) {
    // TODO: sort by rank only. Equal ranks must stay in their original order.
    const std::size_t n = cards.size();
    for (std::size_t i = 1; i < n; i++){
        const Card toInsert = cards[i];
        std::ptrdiff_t j = static_cast<std::ptrdiff_t>(i) - 1;
        while (j >= 0 && cards[static_cast<std::size_t>(j)].rank > toInsert.rank) {
            cards[static_cast<std::size_t>(j + 1)] = cards[static_cast<std::size_t>(j)];
            j--;
        }
        cards[static_cast<std::size_t>(j + 1)] = toInsert;
    }
}