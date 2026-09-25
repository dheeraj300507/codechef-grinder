# [Chef and String (XYSTR)](https://www.codechef.com/problems/XYSTR)

- **Difficulty Rating**: 1124
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string consisting of characters 'x' (representing girls) and 'y' (representing boys). We need to form the maximum number of pairs consisting of one boy and one girl, with the constraint that the two students in a pair must be adjacent in the string. Once a student is paired, they cannot be part of another pair.

## Intuition & Mathematical Observation
This problem can be solved using a **Greedy approach**. 

1. **Local Optimal Choice**: To maximize the total number of pairs, we should pair adjacent students as soon as we find a valid 'xy' or 'yx' combination.
2. **Strategy**: We iterate through the string from left to right. 
   - If the current character `s[i]` and the next character `s[i+1]` are different, it means we have found a valid pair. We increment our pair count and skip both characters (move to `i + 2`) because they are now "used."
   - If they are the same, we cannot form a pair using `s[i]` with `s[i+1]`. Therefore, we move to the next index (`i + 1`) to see if `s[i+1]` can be paired with `s[i+2]`.
3. **Why Greedy works**: Since we only care about the total count and the students are in a fixed linear order, taking the first available pair does not prevent us from finding an optimal solution elsewhere. Skipping an index when a pair is found is always better than or equal to any other strategy.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We traverse the string at most once.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a string of 'x' (girls) and 'y' (boys).
 * We want to form the maximum number of pairs (boy, girl) where the students are adjacent.
 * This is a classic greedy problem. We iterate through the string from left to right.
 * If we find an adjacent pair (S[i], S[i+1]) such that one is 'x' and the other is 'y',
 * we form a pair and skip both students (move to i+2).
 * If they are not a pair, we move to the next student (i+1).
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int pairs = 0;
    
    // Iterate through the string, checking adjacent pairs
    for (int i = 0; i < n - 1; ) {
        // Check if current student and next student are different
        if (s[i] != s[i + 1]) {
            pairs++;
            // Both students are now paired, move to the next available student
            i += 2;
        } else {
            // Cannot pair these two, move to the next student
            i++;
        }
    }
    
    cout << pairs << "\n";
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
```