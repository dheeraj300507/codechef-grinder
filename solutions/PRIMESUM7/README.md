# [Prime Sum (PRIMESUM7)](https://www.codechef.com/problems/PRIMESUM7)

- **Difficulty Rating**: 872
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ consisting only of the integers $\{1, 2, 3\}$, find the number of pairs $(i, j)$ such that $1 \le i < j \le N$ and the sum $A_i + A_j$ is a prime number.

## Intuition & Mathematical Observation
Since the elements are restricted to $\{1, 2, 3\}$, the possible sums of any two elements are:
- $1 + 1 = 2$ (Prime)
- $1 + 2 = 3$ (Prime)
- $1 + 3 = 4$ (Not Prime)
- $2 + 2 = 4$ (Not Prime)
- $2 + 3 = 5$ (Prime)
- $3 + 3 = 6$ (Not Prime)

The prime sums are $\{2, 3, 5\}$. We can count the occurrences of each number ($c_1, c_2, c_3$) and calculate the valid pairs based on these sums:
1. **Sum = 2**: Formed by $(1, 1)$. The number of ways to choose 2 ones from $c_1$ is $\binom{c_1}{2} = \frac{c_1 \times (c_1 - 1)}{2}$.
2. **Sum = 3**: Formed by $(1, 2)$. The number of ways is $c_1 \times c_2$.
3. **Sum = 5**: Formed by $(2, 3)$. The number of ways is $c_2 \times c_3$.

The total count is the sum of these three values.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the size of the array, as we iterate through the array once to count the frequencies.
- **Space Complexity**: $O(1)$, as we only store the counts of the three possible values regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array elements A_i are restricted to {1, 2, 3}.
 * Possible sums of pairs (A_i, A_j) are:
 * 1 + 1 = 2 (Prime)
 * 1 + 2 = 3 (Prime)
 * 1 + 3 = 4 (Not Prime)
 * 2 + 2 = 4 (Not Prime)
 * 2 + 3 = 5 (Prime)
 * 3 + 3 = 6 (Not Prime)
 * 
 * We need to count pairs (i, j) with i < j such that A_i + A_j is in {2, 3, 5}.
 * Let c1, c2, c3 be the counts of 1s, 2s, and 3s in the array.
 * 
 * Pairs with sum 2: (1, 1) -> c1 * (c1 - 1) / 2
 * Pairs with sum 3: (1, 2) -> c1 * c2
 * Pairs with sum 5: (2, 3) -> c2 * c3
 * 
 * Total = (c1 * (c1 - 1) / 2) + (c1 * c2) + (c2 * c3)
 */

void solve() {
    int N;
    cin >> N;
    long long c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val == 1) c1++;
        else if (val == 2) c2++;
        else if (val == 3) c3++;
    }

    long long ans = 0;
    // Sum 2: (1, 1)
    ans += (c1 * (c1 - 1)) / 2;
    // Sum 3: (1, 2)
    ans += (c1 * c2);
    // Sum 5: (2, 3)
    ans += (c2 * c3);

    cout << ans << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```