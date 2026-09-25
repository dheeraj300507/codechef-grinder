# [Single-use Attack (SINGLEUSE)](https://www.codechef.com/problems/SINGLEUSE)

- **Difficulty Rating**: 777
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is fighting a boss with $H$ health points. Chef has two types of attacks:
1. **Normal Attack**: Deals $X$ damage.
2. **Special Attack**: Deals $Y$ damage, but can be used **only once**.

The goal is to find the minimum number of attacks required to defeat the boss (reduce health to $\le 0$).

## Intuition & Mathematical Observation
To minimize the total number of attacks, we compare two strategies:

1. **Strategy 1: Only Normal Attacks**
   The number of attacks required is $\lceil H / X \rceil$. Using integer arithmetic, this is calculated as `(H + X - 1) / X`.

2. **Strategy 2: Use Special Attack Once + Normal Attacks**
   - If the special attack is enough to defeat the boss ($H \le Y$), the answer is $1$.
   - Otherwise, the boss has $H - Y$ health remaining. We then use normal attacks to finish the boss, requiring $1 + \lceil (H - Y) / X \rceil$ total attacks.

We simply calculate both values and output the minimum of the two.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two options:
 * 1. Use only normal attacks:
 *    The number of attacks required is ceil(H / X).
 *    In integer arithmetic, this is (H + X - 1) / X.
 * 
 * 2. Use the special attack once, then normal attacks:
 *    The special attack reduces health by Y.
 *    Remaining health = H - Y.
 *    If H - Y <= 0, the total attacks needed is 1.
 *    Otherwise, the number of normal attacks needed is ceil((H - Y) / X).
 *    Total attacks = 1 + ceil((H - Y) / X).
 * 
 * We want the minimum of these two options.
 */

void solve() {
    long long H, X, Y;
    cin >> H >> X >> Y;

    // Option 1: Only normal attacks
    long long attacks_only_normal = (H + X - 1) / X;

    // Option 2: Special attack once + normal attacks
    long long attacks_with_special;
    if (H <= Y) {
        attacks_with_special = 1;
    } else {
        long long remaining_health = H - Y;
        attacks_with_special = 1 + (remaining_health + X - 1) / X;
    }

    cout << min(attacks_only_normal, attacks_with_special) << "\n";
}

int main() {
    // Fast I/O
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