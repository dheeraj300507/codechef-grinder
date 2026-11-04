#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An inversion is a pair (i, j) such that i < j and A[i] > A[j].
 * A local inversion is a pair (i, i+1) such that A[i] > A[i+1].
 * 
 * Every local inversion is by definition an inversion.
 * Therefore, the number of local inversions is always less than or equal to 
 * the total number of inversions.
 * The permutation is "good" if and only if the number of inversions equals 
 * the number of local inversions.
 * 
 * Constraints: N <= 100.
 * An O(N^2) approach to count total inversions and an O(N) approach to count 
 * local inversions will easily pass within the 1s time limit.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int total_inversions = 0;
    int local_inversions = 0;

    // Count total inversions: O(N^2)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] > a[j]) {
                total_inversions++;
            }
        }
    }

    // Count local inversions: O(N)
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            local_inversions++;
        }
    }

    if (total_inversions == local_inversions) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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