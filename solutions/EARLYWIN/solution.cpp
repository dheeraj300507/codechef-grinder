#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two strings A and B. We need to find the longest common prefix.
 * Since the problem guarantees that the first characters are the same, 
 * the length of the common prefix will be at least 1.
 * We iterate through the indices from 0 up to min(N, M) - 1 and compare 
 * characters at each position. As soon as we find a mismatch, we stop.
 * 
 * Time Complexity: O(min(N, M)) per test case.
 * Space Complexity: O(N + M) to store the strings.
 */

void solve() {
    int N, M;
    cin >> N >> M;
    string A, B;
    cin >> A >> B;

    string result = "";
    int limit = min(N, M);

    for (int i = 0; i < limit; ++i) {
        if (A[i] == B[i]) {
            result += A[i];
        } else {
            break;
        }
    }

    cout << result << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}