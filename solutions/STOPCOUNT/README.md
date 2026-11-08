# [Stop The Count (STOPCOUNT)](https://www.codechef.com/problems/STOPCOUNT)

- **Difficulty Rating**: 893
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a binary string $S$ of length $N$, where '1' represents a vote for Chef and '0' represents a vote for AntiChef. We need to determine how many prefixes of this string satisfy the condition that the total number of votes for Chef is strictly greater than the total number of votes for AntiChef.

## Intuition & Mathematical Observation
The problem asks us to evaluate the state of the vote count at every possible stopping point (prefix). 

1. Let $c_i$ be the number of '1's in the prefix $S[0 \dots i]$.
2. Let $a_i$ be the number of '0's in the prefix $S[0 \dots i]$.
3. Chef is winning at index $i$ if $c_i > a_i$.

Since we need to check this for every index $i$ from $0$ to $N-1$, we can maintain two running counters while iterating through the string once. For each character encountered, we update the respective counter and check the condition. If the condition is met, we increment a global `win_count`.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We perform a single pass through the string, and each operation inside the loop is $O(1)$.
- **Space Complexity**: $O(N)$ to store the input string (or $O(1)$ if we process the input character by character).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wins if the number of votes for him (1s) is strictly greater than 
 * the number of votes for AntiChef (0s) at the point the counting stops.
 * 
 * Let 'c' be the count of 1s and 'a' be the count of 0s up to index i.
 * Chef wins if c > a.
 * 
 * We iterate through the string, maintaining the running counts of 1s and 0s.
 * For each prefix of length k (1 <= k <= N), we check if the condition holds.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int chef_votes = 0;
    int antichef_votes = 0;
    int win_count = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            chef_votes++;
        } else {
            antichef_votes++;
        }

        // Chef wins if he has strictly more votes than AntiChef
        if (chef_votes > antichef_votes) {
            win_count++;
        }
    }

    cout << win_count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```