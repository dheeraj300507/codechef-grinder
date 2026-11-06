#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks us to calculate the total time taken to cool a dessert from X to Y.
 * For each degree reduction from K to K-1, the time taken is ceil(K / 10.0).
 * In integer arithmetic, ceil(K / 10.0) is equivalent to (K + 9) / 10.
 * 
 * Constraints:
 * 1 <= T <= 5000
 * 1 <= Y < X <= 100
 * 
 * Since X is at most 100, a simple loop for each test case is highly efficient.
 * Total complexity per test case: O(X - Y), which is at most O(100).
 * Total complexity for T test cases: O(T * (X - Y)), which is at most 500,000 operations.
 * This easily fits within the 1s time limit.
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;

    long long total_time = 0;
    
    // Iterate from current temperature X down to Y+1
    // In each step, calculate the time to go from current_temp to current_temp - 1
    for (int current_temp = X; current_temp > Y; --current_temp) {
        // ceil(current_temp / 10.0)
        int time_for_step = (current_temp + 9) / 10;
        total_time += time_for_step;
    }
    
    cout << total_time << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}