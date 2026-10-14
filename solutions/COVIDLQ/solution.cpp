#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * We need to ensure that for any two people (1s), the distance between them 
 * is at least 6 feet.
 * 
 * If the indices of two people are i and j (where i < j), the distance is (j - i).
 * The condition is (j - i) >= 6.
 * 
 * Algorithm:
 * 1. Iterate through the array and store the index of the last person seen.
 * 2. If we encounter another person, check if the current index minus the 
 *    last seen index is less than 6.
 * 3. If it is less than 6, social distancing is violated (return "NO").
 * 4. If we finish the loop without violations, return "YES".
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int last_pos = -10; // Initialize with a value that won't trigger a false violation
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}