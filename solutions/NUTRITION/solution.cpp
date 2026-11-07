#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N fruits, each with a type A_i and a nutrition value B_i.
 * We can eat at most one fruit of each type.
 * To maximize the total nutrition, for each unique fruit type present,
 * we should pick the fruit with the maximum nutrition value, provided that
 * the value is positive. If the maximum value for a type is negative,
 * we choose not to eat any fruit of that type (contributing 0).
 * 
 * Algorithm:
 * 1. Use an array (or map) to store the maximum nutrition value found so far 
 *    for each fruit type. Since 1 <= A_i <= N, an array of size N+1 is sufficient.
 * 2. Initialize the array with a very small value (or handle initialization carefully).
 * 3. Iterate through all fruits, updating the max value for each type.
 * 4. Sum up all positive max values.
 * 
 * Complexity:
 * Time: O(N) per test case.
 * Space: O(N) to store the max nutrition per type.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    vector<int> B(N);
    for (int i = 0; i < N; ++i) cin >> B[i];

    // max_nutrition[type] stores the highest nutrition value for that type.
    // Initialize with a value smaller than any possible B_i (-100).
    vector<int> max_nutrition(N + 1, -1000);

    for (int i = 0; i < N; ++i) {
        if (B[i] > max_nutrition[A[i]]) {
            max_nutrition[A[i]] = B[i];
        }
    }

    long long total_nutrition = 0;
    for (int i = 1; i <= N; ++i) {
        // Only add if the max nutrition for this type is positive.
        if (max_nutrition[i] > 0) {
            total_nutrition += max_nutrition[i];
        }
    }

    cout << total_nutrition << "\n";
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