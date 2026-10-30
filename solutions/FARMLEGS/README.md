# [Legs on a Farm (FARMLEGS)](https://www.codechef.com/problems/FARMLEGS)

- **Difficulty Rating**: 709
- **Solved in**: 2 attempt(s)

## Problem Summary
Given the total number of legs $N$ on a farm consisting of cows (4 legs) and chickens (2 legs), find the minimum number of animals required to account for exactly $N$ legs.

## Intuition & Mathematical Observation
To minimize the total number of animals ($A = C + H$), we should prioritize animals with more legs (cows), as they contribute more to the leg count per individual.

Let $C$ be the number of cows and $H$ be the number of chickens. We have the constraint:
$$4C + 2H = N$$
We want to minimize $A = C + H$. Substituting $H = \frac{N - 4C}{2}$:
$$A = C + \frac{N - 4C}{2} = C + \frac{N}{2} - 2C = \frac{N}{2} - C$$

To minimize $A$, we must maximize $C$. Since each cow has 4 legs, the maximum number of cows we can have is $\lfloor N/4 \rfloor$.

1. **If $N$ is divisible by 4 ($N \pmod 4 = 0$):** We use only cows. $C = N/4$, $H = 0$. Total = $N/4$.
2. **If $N \pmod 4 = 2$:** We use the maximum number of cows possible, leaving 2 legs remaining, which must be one chicken. $C = (N-2)/4$, $H = 1$. Total = $(N-2)/4 + 1$.

Both cases can be unified into the formula: `(N / 4) + (N % 4) / 2`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses basic arithmetic operations. The total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>

/**
 * Problem Analysis:
 * We want to minimize A = C + H subject to 4C + 2H = N.
 * A = C + (N - 4C) / 2 = C + N/2 - 2C = N/2 - C.
 * To minimize A, we must maximize C.
 * The maximum number of cows C is floor(N / 4).
 * 
 * If N % 4 == 0:
 *   Max C = N / 4, H = 0. Total = N / 4.
 * If N % 4 == 2:
 *   Max C = (N - 2) / 4, H = 1. Total = (N - 2) / 4 + 1 = (N + 2) / 4.
 * 
 * Both cases are covered by: (N / 4) + (N % 4) / 2.
 */

using namespace std;

int main() {
    // Optimize I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // Calculate minimum animals:
        // N/4 gives the number of cows (maximizing cows minimizes total animals)
        // (N%4)/2 gives the number of chickens (0 if N%4==0, 1 if N%4==2)
        int min_animals = (n / 4) + ((n % 4) / 2);
        
        cout << min_animals << "\n";
    }
    
    return 0;
}
```