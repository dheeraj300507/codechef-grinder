# [Copy-Paste (RRCOPY)](https://www.codechef.com/problems/RRCOPY)

- **Difficulty Rating**: 1280
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to find the minimum size of an initial array $B$ such that we can obtain $A$ by performing the "Copy-Paste" operation any number of times. A "Copy-Paste" operation allows us to select any contiguous subsequence of the current array and insert it anywhere in the array.

## Intuition & Mathematical Observation
The key observation is that any element present in the final array $A$ must have originated from the initial array $B$. Since we can copy any contiguous subsequence, we can effectively "build" the array $A$ by starting with a set of all unique elements found in $A$.

If we start with an array $B$ containing exactly the set of distinct elements present in $A$, we can arrange them in any order. By repeatedly copying and pasting these elements, we can construct any sequence that contains these elements. Therefore, the minimum size of the initial array $B$ is simply the count of **distinct elements** in $A$.

For example, if $A = [1, 2, 3, 1, 2]$, the distinct elements are $\{1, 2, 3\}$. We can start with $B = [1, 2, 3]$ and copy the subsequence $[1, 2]$ to the end to match $A$.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of elements. Inserting $N$ elements into a `std::set` takes $O(N \log N)$ time. Given $N = 10^5$ and $T = 20$, this performs well within the 2-second time limit.
- **Space Complexity**: $O(N)$ to store the distinct elements in the `std::set`.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The "Copy-Paste" operation allows us to take any contiguous subsequence and 
 * insert it anywhere. This means if we have a set of unique elements present 
 * in the final array A, we can always start with an array containing exactly 
 * those unique elements in any order. 
 * 
 * Therefore, the minimal size of the initial array is simply the number of 
 * distinct elements in the given array A.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a set to automatically handle distinct elements
    set<int> distinct_elements;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        distinct_elements.insert(val);
    }
    
    // The answer is the number of unique elements found
    cout << distinct_elements.size() << "\n";
}

int main() {
    // Optimize I/O operations for faster execution
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