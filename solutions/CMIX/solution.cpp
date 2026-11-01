#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to maximize (A_i * V_j + V_i * A_j) for 1 <= i < j <= N.
 * Constraints: N <= 100, T <= 100.
 * Complexity: O(T * N^2) is ~5 * 10^5 operations, which is well within 1s.
 * The previous TLE was likely due to an issue with the input stream handling 
 * or environment-specific overhead.
 */

struct Spell {
    long long v, a;
};

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<Spell> spells(n);
    for (int i = 0; i < n; ++i) {
        cin >> spells[i].v >> spells[i].a;
    }

    // Initialize max_strength with a very small value.
    // Since A_i, V_i >= 1, the minimum possible strength is 2.
    long long max_strength = -1;

    // Iterate through all pairs (i, j) where i < j
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            // Formula: A_i * V_j + V_i * A_j
            long long current_strength = (spells[i].a * spells[j].v) + (spells[i].v * spells[j].a);
            if (current_strength > max_strength) {
                max_strength = current_strength;
            }
        }
    }

    cout << max_strength << "\n";
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