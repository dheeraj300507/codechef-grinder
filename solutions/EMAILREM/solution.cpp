#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N total participants and U participants who opted out.
 * The number of participants to send emails to is simply N - U.
 * 
 * Constraints:
 * 1 <= U < N <= 10^5
 * The result will fit in a standard integer, but using long long is safe practice.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice often involves reading until EOF
    // or handling a specific number of test cases. Given the problem description:
    // "The first and only line of input will contain a single line..."
    // We will read N and U once.
    
    long long N, U;
    if (cin >> N >> U) {
        cout << (N - U) << "\n";
    }

    return 0;
}