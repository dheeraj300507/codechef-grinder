#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N dishes with preparation times C_i and two burners.
 * Since N is very small (N <= 4), we can solve this using recursion or bitmasking.
 * We want to partition the set of dishes into two subsets (burner 1 and burner 2)
 * such that the maximum of the sum of times in each subset is minimized.
 * 
 * Let S be the total sum of all C_i.
 * Let S1 be the sum of times on burner 1.
 * Then the time taken is max(S1, S - S1).
 * We want to minimize this value.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    int min_time = 1e9;

    // Since N is at most 4, we can iterate through all 2^N possible 
    // assignments of dishes to two burners using a bitmask.
    for (int i = 0; i < (1 << N); ++i) {
        int burner1 = 0;
        int burner2 = 0;
        for (int j = 0; j < N; ++j) {
            if ((i >> j) & 1) {
                burner1 += C[j];
            } else {
                burner2 += C[j];
            }
        }
        min_time = min(min_time, max(burner1, burner2));
    }

    cout << min_time << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}