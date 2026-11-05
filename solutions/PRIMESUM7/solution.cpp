#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array elements A_i are restricted to {1, 2, 3}.
 * Possible sums of pairs (A_i, A_j) are:
 * 1 + 1 = 2 (Prime)
 * 1 + 2 = 3 (Prime)
 * 1 + 3 = 4 (Not Prime)
 * 2 + 2 = 4 (Not Prime)
 * 2 + 3 = 5 (Prime)
 * 3 + 3 = 6 (Not Prime)
 * 
 * We need to count pairs (i, j) with i < j such that A_i + A_j is in {2, 3, 5}.
 * Let c1, c2, c3 be the counts of 1s, 2s, and 3s in the array.
 * 
 * Pairs with sum 2: (1, 1) -> c1 * (c1 - 1) / 2
 * Pairs with sum 3: (1, 2) -> c1 * c2
 * Pairs with sum 5: (2, 3) -> c2 * c3
 * 
 * Total = (c1 * (c1 - 1) / 2) + (c1 * c2) + (c2 * c3)
 */

void solve() {
    int N;
    cin >> N;
    long long c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 1) c1++;
        else if (val == 2) c2++;
        else if (val == 3) c3++;
    }

    long long ans = 0;
    // Sum 2: (1, 1)
    ans += (c1 * (c1 - 1)) / 2;
    // Sum 3: (1, 2)
    ans += (c1 * c2);
    // Sum 5: (2, 3)
    ans += (c2 * c3);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}