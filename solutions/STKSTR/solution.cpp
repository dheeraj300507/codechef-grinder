#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of length N and a multiplier X.
 * We can multiply exactly one element A[i] by X.
 * We want to maximize the length of the longest non-decreasing subarray.
 * 
 * Since N is small (sum of N <= 1000), we can iterate through every possible 
 * index i (0 to N-1) where we apply the operation A[i] *= X.
 * For each modified array, we calculate the streak value in O(N).
 * Total complexity: O(N^2), which is well within the limits (10^6 operations).
 */

int get_streak(const vector<long long>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    int max_streak = 1;
    int current_streak = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= arr[i - 1]) {
            current_streak++;
        } else {
            max_streak = max(max_streak, current_streak);
            current_streak = 1;
        }
    }
    max_streak = max(max_streak, current_streak);
    return max_streak;
}

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Case 1: No operation performed
    int max_val = get_streak(A);

    // Case 2: Try modifying each index i
    for (int i = 0; i < N; ++i) {
        long long original = A[i];
        A[i] *= X;
        max_val = max(max_val, get_streak(A));
        A[i] = original; // backtrack
    }

    cout << max_val << "\n";
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