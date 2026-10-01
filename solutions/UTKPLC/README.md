# [Utkarsh and Placement tests (UTKPLC)](https://www.codechef.com/problems/UTKPLC)

- **Difficulty Rating**: 886
- **Solved in**: 2 attempt(s)

## Problem Summary
Utkarsh has a specific preference order for three companies (let's call them $A, B,$ and $C$). He receives job offers from exactly two of these three companies. The goal is to determine which of the two offered companies Utkarsh will choose based on his predefined preference list.

## Intuition & Mathematical Observation
Since there are only three companies in the preference list, we can represent the preference as an ordered sequence (e.g., $p_1, p_2, p_3$). 

When given two choices, $x$ and $y$, the decision logic is straightforward:
1. If $x$ appears earlier in the preference list than $y$, Utkarsh chooses $x$.
2. Otherwise, he chooses $y$.

Instead of using complex data structures, we can use a simple conditional check. If $x$ is the most preferred company ($p_1$), it is automatically the choice. If $x$ is the second most preferred ($p_2$), it is the choice only if $y$ is the least preferred ($p_3$). In all other cases, $y$ must be the better choice.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of comparisons regardless of the input.
- **Space Complexity**: $O(1)$, as we only store a few characters to represent the companies.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: Utkarsh and Placement tests
 * Approach:
 * Since there are only 3 companies, we can determine the preference rank 
 * by checking the position of the offered companies in the preference string.
 * The company that appears earlier in the preference list is the one chosen.
 */

void solve() {
    char p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    
    char x, y;
    cin >> x >> y;
    
    // We check the preference order directly.
    // If x is the first preference, it's the answer.
    // If x is the second preference, it's the answer only if y is the third.
    // Otherwise, y is the answer.
    
    if (x == p1 || (x == p2 && y == p3)) {
        cout << x << "\n";
    } else {
        cout << y << "\n";
    }
}

int main() {
    // Optimize I/O operations
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