#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the sum of the two largest distinct integers in an array.
 * Since the constraints on A_i are small (1 <= A_i <= 1000), we can either:
 * 1. Sort the array and pick the two largest distinct values.
 * 2. Use a set to store unique elements and pick the two largest.
 * 3. Keep track of the largest and second largest distinct values in a single pass.
 * 
 * Given N <= 10^5 and sum of N <= 2*10^5, an O(N log N) or O(N) approach is optimal.
 * Using a set or sorting is efficient enough.
 */

void solve() {
    int N;
    cin >> N;
    
    // Use a set to store unique elements to easily find the two largest
    set<int> distinct_elements;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        distinct_elements.insert(val);
    }
    
    // Since the problem guarantees at least two distinct integers,
    // we can safely access the last two elements of the set.
    auto it = distinct_elements.end();
    int largest = *(--it);
    int second_largest = *(--it);
    
    cout << (long long)largest + second_largest << "\n";
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