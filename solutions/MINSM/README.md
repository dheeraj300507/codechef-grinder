# [Minimum Sum (MINSM)](https://www.codechef.com/problems/MINSM)

- **Difficulty Rating**: 1315
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, you are allowed to perform an operation any number of times: choose two indices $i$ and $j$ and replace either $A_i$ or $A_j$ with $\gcd(A_i, A_j)$. The goal is to minimize the sum of the elements in the array after performing any number of operations.

## Intuition & Mathematical Observation
1. **GCD Property**: The operation allows us to replace an element with the greatest common divisor of two elements. By repeatedly applying this, we can eventually transform any element into the GCD of the entire array.
2. **Lower Bound**: Let $G = \gcd(A_1, A_2, \dots, A_N)$. Since every element in the array must be a multiple of the GCD of the final array, and the final GCD must be a multiple of the original $G$, every element in the final array must be at least $G$.
3. **Optimality**: If we reduce every element in the array to $G$, the sum becomes $N \times G$. Since each element $A_i \ge G$, the sum $\sum A_i \ge N \times G$. Therefore, $N \times G$ is the theoretical minimum sum achievable.
4. **Conclusion**: The minimum sum is simply the number of elements multiplied by the greatest common divisor of all elements in the initial array.

## Complexity Analysis
- **Time Complexity**: $O(N \cdot \log(\min(A)))$, where $N$ is the number of elements. We iterate through the array once and perform a GCD operation at each step. The Euclidean algorithm for GCD takes logarithmic time relative to the values of the elements.
- **Space Complexity**: $O(N)$ to store the input array (though this could be optimized to $O(1)$ by calculating the GCD on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * By repeatedly applying the operation, we can make every element in the array
 * equal to the greatest common divisor (G) of all elements in the array.
 * Since every element must be at least G, the minimum possible sum is N * G.
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    long long g = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (i == 0) g = A[i];
        else g = gcd(g, A[i]);
    }
    
    // The minimum sum is N * gcd(all elements)
    cout << (long long)N * g << "\n";
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