#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to maximize the sum of N-1 elements by skipping exactly one day.
 * Let S be the sum of all elements. If we skip element A_i, the sum is S - A_i.
 * To maximize (S - A_i), we must minimize A_i.
 * 
 * Complexity:
 * Time: O(N) per test case.
 * Space: O(1) auxiliary space.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long sum = 0;
    // Initialize min_val with a value larger than any possible A_i (max 100)
    int min_val = 200; 
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        sum += val;
        if (val < min_val) {
            min_val = val;
        }
    }
    
    // The result is the total sum minus the smallest element
    cout << (sum - min_val) << "\n";
}

int main() {
    // Fast I/O to handle large input sizes efficiently
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}