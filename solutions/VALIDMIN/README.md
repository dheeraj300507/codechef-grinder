# [Valid Minimum (VALIDMIN)](https://www.codechef.com/problems/VALIDMIN)

- **Difficulty Rating**: 1132
- **Solved in**: 1 attempt(s)

## Problem Summary
Given three integers $P, Q,$ and $R$, determine if there exist three integers $A, B,$ and $C$ such that:
- $\min(A, B) = P$
- $\min(B, C) = Q$
- $\min(C, A) = R$

If such a triplet $(A, B, C)$ exists, output `YES`; otherwise, output `NO`.

## Intuition & Mathematical Observation
Let the given values be $P, Q, R$. Without loss of generality, assume we sort these values such that $m_1 \le m_2 \le m_3$.

Consider the properties of the minimum function:
1. If we have three values $A, B, C$, their pairwise minimums are $x = \min(A, B)$, $y = \min(B, C)$, and $z = \min(C, A)$.
2. If we sort $A, B, C$ such that $A \le B \le C$, then:
   - $\min(A, B) = A$
   - $\min(B, C) = B$
   - $\min(C, A) = A$
3. This implies that in any valid configuration, the two smallest values among the three results ($P, Q, R$) must be equal. 

**Proof:**
If we sort the results $P, Q, R$ as $m_1 \le m_2 \le m_3$, the condition $m_1 = m_2$ must hold. 
- If $m_1 = m_2$, we can construct a valid set. For example, if we have $m_1, m_1, m_3$, we can set $A = m_3, B = m_1, C = m_1$.
- Then:
  - $\min(A, B) = \min(m_3, m_1) = m_1$
  - $\min(B, C) = \min(m_1, m_1) = m_1$
  - $\min(C, A) = \min(m_1, m_3) = m_1$
- This results in the set $\{m_1, m_1, m_1\}$, which is a valid subset of $\{m_1, m_1, m_3\}$ if $m_3 \ge m_1$. If $m_3$ is larger, we can adjust the values to satisfy the specific $m_3$ requirement. Essentially, the condition simplifies to checking if the two smallest values of the input are equal.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of operations (sorting 3 elements).
- **Space Complexity**: $O(1)$, as we only use a fixed-size array to store the three integers.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * After sorting the three inputs P, Q, R as m1 <= m2 <= m3,
 * the condition for a valid tuple (A, B, C) is that the two 
 * smallest values must be equal (m1 == m2).
 */

void solve() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    
    // Sort the three inputs to easily compare the smallest values
    sort(arr, arr + 3);
    
    // If the two smallest values are equal, a valid triplet exists
    if (arr[0] == arr[1]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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