# [Prime Generator (PRIME1)](https://www.codechef.com/problems/PRIME1)

- **Difficulty Rating**: 1069
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to generate all prime numbers within a given range $[m, n]$, where $1 \le m \le n \le 10^9$ and $n - m \le 10^5$. Since the range size is relatively small but the absolute values can be quite large, a standard Sieve of Eratosthenes up to $10^9$ is not feasible due to memory and time constraints.

## Intuition & Mathematical Observation
To solve this efficiently, we use the **Segmented Sieve** technique:
1. **Precomputation**: Any composite number $x \le 10^9$ must have a prime factor $\le \sqrt{10^9} \approx 31622$. We first find all primes up to $\sqrt{n}$ using a standard sieve.
2. **Range Marking**: We create a boolean array `is_prime_range` of size $(n - m + 1)$ representing the numbers from $m$ to $n$.
3. **Sieving**: For each prime $p$ found in the precomputation step, we mark its multiples within the range $[m, n]$ as `false`. 
   - The first multiple of $p$ greater than or equal to $m$ can be calculated as `start = (m + p - 1) / p * p`.
   - We ensure `start` is at least $p^2$ to avoid marking the prime $p$ itself as composite.
4. **Output**: After marking all multiples, any index $i$ in `is_prime_range` that remains `true` corresponds to a prime number $m + i$.

## Complexity Analysis
- **Time Complexity**: $O(\sqrt{n} \log \log \sqrt{n} + (n - m + 1) \log \log n)$. The first part is for the initial sieve, and the second part is for marking the range $[m, n]$ using the precomputed primes. Given $n-m \le 10^5$, this is well within the time limits.
- **Space Complexity**: $O(\sqrt{n} + (n - m))$, which is approximately $O(31622 + 10^5)$, fitting comfortably within standard memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: PRIME1 - Prime Generator
 * Approach: Segmented Sieve
 */

void solve() {
    long long m, n;
    cin >> m >> n;

    if (m < 2) m = 2;
    if (m > n) return;

    int limit = sqrt(n) + 1;
    vector<int> primes;
    vector<bool> is_prime_small(limit + 1, true);
    is_prime_small[0] = is_prime_small[1] = false;

    // Precompute primes up to sqrt(n)
    for (int p = 2; p * p <= limit; p++) {
        if (is_prime_small[p]) {
            for (int i = p * p; i <= limit; i += p)
                is_prime_small[i] = false;
        }
    }
    for (int p = 2; p <= limit; p++) {
        if (is_prime_small[p]) primes.push_back(p);
    }

    // Segmented Sieve for range [m, n]
    vector<bool> is_prime_range(n - m + 1, true);

    for (int p : primes) {
        // Find the first multiple of p in [m, n]
        long long start = (m + p - 1) / p * p;
        if (start < (long long)p * p) start = (long long)p * p;
        
        for (long long j = start; j <= n; j += p) {
            is_prime_range[j - m] = false;
        }
    }

    for (long long i = m; i <= n; i++) {
        if (is_prime_range[i - m]) {
            cout << i << "\n";
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
        if (t > 0) cout << "\n";
    }
    return 0;
}
```