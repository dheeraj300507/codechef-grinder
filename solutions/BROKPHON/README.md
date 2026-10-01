# [Broken Telephone (BROKPHON)](https://www.codechef.com/problems/BROKPHON)

- **Difficulty Rating**: 1204
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of "Broken Telephone," a message is passed along a line of $N$ players. Each player $i$ whispers a message $A[i]$. A player is considered to have "broken" the telephone if the message they whispered is different from the message whispered by the previous player or the message heard by the next player. Specifically, if $A[i] \neq A[i+1]$, the message has been corrupted at that link. We need to find the total number of players who are involved in at least one such discrepancy.

## Intuition & Mathematical Observation
The core observation is that a discrepancy occurs whenever $A[i] \neq A[i+1]$. 
- If $A[i] \neq A[i+1]$, it implies that the message changed between player $i$ and player $i+1$. 
- Consequently, both player $i$ and player $i+1$ are involved in a "broken" communication.
- We can use a boolean array `is_wrong` of size $N$ to track which players are involved in a discrepancy. By iterating through the array once and checking every adjacent pair $(i, i+1)$, we can mark both indices as `true` whenever $A[i] \neq A[i+1]$.
- Finally, the answer is simply the count of `true` values in our boolean array. This approach naturally handles overlapping discrepancies (e.g., if $A[i-1] \neq A[i]$ and $A[i] \neq A[i+1]$, player $i$ is marked `true` twice but only counted once).

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of players. We perform a single pass to identify discrepancies and another pass to count the marked players.
- **Space Complexity**: $O(N)$ to store the input array and the boolean tracking array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A player i is involved in a discrepancy if their whispered message A[i] 
 * differs from their neighbor's message. If A[i] != A[i+1], both player i 
 * and player i+1 are marked as having a broken link.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Use a boolean array to mark players involved in a discrepancy
    vector<bool> is_wrong(n, false);
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != a[i + 1]) {
            is_wrong[i] = true;
            is_wrong[i + 1] = true;
        }
    }

    // Count how many unique players were marked
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (is_wrong[i]) {
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O for performance
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