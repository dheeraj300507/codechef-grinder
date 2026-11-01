# [Luigi and Uniformity (DIVIDEMAKEEQ)](https://www.codechef.com/problems/DIVIDEMAKEEQ)

- **Difficulty Rating**: 1185
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to make all elements equal. In one operation, we can choose an index $i$ and replace $A_i$ with $A_i / X$, where $X$ is any divisor of $A_i$ such that $X > 1$. We want to find the minimum number of operations required to make all elements in the array equal.

## Intuition & Mathematical Observation
1. **Target Value**: To make all elements equal using the division operation, the final value must be a common divisor of all elements in the original array.
2. **GCD Property**: Any common divisor of the array elements must also be a divisor of the Greatest Common Divisor (GCD) of the entire array. Let $G = \text{gcd}(A_1, A_2, \dots, A_N)$.
3. **Feasibility**: Any element $A_i$ can be reduced to any of its divisors. Since $G$ divides every $A_i$, we can reduce every element in the array to $G$ in at most one operation (if $A_i > G$, we divide by $A_i/G$; if $A_i = G$, we do nothing).
4. **Optimization**: The problem asks for the minimum operations. If we choose the target value to be $G$, the cost is the number of elements $A_i$ such that $A_i \neq G$. This is equivalent to $N - (\text{count of } G \text{ in } A)$.
5. **Refinement**: While the logic above holds for $G$, we must consider if any other common divisor $V$ could yield a better result. However, since $V$ must be a divisor of $G$, and any $A_i$ that is a multiple of $G$ is also a multiple of $V$, we can always reach $V$ from $A_i$. But to reach $V$, we need $A_i$ to be a multiple of $V$. Since $G$ is the largest common divisor, choosing $G$ as the target is always optimal because it is the "closest" target to the original values that every element can reach.

## Complexity Analysis
- **Time Complexity**: $O(N \log(\min(A)) + \sqrt{G})$, where $N$ is the number of elements and $G$ is the GCD of the array. Calculating the GCD takes $O(N \log(\min(A)))$, and finding divisors takes $O(\sqrt{G})$. The final frequency count is $O(N)$.
- **Space Complexity**: $O(N)$ to store the array elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Strategy:
 * 1. Calculate G = gcd(A_1, A_2, ..., A_N).
 * 2. Any common divisor V of the array must be a divisor of G.
 * 3. To minimize moves, we want to reach a common value. 
 *    Since G is the greatest common divisor, every element A[i] 
 *    can be reduced to G in exactly 1 move if A[i] > G, 
 *    or 0 moves if A[i] == G.
 * 4. Thus, the minimum moves = N - (count of elements already equal to G).
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long g = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) g = a[i];
        else g = gcd(g, a[i]);
    }

    // Count how many elements are already equal to the GCD
    int count_g = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == g) {
            count_g++;
        }
    }

    // The elements not equal to g need 1 operation to become g
    cout << n - count_g << "\n";
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