#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of N elements and we perform K removals.
 * Each removal must be either the current first or current last element.
 * After K removals, we are left with N - K elements.
 * 
 * If we remove K elements in total, we are essentially choosing a contiguous 
 * subarray of length (N - K).
 * Let M = N - K be the number of elements remaining.
 * The remaining elements will form a contiguous subarray A[i...i+M-1] 
 * for some 0 <= i <= K.
 * 
 * To maximize the sum of the remaining elements, we simply need to find the 
 * maximum sum of any contiguous subarray of length (N - K).
 * 
 * Constraints: N <= 100, so an O(N^2) approach is perfectly fine.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int remaining_len = N - K;
    
    // Calculate prefix sums to compute subarray sums in O(1)
    vector<long long> prefix_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
    }

    long long max_sum = -1; // Since A_i >= 1, sum is always positive

    // Iterate over all possible starting positions of the remaining subarray
    // The subarray starts at index i and has length remaining_len.
    // The end index is i + remaining_len - 1.
    // Valid i range: 0 to N - remaining_len (which is K)
    for (int i = 0; i <= K; ++i) {
        long long current_sum = prefix_sum[i + remaining_len] - prefix_sum[i];
        if (max_sum == -1 || current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    cout << max_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}