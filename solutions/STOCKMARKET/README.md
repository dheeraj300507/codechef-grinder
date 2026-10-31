# [Chef and Stocks (STOCKMARKET)](https://www.codechef.com/problems/STOCKMARKET)

- **Difficulty Rating**: 948
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef is given the price of a stock for $N$ consecutive days. He wants to choose $N-1$ days to buy the stock such that the total cost is maximized. Effectively, this means Chef must choose exactly one day to "skip" (not buy the stock), and he wants to choose the day that results in the highest possible sum for the remaining $N-1$ days.

## Intuition & Mathematical Observation
Let the prices of the stock over $N$ days be represented by the array $A = [A_1, A_2, \dots, A_N]$.
The total sum of all stock prices is $S = \sum_{i=1}^{N} A_i$.

If Chef skips the stock on day $i$, the total cost becomes:
$$\text{Cost}_i = S - A_i$$

To maximize the total cost, we need to maximize $(S - A_i)$. Since $S$ is a constant for a given test case, maximizing $(S - A_i)$ is mathematically equivalent to **minimizing $A_i$**. 

Therefore, the optimal strategy is to find the minimum value in the array and subtract it from the total sum of all elements.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the total sum and find the minimum element.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store a few variables (`sum`, `min_val`, `val`) regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to maximize the sum of N-1 elements by skipping exactly one day.
 * Let S be the sum of all elements. If we skip element A_i, the sum is S - A_i.
 * To maximize (S - A_i), we must minimize A_i.
 * 
 * Complexity:
 * Time: O(N) per test case.
 * Space: O(1) auxiliary space.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long sum = 0;
    // Initialize min_val with a value larger than any possible A_i (max 100)
    int min_val = 200; 
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        sum += val;
        if (val < min_val) {
            min_val = val;
        }
    }
    
    // The result is the total sum minus the smallest element
    cout << (sum - min_val) << "\n";
}

int main() {
    // Fast I/O to handle large input sizes efficiently
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}
```