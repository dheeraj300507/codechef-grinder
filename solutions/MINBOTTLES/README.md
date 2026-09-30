# [Minimum Bottles (MINBOTTLES)](https://www.codechef.com/problems/MINBOTTLES)

- **Difficulty Rating**: 656
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given $N$ bottles, each containing a certain amount of water $A_i$. You have an unlimited supply of empty bottles, each with a maximum capacity of $X$. Since you can transfer water freely between bottles, the goal is to find the minimum number of bottles of capacity $X$ required to store the total volume of water present in all $N$ bottles.

## Intuition & Mathematical Observation
The problem asks for the minimum number of bottles of capacity $X$ needed to hold a total volume $S = \sum_{i=1}^{N} A_i$. 

Because we can redistribute the water perfectly, we don't need to worry about the individual volumes of the original bottles. We simply need to calculate the total volume $S$ and determine how many containers of size $X$ are required to hold it. 

Mathematically, this is equivalent to calculating $\lceil \frac{S}{X} \rceil$. In integer arithmetic, the ceiling division $\lceil \frac{a}{b} \rceil$ can be efficiently calculated using the formula:
$$\text{result} = \frac{a + b - 1}{b}$$
This avoids the need for floating-point arithmetic and potential precision issues.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of bottles. We iterate through the input array exactly once to calculate the sum.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We have N bottles with capacity X. We want to store the total volume of water
 * S = sum(A_i) in the minimum number of bottles.
 * Since we can transfer water freely, we simply fill bottles to capacity X one by one.
 * The number of bottles needed is ceil(S / X).
 */

void solve() {
    int N;
    long long X;
    if (!(cin >> N >> X)) return;

    long long total_water = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        total_water += a;
    }

    // Calculate ceil(total_water / X) using integer division
    // Formula: (total_water + X - 1) / X
    // This handles the case where total_water is not perfectly divisible by X.
    long long min_bottles = (total_water + X - 1) / X;

    cout << min_bottles << endl;
}

int main() {
    // Optimize I/O operations for faster execution
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