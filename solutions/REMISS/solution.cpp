#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Guard 1 counts A entries.
 * Guard 2 counts B entries.
 * Since at least one guard is always awake, the total number of entries 
 * must be at least the maximum of the two counts (because the guard who 
 * was awake saw at least that many).
 * The maximum possible number of entries is the sum of the two counts 
 * (assuming they never overlapped in their counting, i.e., they were 
 * awake at different times).
 * 
 * Minimum entries = max(A, B)
 * Maximum entries = A + B
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b;
        cin >> a >> b;
        
        // Calculate minimum and maximum
        long long min_entries = max(a, b);
        long long max_entries = a + b;
        
        cout << min_entries << " " << max_entries << "\n";
    }
    
    return 0;
}