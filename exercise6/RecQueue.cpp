// RecQueue.cpp
// CSCI 235 -- Exercise 6: Recursion and Queues
// Complete the four functions below by finishing the TODO sections.
// Submit this file (and only this file) to Gradescope.

#include "RecQueue.hpp"

// Task A
void rotate(std::queue<int>& q, int k) {
    // TODO: base case, then move one element and recurse with a smaller k.
    if (k <= 0 || q.empty()) {
        return;
    }

    while (k > 0) {
        int front = q.front();
        q.pop();
        q.push(front);
        k--;
    }
    (void)q; (void)k;
}

// Task B
void reverseQueue(std::queue<int>& q) {
    // TODO: base case; otherwise take the front element out, reverse what
    // is left, and decide where the element you took out belongs.
    if (q.empty()) {
        return;
    }
    int front = q.front();
    q.pop();
    reverseQueue(q);
    q.push(front);
    (void)q;
}

// Task C
int hotPotato(std::queue<int>& q, int k) {
    // TODO: base case: one person left. Otherwise play one round (k passes,
    // then one person leaves), then recurse on the smaller game.
    if (q.size() == 1) {
        return q.front();
    }
    for (int i = 0; i < k; i++) {
        int front = q.front();
        q.pop();
        q.push(front);
    }
    q.pop();
    (void)q; (void)k;
    return hotPotato(q, k);
}

// Task D
int survivorPosition(int n, int k) {
    // TODO: base case, then express the answer for n people through the
    // answer for n - 1 people.
    if (n == 1) {
        return 0;
    }
    while (n > 1) {
        return (survivorPosition(n - 1, k) + k + 1) % n;
    }
    return 0;
}

