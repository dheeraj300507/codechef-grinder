# [Add to get GCD (ADDGCD)](https://www.codechef.com/problems/ADDGCD)

- **Difficulty Rating**: 1008
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $Y$, we want to make their Greatest Common Divisor (GCD) greater than 1. We are allowed to perform an operation where we increment either $X$ or $Y$ by 1. We need to find the minimum number of operations required to achieve $\gcd(X+a, Y+b) > 1$, where $a$ and $b$ are the number of increments applied to $X$ and $Y$ respectively.

## Intuition & Mathematical Observation
The problem asks for the minimum $a + b$ such that $\gcd(X+a, Y+b) > 1$. 

1. **Case 0 (Already satisfied):** If $\gcd(X, Y) > 1$, the condition is already met. The answer is **0**.
2. **Case 1 (One increment):** If we can make the GCD greater than 1 by adding 1 to either $X$ or $Y$, the answer is **1**. We check this by verifying if $\gcd(X+1, Y) > 1$ or $\gcd(X, Y+1) > 1$.
3. **Case 2 (Two increments):** If neither of the above works, we can always make both numbers even by adding 1 to each (if they are odd). Since any two even numbers have a GCD of at least 2, the answer is at most **2**. 

Because we check for 0, then 1, and finally default to 2, we cover all possible scenarios efficiently.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot \log(\min(X, Y)))$, where $T$ is the number of test cases. The GCD calculation using the Euclidean algorithm takes logarithmic time relative to the input values.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and perform calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to find the minimum operations to make gcd(X+a, Y+b) > 1.
 * 1. If gcd(X, Y) > 1, answer is 0.
 * 2. If gcd(X+1, Y) > 1 or gcd(X, Y+1) > 1, answer is 1.
 * 3. Otherwise, the answer is 2 (e.g., making both numbers even).
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // Check if already satisfied
    if (gcd(X, Y) > 1) {
        cout << 0 << "\n";
        return;
    }

    // Check if 1 operation is sufficient
    if (gcd(X + 1, Y) > 1 || gcd(X, Y + 1) > 1) {
        cout << 1 << "\n";
        return;
    }

    // Otherwise, 2 operations are always sufficient
    cout << 2 << "\n";
}

int main() {
    // Optimize I/O operations
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