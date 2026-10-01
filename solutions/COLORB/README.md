# [Coloured Orbs (COLORB)](https://www.codechef.com/problems/COLORB)

- **Difficulty Rating**: 273
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $R$ red orbs and $B$ blue orbs. You can combine 1 red orb and 1 blue orb to create 1 green orb. The skill values for the orbs are:
- Red: 1
- Blue: 2
- Green: 5

The goal is to maximize the total skill value by choosing the optimal number of green orbs to create.

## Intuition & Mathematical Observation
Let $k$ be the number of green orbs created. Since each green orb requires one red and one blue orb, $k$ can range from $0$ to $\min(R, B)$.

After creating $k$ green orbs, the remaining quantities are:
- Red: $R - k$
- Blue: $B - k$
- Green: $k$

The total skill $S$ can be expressed as:
$$S = (R - k) \times 1 + (B - k) \times 2 + k \times 5$$
$$S = R - k + 2B - 2k + 5k$$
$$S = R + 2B + 2k$$

Since $R$ and $B$ are constants, the total skill $S$ is a strictly increasing function of $k$. To maximize $S$, we must maximize $k$. The maximum possible value for $k$ is $\min(R, B)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves basic arithmetic operations and a comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total Skill = R + 2B + 2k
 * To maximize the skill, we maximize k, where k = min(R, B).
 */

void solve() {
    long long R, B;
    if (!(cin >> R >> B)) return;
    
    // Maximize green orbs by taking the minimum of available red and blue
    long long k = min(R, B);
    
    // Calculate total skill based on the derived formula
    long long max_skill = (R - k) * 1 + (B - k) * 2 + k * 5;
    
    cout << max_skill << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
```