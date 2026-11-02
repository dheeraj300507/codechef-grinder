#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N monsters with initial HP H_i.
 * Each day, we kill one monster if A >= H_i.
 * After each day, all remaining monsters' HP increases by X.
 * 
 * Strategy:
 * To minimize the required attack stat A, we should kill the monsters with the 
 * highest HP first. Why? Because if we kill a monster with higher HP later, 
 * it will have accumulated more HP increases (X per day), making it harder to kill.
 * 
 * Let's sort the monsters in descending order of their initial HP: H_1 >= H_2 >= ... >= H_N.
 * If we kill them in this order:
 * - Day 0: Kill the monster with H_1. Required A >= H_1.
 * - Day 1: Kill the monster with H_2. It has been alive for 1 day, so its HP is H_2 + X. Required A >= H_2 + X.
 * - Day 2: Kill the monster with H_3. It has been alive for 2 days, so its HP is H_3 + 2X. Required A >= H_3 + 2X.
 * - ...
 * - Day i: Kill the monster with H_{i+1}. It has been alive for i days, so its HP is H_{i+1} + i*X. Required A >= H_{i+1} + i*X.
 * 
 * The minimum attack stat A must be at least the maximum of all these values:
 * A = max(H_i + (i-1) * X) for i = 1 to N.
 * 
 * Time Complexity: O(N log N) per test case due to sorting.
 * Space Complexity: O(N) to store the HP values.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // Sort in descending order to kill the strongest monsters first
    sort(H.begin(), H.end(), greater<long long>());

    long long max_A = 0;
    for (int i = 0; i < N; ++i) {
        // The i-th monster (0-indexed) will be killed on day i.
        // Its HP will be H[i] + i * X.
        long long required_A = H[i] + (long long)i * X;
        if (required_A > max_A) {
            max_A = required_A;
        }
    }

    cout << max_A << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}