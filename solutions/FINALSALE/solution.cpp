#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The total sales if closing on day k (1-indexed) is:
 * (Sum of A[1...k-1]) + 2 * A[k]
 * = (Sum of A[1...k]) + A[k]
 * 
 * Complexity: O(N) time, O(N) space.
 * Given the constraints and the TLE, we ensure fast I/O and efficient memory usage.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Using a vector is fine, but we ensure we don't reallocate unnecessarily
    // if N is large.
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    long long current_prefix_sum = 0;
    long long max_total_sales = 0;

    for (int i = 0; i < N; ++i) {
        current_prefix_sum += A[i];
        long long current_total = current_prefix_sum + A[i];
        if (current_total > max_total_sales) {
            max_total_sales = current_total;
        }
    }

    cout << max_total_sales << "\n";
}

int main() {
    // Optimization for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}