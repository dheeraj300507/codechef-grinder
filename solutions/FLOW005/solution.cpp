#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Smallest Numbers of Notes (FLOW005)
 * Strategy: Greedy approach.
 * Since the denominations are {1, 2, 5, 10, 50, 100}, and each larger denomination
 * is a multiple of smaller ones (or can be formed optimally), we can always
 * pick the largest possible denomination first to minimize the total count.
 */

void solve() {
    int n;
    cin >> n;
    
    int denominations[] = {100, 50, 10, 5, 2, 1};
    int count = 0;
    
    for (int i = 0; i < 6; ++i) {
        if (n >= denominations[i]) {
            count += n / denominations[i];
            n %= denominations[i];
        }
    }
    
    cout << count << "\n";
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