#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An element is a leader if it is strictly greater than all elements to its right.
 * The rightmost element is always a leader.
 * To solve this efficiently in O(N) time:
 * 1. Traverse the array from right to left.
 * 2. Keep track of the maximum element encountered so far from the right.
 * 3. If the current element is strictly greater than the current maximum, it is a leader.
 * 4. Since we need to output them in original left-to-right order, we can store the 
 *    found leaders in a list and then reverse it, or use a stack.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 0) return;

    vector<long long> leaders;
    // The rightmost element is always a leader
    long long max_from_right = a[n - 1];
    leaders.push_back(max_from_right);

    // Traverse from second to last element to the beginning
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > max_from_right) {
            leaders.push_back(a[i]);
            max_from_right = a[i];
        }
    }

    // The leaders are currently in right-to-left order, reverse to get left-to-right
    reverse(leaders.begin(), leaders.end());

    for (int i = 0; i < leaders.size(); ++i) {
        cout << leaders[i] << (i == (int)leaders.size() - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case structure based on the 
    // input format description, but standard competitive programming practice 
    // handles potential multiple test cases if specified.
    // Given the constraints and format, we execute the logic once.
    solve();

    return 0;
}