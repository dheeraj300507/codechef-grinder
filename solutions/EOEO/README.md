# [The Tom and Jerry Game! (EOEO)](https://www.codechef.com/problems/EOEO)

- **Difficulty Rating**: 1337
- **Solved in**: 1 attempt(s)

## Problem Summary
Tom and Jerry are playing a game with a number $TS$ (Tom's starting number). Jerry chooses a number $JS$ such that $1 \le JS \le TS$. The game proceeds in turns:
1. If both $TS$ and $JS$ are even, both are divided by 2.
2. If both are odd, the game ends and Tom wins.
3. If $TS$ is even and $JS$ is odd, Tom wins.
4. If $TS$ is odd and $JS$ is even, Jerry wins.

We need to find the number of possible values for $JS$ such that Jerry wins the game.

## Intuition & Mathematical Observation
Let $TS = 2^k \cdot m$, where $m$ is an odd integer. The game effectively removes the common power of 2 from both $TS$ and $JS$. 

For Jerry to win, the game must reach a state where $TS$ is odd and $JS$ is even. 
- After dividing $TS$ by $2^k$, $TS$ becomes $m$ (which is odd).
- For Jerry to win, $JS$ must still be even after the same number of divisions. This implies that $JS$ must have been divisible by a higher power of 2 than $TS$.
- Specifically, if $TS = 2^k \cdot m$, then $JS$ must be a multiple of $2^{k+1}$.

Thus, the problem reduces to counting how many multiples of $2^{k+1}$ exist in the range $[1, TS]$. The number of such multiples is simply:
$$\text{Count} = \left\lfloor \frac{TS}{2^{k+1}} \right\rfloor$$

**Example:**
If $TS = 12$ ($2^2 \cdot 3$), then $k=2$. We need multiples of $2^{2+1} = 8$.
In the range $[1, 12]$, the only multiple of 8 is 8 itself.
$\lfloor 12 / 8 \rfloor = 1$. Jerry wins if he picks 8.

## Complexity Analysis
- **Time Complexity**: $O(\log(TS))$ per test case. The `while` loop runs once for each trailing zero in the binary representation of $TS$, which is at most 64 for a `long long`.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let TS = 2^k * m, where m is odd.
 * For Jerry to win, JS must be divisible by a higher power of 2 than TS.
 * That is, if TS = 2^k * m, JS must be a multiple of 2^(k+1).
 * The number of such values in range [1, TS] is floor(TS / 2^(k+1)).
 */

void solve() {
    long long ts;
    cin >> ts;

    // Find the power of 2 that divides TS
    long long temp_ts = ts;
    long long power_of_2 = 1;
    
    // Extract the power of 2 component
    while ((temp_ts & 1) == 0) {
        temp_ts >>= 1;
        power_of_2 <<= 1;
    }
    
    // We need JS to be a multiple of (power_of_2 * 2)
    // The number of multiples of X in range [1, TS] is floor(TS / X)
    long long divisor = power_of_2 * 2;
    cout << ts / divisor << "\n";
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