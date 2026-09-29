# [Yoga Day (YOGADAY)](https://www.codechef.com/problems/YOGADAY)

- **Difficulty Rating**: 264
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine how many complete rounds of "Surya Namaskar" can be performed given a total number of yoga poses $N$. We are told that one complete round consists of exactly 12 poses. We need to output the total number of full rounds possible.

## Intuition & Mathematical Observation
Since each round requires exactly 12 poses, the number of complete rounds is simply the quotient obtained when dividing the total number of poses $N$ by 12. In programming, this is achieved using integer division (`N / 12`), which automatically discards any remainder (incomplete rounds).

**Example:**
- If $N = 24$, $24 / 12 = 2$ rounds.
- If $N = 25$, $25 / 12 = 2$ rounds (with 1 pose left over).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as it involves a single arithmetic division operation.
- **Space Complexity**: $O(1)$, as we only use a single integer variable to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each round of Surya Namaskar consists of 12 yoga poses.
 * Given N total poses, the number of complete rounds is the integer division of N by 12.
 * 
 * Constraints:
 * 1 <= N <= 100
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Read the total number of poses N
    int N;
    if (cin >> N) {
        // Calculate complete rounds using integer division
        int rounds = N / 12;
        cout << rounds << "\n";
    }

    return 0;
}
```