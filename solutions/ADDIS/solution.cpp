#include <bits/stdc++.h>
using namespace std;

/**
 * The problem asks to minimize the maximum frequency of any element in B.
 * For any X, freq_B(Y) = count(Y-X) + count(Y+X).
 * If we pick X such that for all i, j, A_i + X != A_j - X (i.e., 2X != A_j - A_i),
 * then for any Y, at most one of (Y-X) or (Y+X) can be in A.
 * Thus, freq_B(Y) = count(Y-X) or count(Y+X).
 * The max frequency will be the same as the original max frequency.
 * However, we can split the most frequent element V by choosing X such that
 * we move half of the V's to V+X and half to V-X.
 */

void solve() {
    int N;
    cin >> N;
    map<int, int> counts;
    int max_f = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        counts[a]++;
        max_f = max(max_f, counts[a]);
    }
    // We can always achieve ceil(max_f / 2.0) by splitting the most frequent element.
    cout << (max_f + 1) / 2 << "\n";
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