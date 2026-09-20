# [Compress the Video (COMPRESSVD)](https://www.codechef.com/problems/COMPRESSVD)

- **Difficulty Rating**: 940
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a sequence of video frames represented by an array of integers. You can remove any frame if it is identical to the frame immediately preceding it. The goal is to find the minimum number of frames remaining after performing this operation as many times as possible.

## Intuition & Mathematical Observation
The problem states that we can remove a frame if it is equal to the one before it. If we have a sequence of identical consecutive frames (e.g., `[5, 5, 5, 2, 2]`), we can repeatedly remove the duplicates until only one instance of that value remains for that specific "block" (resulting in `[5, 2]`).

Essentially, the problem asks us to count the number of unique "blocks" of consecutive identical elements. 
- We always keep the first frame.
- For every subsequent frame, we only keep it if it is different from the frame immediately preceding it.
- This effectively reduces the array to its "run-length encoded" form where we only count the number of groups.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of frames. We iterate through the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array. This could be optimized to $O(1)$ if we process the input stream element-by-element without storing the entire array.

## Solution Code

```cpp
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

    // The first frame is always kept.
    int count = 1;
    for (int i = 1; i < n; ++i) {
        // If the current frame is different from the previous one,
        // it represents the start of a new block and must be kept.
        if (a[i] != a[i - 1]) {
            count++;
        }
    }

    cout << count << "\n";
}

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```