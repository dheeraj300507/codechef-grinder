#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows removing a frame if it is equal to its neighbor.
 * This is equivalent to saying that if we have a sequence of identical 
 * consecutive frames (e.g., [2, 2, 2]), we can remove all but one of them.
 * 
 * Effectively, we are looking for the number of "blocks" of identical 
 * consecutive values. For example, in [2, 1, 2, 2], the blocks are [2], [1], [2, 2].
 * The number of frames remaining will be the number of such blocks.
 * 
 * Algorithm:
 * Iterate through the array and count how many times the current element 
 * is different from the previous element. The first element is always kept.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the input, or O(1) if processed on the fly.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 0) {
        cout << 0 << "\n";
        return;
    }

    int count = 1;
    for (int i = 1; i < n; ++i) {
        // If the current frame is different from the previous one,
        // it cannot be removed by the rule.
        if (a[i] != a[i - 1]) {
            count++;
        }
    }

    cout << count << "\n";
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