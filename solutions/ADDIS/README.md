# [Additive Dissonance (ADDIS)](https://www.codechef.com/problems/ADDIS)

- **Difficulty Rating**: 1064
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to choose an integer $X$ such that if we construct a new array $B$ where each element $B_i = A_i + X$ or $B_i = A_i - X$, the maximum frequency of any element in $B$ is minimized. We want to find the minimum possible value of this maximum frequency.

## Intuition & Mathematical Observation
The goal is to distribute the occurrences of the most frequent element in $A$ across two different values in $B$. 

1. Let $V$ be the element in $A$ that appears with the maximum frequency, denoted as `max_f`.
2. For any chosen $X$, each occurrence of $V$ in $A$ can be transformed into either $V+X$ or $V-X$ in $B$.
3. If we choose $X$ such that $V+X \neq V-X$ (which is true for any $X \neq 0$), we can split the `max_f` occurrences of $V$ into two groups: those that become $V+X$ and those that become $V-X$.
4. To minimize the maximum frequency, we should split these occurrences as evenly as possible. If we have `max_f` occurrences, we can assign $\lceil \text{max\_f} / 2 \rceil$ to $V+X$ and $\lfloor \text{max\_f} / 2 \rfloor$ to $V-X$.
5. Since we can choose $X$ to be sufficiently large or specific to avoid collisions with other elements in $A$, the bottleneck for the maximum frequency will always be the most frequent element. Thus, the answer is simply $\lceil \text{max\_f} / 2 \rceil$, which can be calculated using integer division as `(max_f + 1) / 2`.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ or $O(N)$ depending on the map implementation. Using `std::map` takes $O(N \log N)$, while `std::unordered_map` would take $O(N)$ on average. Given the constraints, $O(N \log N)$ is well within the limits.
- **Space Complexity**: $O(N)$ to store the frequency counts of the elements in the map.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * The problem asks to minimize the maximum frequency of any element in B.
 * By choosing an appropriate X, we can split the occurrences of the most 
 * frequent element V into V+X and V-X.
 * The optimal strategy is to distribute the max_f occurrences as evenly 
 * as possible, resulting in ceil(max_f / 2).
 */

void solve() {
    int N;
    cin >> N;
    map<int, int> counts;
    int max_f = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        counts[a]++;
        max_f = max(max_f, counts[a]);
    }
    
    // The minimum possible maximum frequency is ceil(max_f / 2.0)
    cout << (max_f + 1) / 2 << "\n";
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