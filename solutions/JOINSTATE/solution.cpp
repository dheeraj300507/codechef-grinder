#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and a threshold M.
 * We need to partition the array into the maximum number of contiguous subarrays
 * such that the sum of each subarray is at least M.
 * 
 * Greedy Strategy:
 * Iterate through the array and maintain a running sum.
 * As soon as the running sum reaches or exceeds M, we have formed a valid state.
 * We increment our count of states and reset the running sum to 0.
 * Any remaining elements after the last valid state are effectively merged into 
 * the last valid state (or if they don't form a sum >= M on their own, they 
 * must be part of the previous state to satisfy the condition).
 * 
 * Since we want to maximize the number of states, we should "close" a state 
 * as soon as the sum >= M.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int state_count = 0;
    long long current_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        current_sum += A[i];
        if (current_sum >= M) {
            state_count++;
            current_sum = 0;
        }
    }
    
    cout << state_count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}