#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. The length Ni must be odd for a unique center to exist.
 * 2. The first element must be 1.
 * 3. The sequence must increase by 1 until the center, then decrease by 1.
 * 4. This implies the sequence must be 1, 2, 3, ..., (Ni+1)/2, ..., 3, 2, 1.
 * 
 * Time Complexity: O(Ni) per test case, total O(S * Ni).
 * Space Complexity: O(Ni) to store the strip.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    // Condition 1: Length must be odd to have a unique center
    if (n % 2 == 0) {
        cout << "no" << "\n";
        return;
    }

    // Condition 2: Must start and end with 1
    if (h[0] != 1 || h[n - 1] != 1) {
        cout << "no" << "\n";
        return;
    }

    int center_idx = n / 2;
    
    // Check increasing part
    for (int i = 0; i < center_idx; ++i) {
        if (h[i + 1] != h[i] + 1) {
            cout << "no" << "\n";
            return;
        }
    }

    // Check decreasing part
    for (int i = center_idx; i < n - 1; ++i) {
        if (h[i + 1] != h[i] - 1) {
            cout << "no" << "\n";
            return;
        }
    }

    cout << "yes" << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s;
    if (!(cin >> s)) return 0;
    while (s--) {
        solve();
    }
    return 0;
}