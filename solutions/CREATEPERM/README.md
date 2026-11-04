# [Permutation Construction (CREATEPERM)](https://www.codechef.com/problems/CREATEPERM)

- **Difficulty Rating**: 1389
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an integer $N$, construct a permutation $P$ of length $N$ (containing all integers from $1$ to $N$ exactly once) such that for every index $i$ (where $1 < i < N$), the condition $P_i \ge (P_{i+1} - P_{i-1})^2$ is satisfied.

## Intuition & Mathematical Observation
The condition $P_i \ge (P_{i+1} - P_{i-1})^2$ is quite restrictive. If the difference $|P_{i+1} - P_{i-1}|$ is large, the square will grow very quickly, making it impossible to satisfy the inequality. Therefore, the key is to keep the difference between elements at distance 2 (i.e., $P_{i+1}$ and $P_{i-1}$) as small as possible.

By interleaving two sequences—the first half of the range $[1, N]$ and the second half—we can control these differences:
1. Divide the numbers $1$ to $N$ into two groups: $[1, \lceil N/2 \rceil]$ and $[\lceil N/2 \rceil + 1, N]$.
2. Arrange the permutation by picking one element from the first group, then one from the second, alternating back and forth.
3. This construction ensures that $P_{i+1}$ and $P_{i-1}$ are always consecutive or very close in value (often differing by only 1), which makes $(P_{i+1} - P_{i-1})^2$ equal to $1^2 = 1$ or $0^2 = 0$. Since $P_i \ge 1$ for all $i$, the condition $P_i \ge (P_{i+1} - P_{i-1})^2$ is easily satisfied for all valid $i$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to fill it and once to print it.
- **Space Complexity**: $O(N)$ to store the permutation before printing.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * The condition P[i] >= (P[i+1] - P[i-1])^2 is satisfied if 
 * |P[i+1] - P[i-1]| is small.
 * By interleaving the first half and the second half of the 
 * range [1, N], we ensure that the difference between 
 * adjacent elements in the interleaved sequence is roughly N/2, 
 * but the difference between elements at distance 2 is very small (usually 1).
 */

void solve() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << 1 << "\n";
        return;
    }
    
    vector<int> p(N);
    int mid = (N + 1) / 2;
    int left = 1;
    int right = mid + 1;
    
    for (int i = 0; i < N; ++i) {
        // Interleave elements from the first half and second half
        if (i % 2 == 0) {
            p[i] = left++;
        } else {
            p[i] = right++;
        }
    }
    
    for (int i = 0; i < N; ++i) {
        cout << p[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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