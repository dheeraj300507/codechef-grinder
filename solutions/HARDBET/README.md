# [Hardest Problem Bet (HARDBET)](https://www.codechef.com/problems/HARDBET)

- **Difficulty Rating**: 803
- **Solved in**: 1 attempt(s)

## Problem Summary
Three friends (Alice, Bob, and the user) are comparing the difficulty of three problems, labeled A, B, and C. The difficulty is determined by the number of successful submissions: the problem with the **lowest** number of successful submissions is considered the "hardest." Given the number of submissions for each problem ($S_A, S_B, S_C$), we must determine who wins the bet:
- If problem C is the hardest, **Alice** wins.
- If problem B is the hardest, **Bob** wins.
- If problem A is the hardest, it is a **Draw**.

## Intuition & Mathematical Observation
The problem asks us to identify the minimum value among three distinct integers ($S_A, S_B, S_C$). 
1. We compare the three input values to find the minimum.
2. We use conditional statements (`if-else`) to map the minimum value to the corresponding person:
   - `min(S_A, S_B, S_C) == S_C` $\rightarrow$ "Alice"
   - `min(S_A, S_B, S_C) == S_B` $\rightarrow$ "Bob"
   - Otherwise $\rightarrow$ "Draw" (since $S_A$ must be the minimum).

Since the problem guarantees that all three values are distinct, there will never be a tie for the minimum value, making the logic straightforward.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of comparisons.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem defines the "hardest" problem as the one with the minimum number of successful submissions.
 * We are given S_A, S_B, and S_C.
 * - If S_C is the minimum, Alice wins.
 * - If S_B is the minimum, Bob wins.
 * - If S_A is the minimum, it's a Draw.
 * 
 * Constraints: 1 <= S_A, S_B, S_C <= 100, all distinct.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

void solve() {
    int sa, sb, sc;
    if (!(cin >> sa >> sb >> sc)) return;

    // Find the minimum value among the three
    int min_val = min({sa, sb, sc});

    if (min_val == sc) {
        cout << "Alice" << "\n";
    } else if (min_val == sb) {
        cout << "Bob" << "\n";
    } else {
        cout << "Draw" << "\n";
    }
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