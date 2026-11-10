#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef starts at index 1. He moves from i to i+1.
 * Conditions for moving from H[i] to H[i+1]:
 * 1. If H[i+1] == H[i]: Always possible.
 * 2. If H[i+1] > H[i]: Possible if H[i+1] - H[i] <= U.
 * 3. If H[i+1] < H[i]: 
 *    a. Possible if H[i] - H[i+1] <= D.
 *    b. If H[i] - H[i+1] > D, he can use a parachute (only once).
 * 
 * We need to find the rightmost index reachable. Since we want to go as far as possible,
 * we should greedily move forward. If we encounter a jump that requires a parachute,
 * we use it if we haven't already. If we encounter a jump that is impossible even with
 * a parachute, we stop.
 */

void solve() {
    int N;
    long long U, D;
    cin >> N >> U >> D;
    vector<long long> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    bool parachute_used = false;
    int current_hill = 0; // 0-indexed

    for (int i = 0; i < N - 1; ++i) {
        if (H[i+1] == H[i]) {
            current_hill = i + 1;
        } else if (H[i+1] > H[i]) {
            if (H[i+1] - H[i] <= U) {
                current_hill = i + 1;
            } else {
                break;
            }
        } else { // H[i+1] < H[i]
            if (H[i] - H[i+1] <= D) {
                current_hill = i + 1;
            } else if (!parachute_used) {
                parachute_used = true;
                current_hill = i + 1;
            } else {
                break;
            }
        }
    }

    cout << current_hill + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}