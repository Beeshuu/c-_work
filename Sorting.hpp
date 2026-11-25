// Sorting.hpp
// CSCI 235 -- Exercise 9: Sorting Trace
// Provided file -- do not modify. Gradescope compiles your submission
// against the original version of this file.

#ifndef SORTING_HPP
#define SORTING_HPP

#include <vector>

// What a sort reports about its own work.
//   comparisons : how many times the sort compared two ELEMENTS of the array
//                 (a comparison of two indices, such as j >= 0, does not count).
//   moves       : selectionSort and bubbleSort: the number of SWAPS performed.
//                 insertionSort: the number of SHIFTS (an element copied one
//                 place to the right). Each task below says exactly what to count.
struct SortStats {
    int comparisons;
    int moves;
};

// Task A -- selection sort. Sort a into increasing order.
// Pass i (i = 0, 1, ..., n-2) finds the index of the smallest element of
// a[i..n-1] in the variable minIdx and swaps it into position i, but only
// when minIdx != i (never swap an element with itself).
//   comparisons: one for every test  a[j] < a[minIdx]   (always n(n-1)/2)
//   moves:       the number of swaps actually performed
// An array with 0 or 1 elements returns {0, 0}.
SortStats selectionSort(std::vector<int>& a);

// Task B -- bubble sort with an early exit.
// Pass i (i = n-1, n-2, ..., 1) compares neighbours a[j] and a[j+1] for
// j = 0, 1, ..., i-1 and swaps them when a[j] > a[j+1]. If a whole pass
// makes no swap, the array is sorted: stop at once.
//   comparisons: one for every test  a[j] > a[j+1]
//   moves:       the number of swaps performed
// An array with 0 or 1 elements returns {0, 0}.
SortStats bubbleSort(std::vector<int>& a);

// Task C -- insertion sort. For i = 1, 2, ..., n-1: save a[i] in toInsert,
// shift every element of a[0..i-1] that is STRICTLY greater than toInsert
// one place to the right, and put toInsert into the gap.
//   comparisons: one for every test  a[j] > toInsert
//                (the test  j >= 0  is not a comparison of elements)
//   moves:       the number of shifts (writes of the form a[j+1] = a[j]);
//                placing toInsert into the gap is NOT counted
// An array with 0 or 1 elements returns {0, 0}.
SortStats insertionSort(std::vector<int>& a);

// Task D -- a STABLE sort of cards by rank.
struct Card {
    int  rank;     // the sort key, for example 2 .. 14
    char suit;     // 'C', 'D', 'H' or 'S'; NOT part of the comparison
};
// Sort cards into increasing order of rank. Cards of equal rank must keep the
// order they had before the sort (that is what STABLE means).
// Write your own sort (insertion sort with a strict comparison works well).
// Do not call std::sort, std::stable_sort or std::partial_sort, and do not use a
// sorted container (std::multiset, std::multimap, std::priority_queue).
void stableSortCards(std::vector<Card>& cards);

#endif