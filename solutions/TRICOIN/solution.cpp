#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form a triangle of height 'h', we need:
 * 1 + 2 + 3 + ... + h = h * (h + 1) / 2 coins.
 * We are given N coins and want to find the maximum 'h' such that:
 * h * (h + 1) / 2 <= N
 * h^2 + h - 2N <= 0
 * 
 * Using the quadratic formula for h^2 + h - 2N = 0:
 * h = (-1 + sqrt(1 + 8N)) / 2
 * Since we need the largest integer h, we take the floor of this value.
 * 
 * Constraints: N <= 10^9. 
 * 8 * N can be up to 8 * 10^9, which fits in a 64-bit integer (long long).
 */

void solve() {
    long long n;
    cin >> n;
    
    // We need to find the largest h such that h*(h+1)/2 <= n
    // Binary search approach is robust and avoids precision issues with sqrt
    long long low = 1, high = 2000000000LL; // sqrt(2 * 10^9) is approx 45000, 2e9 is safe upper bound
    long long ans = 0;
    
    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (mid * (mid + 1) / 2 <= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}