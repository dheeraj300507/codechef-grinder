#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A staircase array satisfies A[i] - A[i-1] = 1.
 * This implies A[i] = A[0] + i.
 * Rearranging, we get A[i] - i = A[0].
 * 
 * If we define a new array B where B[i] = A[i] - i, then for the array to be a 
 * staircase, all elements in B must be equal to the same constant (A[0]).
 * 
 * To minimize the number of edits, we want to keep the maximum number of elements 
 * that already satisfy this condition. This is equivalent to finding the most 
 * frequent value in array B.
 * 
 * Let count be the frequency of the most frequent value in B.
 * The minimum edits required = N - count.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    // Use a map to count frequencies of (A[i] - i)
    // Since N <= 2*10^5, a map or unordered_map is efficient.
    // Given the constraints and time limit, a map is safe.
    map<long long, int> counts;
    int max_freq = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        long long val = A[i] - i;
        counts[val]++;
        if (counts[val] > max_freq) {
            max_freq = counts[val];
        }
    }
    
    cout << (N - max_freq) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}