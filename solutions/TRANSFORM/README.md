# [Mario and Transformation (TRANSFORM)](https://www.codechef.com/problems/TRANSFORM)

- **Difficulty Rating**: 649
- **Solved in**: 1 attempt(s)

## Problem Summary
Mario starts in a `NORMAL` state. When he eats a mushroom, his state changes based on the total number of mushrooms consumed ($X$):
- If $X \pmod 3 = 1$, he becomes `HUGE`.
- If $X \pmod 3 = 2$, he becomes `SMALL`.
- If $X \pmod 3 = 0$, he returns to `NORMAL`.

Given the number of mushrooms $X$ consumed, determine Mario's final state.

## Intuition & Mathematical Observation
By observing the transformation sequence:
- $X=0$: `NORMAL`
- $X=1$: `HUGE`
- $X=2$: `SMALL`
- $X=3$: `NORMAL`
- $X=4$: `HUGE`
- $X=5$: `SMALL`

We can see a repeating pattern of length 3. The state depends entirely on the remainder of $X$ when divided by 3. Using the modulo operator (`%`), we can map every possible value of $X$ to one of the three states efficiently without needing to simulate the process step-by-step.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time $O(1)$ modulo operation and a conditional check.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the remainder, regardless of the size of $X$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Mario's transformation cycle repeats every 3 mushrooms:
 * X % 3 == 0 -> NORMAL
 * X % 3 == 1 -> HUGE
 * X % 3 == 2 -> SMALL
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x;
        cin >> x;
        
        int remainder = x % 3;
        
        if (remainder == 0) {
            cout << "NORMAL" << "\n";
        } else if (remainder == 1) {
            cout << "HUGE" << "\n";
        } else {
            cout << "SMALL" << "\n";
        }
    }
    
    return 0;
}
```