# [Good Pairs (EQPAIR)](https://www.codechef.com/problems/EQPAIR)

- **Difficulty Rating**: 1248
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the number of pairs $(i, j)$ such that $1 \le i < j \le N$ and $\gcd(A_i, A_j) = \text{lcm}(A_i, A_j)$.

## Intuition & Mathematical Observation
To solve this problem, we analyze the condition $\gcd(A_i, A_j) = \text{lcm}(A_i, A_j)$.

1. We know the fundamental property: $\gcd(a, b) \times \text{lcm}(a, b) = a \times b$.
2. If $\gcd(a, b) = \text{lcm}(a, b) = k$, then substituting this into the property gives $k \times k = a \times b$, or $k^2 = ab$.
3. Since $k$ is the greatest common divisor, $k$ must divide both $a$ and $b$. Let $a = k \cdot x$ and $b = k \cdot y$, where $\gcd(x, y) = 1$.
4. The $\text{lcm}(a, b)$ is then $k \cdot x \cdot y$.
5. Setting $\gcd(a, b) = \text{lcm}(a, b)$ gives $k = k \cdot x \cdot y$, which simplifies to $x \cdot y = 1$.
6. Since $x$ and $y$ are positive integers, the only solution is $x = 1$ and $y = 1$.
7. Consequently, $a = k$ and $b = k$, meaning $a = b$.

**Conclusion:** A pair $(i, j)$ satisfies the condition if and only if $A_i = A_j$. If a number $x$ appears $f$ times in the array, the number of ways to choose two indices such that $A_i = A_j = x$ is given by the combination formula $\binom{f}{2} = \frac{f(f-1)}{2}$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the use of a `std::map` to store frequencies. If using `std::unordered_map`, it could be $O(N)$ on average, but $O(N \log N)$ is well within the limits for $N = 10^5$.
- **Space Complexity**: $O(N)$ to store the frequency of each distinct element in the map.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are looking for pairs (i, j) such that gcd(A_i, A_j) = lcm(A_i, A_j).
 * As derived, this condition is equivalent to A_i = A_j.
 * We count the frequency of each number and calculate the number of pairs
 * using the combination formula: f * (f - 1) / 2.
 */

void solve() {
    int n;
    cin >> n;
    
    // Using a map to count frequencies of each number.
    // Since N <= 10^5 and A_i <= 10^9, a map is efficient (O(N log N)).
    map<int, long long> counts;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        counts[a]++;
    }
    
    long long total_good_pairs = 0;
    for (auto const& [val, freq] : counts) {
        if (freq > 1) {
            total_good_pairs += (freq * (freq - 1)) / 2;
        }
    }
    
    cout << total_good_pairs << "\n";
}

int main() {
    // Fast I/O setup
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