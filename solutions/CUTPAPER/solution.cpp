#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a square paper of size N x N.
 * We want to cut out squares of size K x K.
 * Along one side of length N, we can fit floor(N / K) squares of length K.
 * Since the paper is a square, we can fit floor(N / K) squares along the width
 * and floor(N / K) squares along the height.
 * The total number of K x K squares is (N / K) * (N / K).
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // Calculate how many squares fit along one dimension
        long long side_count = n / k;

        // Total squares is the product of squares along both dimensions
        long long total_squares = side_count * side_count;

        cout << total_squares << "\n";
    }

    return 0;
}