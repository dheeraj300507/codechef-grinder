#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef can choose to go to the gym on either:
 * 1. All odd-indexed days (1, 3, 5, ...)
 * 2. All even-indexed days (2, 4, 6, ...)
 * 
 * We need to calculate the sum of hours for odd-indexed days and 
 * the sum of hours for even-indexed days, then return the maximum of the two.
 * 
 * Constraints:
 * N <= 100, A_i <= 100.
 * The maximum possible sum is 100 * 100 = 10,000, which fits in a standard int.
 * Using long long is safe practice.
 */

void solve() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    long long odd_sum = 0;
    long long even_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // Days are 1-indexed in the problem description.
        // If i is 0, 2, 4... (even index in 0-based array), it corresponds to day 1, 3, 5...
        if ((i + 1) % 2 != 0) {
            odd_sum += A[i];
        } else {
            even_sum += A[i];
        }
    }
    
    cout << max(odd_sum, even_sum) << "\n";
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