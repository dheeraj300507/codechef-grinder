#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is happy if the bus is NOT full.
 * The bus is full if the number of students (N) equals the number of seats (M).
 * The bus is not full if the number of students (N) is strictly less than the number of seats (M).
 * Given N <= M, the condition for Chef to be happy is N < M.
 * If N == M, the bus is full, and Chef is not happy.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case per run based on the input format,
    // but standard competitive programming practice often involves handling multiple test cases.
    // Given the constraints and format, we read N and M.
    long long N, M;
    if (cin >> N >> M) {
        if (N < M) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}