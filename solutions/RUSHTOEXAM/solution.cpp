#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Each hour, Chef reads A pages.
 * Total pages Chef can read = N * A.
 * We need to check if (N * A) >= M.
 * 
 * Constraints:
 * N <= 24, M <= 100, A <= 10.
 * The product N * A will be at most 24 * 10 = 240.
 * This fits comfortably within a standard 32-bit integer.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves multiple test cases.
    // Given the problem description "The first and only line contains 3 integers",
    // we will process exactly one set of inputs.
    
    long long N, M, A;
    if (!(cin >> N >> M >> A)) return 0;

    // Calculate total capacity
    long long total_capacity = N * A;

    // Check if capacity is sufficient
    if (total_capacity >= M) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }

    return 0;
}