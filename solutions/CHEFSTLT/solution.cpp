#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two strings S1 and S2 of equal length containing lowercase letters and '?'.
 * '?' can be replaced by any lowercase letter.
 * 
 * Minimal difference:
 * For each position i:
 * - If S1[i] == '?' or S2[i] == '?', we can always make them equal (e.g., if S1[i] == '?', 
 *   set it to S2[i]; if both are '?', set both to 'a').
 * - If both are letters and S1[i] != S2[i], they contribute 1 to the difference.
 * - If both are letters and S1[i] == S2[i], they contribute 0.
 * 
 * Maximal difference:
 * For each position i:
 * - If S1[i] == '?' or S2[i] == '?', we can always make them different (e.g., if S1[i] == '?',
 *   set it to a letter different from S2[i]).
 * - If both are letters and S1[i] != S2[i], they contribute 1.
 * - If both are letters and S1[i] == S2[i], they contribute 0.
 */

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int min_diff = 0;
    int max_diff = 0;
    int n = s1.length();
    
    for (int i = 0; i < n; ++i) {
        if (s1[i] == '?' || s2[i] == '?') {
            // For min: we can make them equal, so no difference added.
            // For max: we can make them different, so 1 difference added.
            max_diff++;
        } else {
            // Both are letters.
            if (s1[i] != s2[i]) {
                min_diff++;
                max_diff++;
            }
        }
    }
    
    cout << min_diff << " " << max_diff << "\n";
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