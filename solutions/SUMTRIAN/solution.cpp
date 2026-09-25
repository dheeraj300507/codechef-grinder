#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * This is a classic dynamic programming problem. We are given a triangle of numbers
 * and need to find the path from top to bottom that maximizes the sum.
 * 
 * Let dp[i][j] be the maximum path sum starting from the top to the element at row i, column j.
 * The recurrence relation is:
 * dp[i][j] = a[i][j] + max(dp[i-1][j-1], dp[i-1][j])
 * 
 * Alternatively, we can solve it bottom-up to save space and simplify logic:
 * Let dp[i][j] be the maximum path sum from (i, j) to the base.
 * dp[i][j] = a[i][j] + max(dp[i+1][j], dp[i+1][j+1])
 * 
 * Given N < 100, an O(N^2) approach per test case is perfectly efficient.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;

    // Using a 2D vector to store the triangle
    vector<vector<int>> triangle(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> triangle[i][j];
        }
    }

    // Bottom-up DP approach
    // We modify the triangle in-place to store the max path sums
    // Start from the second to last row and move upwards
    for (int i = N - 2; i >= 0; --i) {
        for (int j = 0; j <= i; ++j) {
            triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
        }
    }

    // The result is at the top of the triangle
    cout << triangle[0][0] << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}