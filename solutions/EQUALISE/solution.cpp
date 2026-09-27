#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two numbers A and B. We can multiply either by 2 any number of times.
 * This means we can transform A into A * 2^x and B into B * 2^y.
 * We want to check if there exist non-negative integers x, y such that A * 2^x = B * 2^y.
 * 
 * This is equivalent to checking if one number can be transformed into the other.
 * Without loss of generality, assume A <= B.
 * We can multiply A by 2 repeatedly until it is either equal to B or exceeds B.
 * If it becomes equal to B, the answer is YES.
 * If it exceeds B, we can never make them equal because multiplying B by 2 
 * would only make the gap larger.
 */

void solve() {
    int A, B;
    cin >> A >> B;

    // Ensure A is the smaller number
    if (A > B) {
        swap(A, B);
    }

    // Keep multiplying the smaller number by 2 until it reaches or exceeds the larger
    while (A < B) {
        A *= 2;
    }

    if (A == B) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}