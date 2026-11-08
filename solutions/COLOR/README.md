# [Chef And Coloring (COLOR)](https://www.codechef.com/problems/COLOR)

- **Difficulty Rating**: 1148
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ rooms, each painted either Red ('R'), Green ('G'), or Blue ('B'). Chef wants all the rooms to be the same color. We need to find the minimum number of rooms that must be repainted to achieve this goal.

## Intuition & Mathematical Observation
To minimize the number of repainted rooms, we should keep the color that is already most frequent in the string and repaint all other rooms to match that color.

1. Let $N$ be the total number of rooms.
2. Let $count_R$, $count_G$, and $count_B$ be the frequencies of 'R', 'G', and 'B' respectively.
3. The number of rooms that already match the most frequent color is $max(count_R, count_G, count_B)$.
4. Therefore, the number of rooms that **must** be repainted is the total number of rooms minus the count of the most frequent color:
   $$\text{Repaint Count} = N - \max(count_R, count_G, count_B)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of rooms, as we iterate through the string exactly once to count the occurrences of each color.
- **Space Complexity**: $O(N)$ to store the input string. If the string were processed character-by-character from the input stream, this could be reduced to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string of length N consisting of 'R', 'G', and 'B'.
 * We want to make all characters in the string the same color.
 * To minimize the number of rooms to repaint, we should choose the color 
 * that already appears the most frequently in the string and repaint 
 * all other rooms to that color.
 * 
 * The number of rooms to repaint = Total rooms (N) - Maximum frequency of any color.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int countR = 0;
    int countG = 0;
    int countB = 0;

    // Count occurrences of each color
    for (char c : s) {
        if (c == 'R') countR++;
        else if (c == 'G') countG++;
        else if (c == 'B') countB++;
    }

    // Find the maximum frequency among the three colors
    int maxFreq = max({countR, countG, countB});

    // The minimum number of rooms to repaint is total rooms minus the count of the most frequent color
    cout << (n - maxFreq) << "\n";
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