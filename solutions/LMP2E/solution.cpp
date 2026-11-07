#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Chef is initially without a jacket.
 * - Without jacket: comfortable if T >= A.
 * - With jacket: comfortable if T <= B.
 * - If T < A, Chef MUST wear a jacket.
 * - If T > B, Chef MUST remove the jacket.
 * - If A <= T <= B, Chef can be either with or without a jacket.
 * 
 * We want to minimize the number of times Chef puts on a jacket.
 * Let 'wearing' be a boolean state (false = no jacket, true = jacket).
 * Initially, wearing = false.
 * For each day i:
 * 1. If T[i] < A: Chef must wear a jacket. If not currently wearing, increment count and set wearing = true.
 * 2. If T[i] > B: Chef must remove the jacket. Set wearing = false.
 * 3. If A <= T[i] <= B: Chef can stay in current state.
 */

void solve() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }

    int wear_count = 0;
    bool wearing = false;

    for (int i = 0; i < N; ++i) {
        if (T[i] < A) {
            // Must wear jacket
            if (!wearing) {
                wear_count++;
                wearing = true;
            }
        } else if (T[i] > B) {
            // Must remove jacket
            wearing = false;
        } else {
            // A <= T[i] <= B
            // Chef can stay in current state, no action needed.
            continue;
        }
    }
    cout << wear_count << "\n";
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