#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A problem is 'good' if every judge gives a score strictly greater than 4.
 * This means for all i, S_i > 4.
 * If any S_i <= 4, the problem is not 'good'.
 * 
 * Time Complexity: O(N) per test case, O(sum of N) total.
 * Space Complexity: O(1) auxiliary space.
 */

void solve() {
    int n;
    cin >> n;
    
    bool is_good = true;
    for (int i = 0; i < n; ++i) {
        int score;
        cin >> score;
        // If any score is 4 or less, the condition is violated.
        if (score <= 4) {
            is_good = false;
        }
    }
    
    if (is_good) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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