#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N coins with values v_1, v_2, ..., v_N.
 * We need to select two distinct coins such that the absolute difference 
 * between their values is minimized.
 * 
 * Approach:
 * 1. If we sort the array of coin values, the minimum difference between any 
 *    two elements must occur between two adjacent elements in the sorted array.
 * 2. Proof: Suppose we have sorted values a_1 <= a_2 <= ... <= a_N.
 *    For any i < j, the difference a_j - a_i = (a_j - a_{j-1}) + (a_{j-1} - a_{j-2}) + ... + (a_{i+1} - a_i).
 *    Since all differences (a_{k+1} - a_k) are non-negative, the sum is at least 
 *    as large as any individual adjacent difference.
 * 3. Algorithm:
 *    a. Sort the array of coin values.
 *    b. Iterate through the sorted array from index 0 to N-2.
 *    c. Calculate the difference between adjacent elements: v[i+1] - v[i].
 *    d. Keep track of the minimum difference found.
 * 
 * Complexity:
 * - Time: O(N log N) due to sorting, where N is the number of coins.
 * - Space: O(N) to store the coin values.
 * - Constraints: Sum of N <= 5*10^5, which fits well within the 1s time limit.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    
    // Sort the coin values to bring the closest values next to each other
    sort(v.begin(), v.end());
    
    // Initialize min_diff with a large value
    long long min_diff = 2000000; // Since max v_i is 10^6, difference <= 10^6
    
    // Find the minimum difference between adjacent elements
    for (int i = 0; i < N - 1; ++i) {
        long long diff = v[i + 1] - v[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
        // Optimization: if diff is 0, it's the smallest possible absolute difference
        if (min_diff == 0) break;
    }
    
    cout << min_diff << "\n";
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