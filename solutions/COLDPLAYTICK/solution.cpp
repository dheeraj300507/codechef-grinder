#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Coldplay Tickets
 * Logic: You are buying tickets for yourself and N friends.
 * Total people = N + 1.
 * Cost per ticket = 5000.
 * Total cost = (N + 1) * 5000.
 * Constraints: 1 <= N <= 5.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // The problem description implies a single input N, 
    // but standard competitive programming practice often involves 
    // reading until EOF or handling a specific number of test cases.
    // Based on the provided sample, we read N and output the result.
    if (cin >> n) {
        long long total_people = (long long)n + 1;
        long long total_cost = total_people * 5000;
        cout << total_cost << "\n";
    }

    return 0;
}