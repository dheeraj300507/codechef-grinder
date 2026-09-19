# [Flip the cards (FLIPCARDS)](https://www.codechef.com/problems/FLIPCARDS)

- **Difficulty Rating**: 641
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ cards in total, where $X$ cards are currently face-up and the remaining $(N - X)$ cards are face-down. You want to reach a state where all cards are either face-up or face-down. Determine the minimum number of flips required to achieve this.

## Intuition & Mathematical Observation
To reach a uniform state, we have two possible target configurations:
1. **All cards face-up:** To achieve this, we must flip all the cards that are currently face-down. Since there are $(N - X)$ face-down cards, this requires $(N - X)$ operations.
2. **All cards face-down:** To achieve this, we must flip all the cards that are currently face-up. Since there are $X$ face-up cards, this requires $X$ operations.

The goal is to find the minimum number of operations to reach either state. Therefore, the answer is simply the minimum of the two possibilities:
$$\text{Result} = \min(X, N - X)$$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are only performing basic arithmetic and a comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards total.
 * X cards are face-up.
 * (N - X) cards are face-down.
 * 
 * To make all cards face-up, we must flip all (N - X) face-down cards.
 * To make all cards face-down, we must flip all X face-up cards.
 * 
 * The goal is to find the minimum number of operations, which is simply:
 * min(X, N - X)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, x;
        cin >> n >> x;
        
        // The number of operations to make all face-up is (n - x)
        // The number of operations to make all face-down is x
        // We take the minimum of these two values.
        int result = min(x, n - x);
        
        cout << result << "\n";
    }
    
    return 0;
}
```