# [Uncle Johny (JOHNY)](https://www.codechef.com/problems/JOHNY)

- **Difficulty Rating**: 1093
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a playlist of $N$ songs, each with a specific length. We are also given the 1-based index $K$ of a specific song called "Uncle Johny." The goal is to determine the new 1-based index of "Uncle Johny" after the entire playlist is sorted in non-decreasing order of song lengths.

## Intuition & Mathematical Observation
1. **Identify the Target**: Since we need to track a specific song, we first extract its length using the provided index $K$ (adjusting for 0-based indexing as $K-1$).
2. **Sorting**: The problem states that the playlist is sorted. Since all song lengths are unique, the relative order of the songs will change, but the length of "Uncle Johny" remains constant.
3. **Search**: After sorting the array, we simply need to find the index where the length of "Uncle Johny" is located. Because the lengths are unique, there will be exactly one position that matches the stored length.
4. **Indexing**: The problem requires a 1-based index, so we add 1 to the 0-based index found after sorting.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of songs. Sorting takes $O(N \log N)$ per test case, and the subsequent linear search takes $O(N)$. Given $N \le 100$, this is highly efficient.
- **Space Complexity**: $O(N)$ to store the array of song lengths for each test case.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array of N song lengths and the index K of "Uncle Johny".
 * We need to find the new index of "Uncle Johny" after the array is sorted.
 * 
 * Approach:
 * 1. Store the length of "Uncle Johny" by accessing the array at index K-1 (since input is 1-indexed).
 * 2. Sort the entire array of song lengths.
 * 3. Find the new position of the stored length in the sorted array.
 * 4. Since the problem guarantees all song lengths are unique, the position is unique.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int k;
    cin >> k;
    
    // Store the length of Uncle Johny
    long long uncleJohnyLength = a[k - 1];
    
    // Sort the playlist
    sort(a.begin(), a.end());
    
    // Find the new position (1-indexed)
    for (int i = 0; i < n; ++i) {
        if (a[i] == uncleJohnyLength) {
            cout << (i + 1) << "\n";
            return;
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}
```