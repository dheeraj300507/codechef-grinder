#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Puppy and Sum
 * The function sum(N) is defined as the sum of integers from 1 to N, which is N*(N+1)/2.
 * The function sum(D, N) applies this operation D times.
 * Given the constraints D, N <= 4, the values will be very small, 
 * so standard integer types are sufficient.
 */

long long sum_n(long long n) {
    return n * (n + 1) / 2;
}

void solve() {
    int D;
    long long N;
    cin >> D >> N;
    
    long long current_val = N;
    for (int i = 0; i < D; ++i) {
        current_val = sum_n(current_val);
    }
    
    cout << current_val << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}