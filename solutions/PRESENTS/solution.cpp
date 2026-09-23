#include <iostream>

using namespace std;

/**
 * Problem Logic:
 * For every 5 gifts, Chef pays for 4.
 * Number of full sets of 5 = N / 5.
 * Remaining gifts = N % 5.
 * Total cost = (N / 5) * 4 + (N % 5).
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;

    long long sets = n / 5;
    long long remainder = n % 5;
    
    long long total_cost = (sets * 4) + remainder;
    
    cout << total_cost << "\n";
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