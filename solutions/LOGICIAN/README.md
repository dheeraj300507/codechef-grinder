# [3 Logicians Walk into a Bar (LOGICIAN)](https://www.codechef.com/problems/LOGICIAN)

- **Difficulty Rating**: 1269
- **Solved in**: 1 attempt(s)

## Problem Summary
A bartender asks a group of $N$ logicians if everyone in the group wants a beer. Each logician $i$ has a preference $S_i$ (where '1' means they want a beer and '0' means they do not). Logicians answer sequentially. A logician can only say "YES" if they are certain everyone wants a beer, "NO" if they are certain at least one person does not want a beer, and "IDK" (I don't know) otherwise. We need to determine the response of each logician.

## Intuition & Mathematical Observation
The key to this problem is understanding the information available to each logician at their turn:

1.  **The "NO" Trigger**: If any logician $i$ has $S_i = 0$, they immediately know that not everyone wants a beer. Thus, they say "NO". Once a "NO" has been uttered, every subsequent logician knows for a fact that at least one person (the one who said "NO" or someone before them) does not want a beer. Therefore, all subsequent logicians will also say "NO".
2.  **The "IDK" Phase**: If a logician $i$ has $S_i = 1$, they look at the previous responses. If everyone before them said "IDK", it implies that all previous logicians also wanted a beer ($S_j = 1$ for all $j < i$). However, logician $i$ does not know the preferences of the people *after* them. Thus, they cannot be certain that everyone wants a beer, so they say "IDK".
3.  **The "YES" Trigger**: The only person who can say "YES" is the very last logician ($N$). If all previous logicians said "IDK", it means everyone from $1$ to $N-1$ wanted a beer. If the $N$-th logician also wants a beer ($S_N = 1$), they now have complete information that everyone wants a beer, and they say "YES".

**Summary of Logic:**
- If `someone_said_no` is true: Output **NO**.
- If $S_i == '0'$: Output **NO** and set `someone_said_no = true`.
- If $S_i == '1'$ and it is the last person: Output **YES**.
- If $S_i == '1'$ and it is not the last person: Output **IDK**.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the string of preferences exactly once.
- **Space Complexity**: $O(N)$ to store the input string $S$ (or $O(1)$ if reading character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Logic Analysis:
 * - If any logician has said "NO", then everyone knows for sure that not everyone wants a beer.
 *   Therefore, all subsequent logicians will say "NO".
 * - If all previous logicians have said "IDK", it means they all wanted a beer (S_i == 1).
 *   If the current logician i has S_i == 0, they know not everyone wants a beer, so they say "NO".
 *   If the current logician i has S_i == 1, they still don't know about the remaining logicians, so they say "IDK".
 * - The only exception is the very last logician (N). If all previous logicians said "IDK" and the N-th logician 
 *   also has S_N == 1, they know everyone wants a beer, so they say "YES".
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool someone_said_no = false;

    for (int i = 0; i < N; ++i) {
        if (someone_said_no) {
            cout << "NO" << "\n";
            continue;
        }

        if (S[i] == '0') {
            cout << "NO" << "\n";
            someone_said_no = true;
        } else {
            // S[i] == '1'
            // If this is the last person and no one said NO yet, 
            // they know everyone wants a beer.
            if (i == N - 1) {
                cout << "YES" << "\n";
            } else {
                cout << "IDK" << "\n";
            }
        }
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```