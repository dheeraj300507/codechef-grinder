#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * To reduce an array of N elements to 1 element, we must perform N-1 operations.
 * In each operation, we remove the larger of two adjacent elements and pay the cost 
 * of the smaller one. To minimize the total cost, we want to ensure that the 
 * smallest element in the array is involved in every single operation.
 * 
 * Since we can always choose to pair the global minimum with any of its neighbors,
 * we can eliminate all other N-1 elements using the global minimum as the cost 
 * for each operation.
 * 
 * Total Cost = (N - 1) * min_element.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long min_val = 200000; // Initialize with a value larger than max Ai (10^5)
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        if (val < min_val) {
            min_val = val;
        }
    }
    
    // The minimum cost is (N-1) * min_val.
    // N <= 50,000 and Ai <= 100,000, so result can be up to 5 * 10^9.
    // This exceeds the range of a 32-bit signed integer, so long long is necessary.
    long long result = (long long)(n - 1) * min_val;
    cout << result << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}