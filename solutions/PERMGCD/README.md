# [Permutation GCD (PERMGCD)](https://www.codechef.com/problems/PERMGCD)

- **Difficulty Rating**: 1328
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $X$, we need to construct a permutation $P$ of the set $\{1, 2, \dots, N\}$ such that the sum of the prefix GCDs of the permutation equals $X$. That is, $\sum_{i=1}^{N} \gcd(P_1, P_2, \dots, P_i) = X$. If no such permutation exists, output -1.

## Intuition & Mathematical Observation
1. **Lower Bound**: The minimum possible sum of prefix GCDs is $N$. This occurs when the GCD becomes 1 immediately (or stays 1 throughout). If $X < N$, it is impossible to satisfy the condition.
2. **Construction Strategy**: We can force the prefix GCD to be some integer $g$ for the first $k$ elements by picking $k$ multiples of $g$ (i.e., $g, 2g, 3g, \dots, kg$). 
   - The sum of the first $k$ prefix GCDs will be $k \times g$.
   - After these $k$ elements, if we include any number not divisible by $g$, the GCD will immediately drop to 1.
   - The remaining $(N-k)$ elements will each contribute 1 to the sum.
   - Total sum $S = (k \times g) + (N - k)$.
3. **Solving for $k$**:
   - $X = kg + N - k$
   - $X - N = k(g - 1)$
   - $k = \frac{X - N}{g - 1}$
4. **Constraints**: We iterate through all possible values of $g$ from $1$ to $N$. For a valid $g$, we check if $(X - N)$ is divisible by $(g - 1)$ and if the resulting $k$ satisfies $1 \le k \le \lfloor N/g \rfloor$ (since we need $k$ distinct multiples of $g$ available in the range $[1, N]$).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. We iterate through $g$ from $1$ to $N$, and the construction of the permutation takes $O(N)$. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the permutation and the `used` array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Strategy:
 * We aim to maintain a prefix GCD of 'g' for the first 'k' elements.
 * By picking multiples of g (g, 2g, ..., kg), the sum is k*g + (N-k).
 * We iterate through all possible g and check if a valid k exists.
 */

void solve() {
    int N, X;
    cin >> N >> X;

    if (X < N) {
        cout << -1 << "\n";
        return;
    }

    // Try all possible starting GCDs 'g'
    for (int g = 1; g <= N; ++g) {
        // Special case for g=1: sum is always N if we start with 1
        if (g == 1) {
            if (X == N) {
                for (int i = 1; i <= N; ++i) cout << i << (i == N ? "" : " ");
                cout << "\n";
                return;
            }
            continue;
        }

        // Check if k = (X - N) / (g - 1) is valid
        if ((X - N) % (g - 1) == 0) {
            int k = (X - N) / (g - 1);
            if (k >= 1 && k <= N / g) {
                vector<bool> used(N + 1, false);
                vector<int> res;
                
                // Add k multiples of g
                for (int i = 1; i <= k; ++i) {
                    res.push_back(i * g);
                    used[i * g] = true;
                }
                
                // Add remaining numbers
                for (int i = 1; i <= N; ++i) {
                    if (!used[i]) {
                        res.push_back(i);
                    }
                }
                
                for (int i = 0; i < N; ++i) cout << res[i] << (i == N - 1 ? "" : " ");
                cout << "\n";
                return;
            }
        }
    }

    cout << -1 << "\n";
}

int main() {
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