#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to maximize the sum of squares of group sums: X_1^2 + X_2^2 + ... + X_K^2.
 * Mathematically, for any set of numbers, the sum of squares is maximized by 
 * grouping all positive numbers together and all negative numbers together.
 * 
 * Let P be the set of positive numbers (including zeros) and N be the set of negative numbers.
 * Case 1: If both P and N are non-empty, we have two groups:
 *         Group 1: All positive numbers (sum = sum(P))
 *         Group 2: All negative numbers (sum = sum(N))
 *         Total score = (sum(P))^2 + (sum(N))^2.
 *         The sizes are |P| and |N|.
 *         Max size = max(|P|, |N|), Min size = min(|P|, |N|).
 * 
 * Case 2: If only P is non-empty (or only N is non-empty), we can only form one group.
 *         Total score = (sum(all))^2.
 *         Size = N.
 *         Max size = N, Min size = N.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    int pos_count = 0;
    int neg_count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] >= 0) {
            pos_count++;
        } else {
            neg_count++;
        }
    }

    if (pos_count == 0 || neg_count == 0) {
        // All numbers are non-negative or all are negative.
        // The maximum score is obtained by putting everyone in one group.
        cout << n << " " << n << "\n";
    } else {
        // We have both positive and negative numbers.
        // To maximize the sum of squares, we group all positives together
        // and all negatives together.
        int max_s = max(pos_count, neg_count);
        int min_s = min(pos_count, neg_count);
        cout << max_s << " " << min_s << "\n";
    }
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