# [Leader of an Array (DSACPR49)](https://www.codechef.com/problems/DSACPR49)

- **Difficulty Rating**: 950
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to identify all "leaders" in an array. An element is defined as a leader if it is strictly greater than all elements to its right. The rightmost element of the array is always considered a leader. The output should list these leaders in the order they appear in the original array.

## Intuition & Mathematical Observation
A naive approach would involve checking every element against all elements to its right, resulting in an $O(N^2)$ complexity. To optimize this, we observe the following:

1. **Right-to-Left Traversal**: If we traverse the array from right to left, we can maintain a variable `max_from_right` that keeps track of the largest element encountered so far.
2. **Condition**: As we move left, if the current element is strictly greater than `max_from_right`, it satisfies the condition of being a leader. We then update `max_from_right` to this new value.
3. **Ordering**: Since this approach identifies leaders from right to left, we store them in a list and reverse it at the end to maintain the original relative order.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of elements in the array. We perform a single pass through the array to identify leaders and a final pass to print them.
- **Space Complexity**: $O(N)$ in the worst case (e.g., a strictly increasing array), as we store the identified leaders in a vector.

## Solution Code

```cpp
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
 * 4. Since we need to output them in original left-to-right order, we store the 
 *    found leaders in a list and then reverse it.
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

    solve();

    return 0;
}
```