#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 11 problems, but only problems 1 through 8 are scorable.
 * For each scorable problem, we need to find the maximum score achieved.
 * The total score is the sum of these maximums.
 * 
 * Approach:
 * 1. Use an array of size 9 (indices 1-8) to store the maximum score for each scorable problem.
 * 2. Initialize the array with 0.
 * 3. For each submission (p, s):
 *    - If p <= 8, update max_scores[p] = max(max_scores[p], s).
 * 4. Sum the values in the array from index 1 to 8.
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the number of submissions.
 * Space: O(1) as we only store scores for 8 problems.
 */

void solve() {
    int n;
    cin >> n;
    
    // max_scores[i] stores the best score for problem i (1-8)
    vector<int> max_scores(9, 0);
    
    for (int i = 0; i < n; ++i) {
        int p, s;
        cin >> p >> s;
        // Only consider problems 1 through 8
        if (p >= 1 && p <= 8) {
            if (s > max_scores[p]) {
                max_scores[p] = s;
            }
        }
    }
    
    long long total_score = 0;
    for (int i = 1; i <= 8; ++i) {
        total_score += max_scores[i];
    }
    
    cout << total_score << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}