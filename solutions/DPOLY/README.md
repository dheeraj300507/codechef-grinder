# [Degree of Polynomial (DPOLY)](https://www.codechef.com/problems/DPOLY)

- **Difficulty Rating**: 793
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a polynomial represented by $N$ coefficients $A_0, A_1, \dots, A_{N-1}$, where $A_i$ is the coefficient of $x^i$, find the degree of the polynomial. The degree is defined as the highest power of $x$ that has a non-zero coefficient.

## Intuition & Mathematical Observation
The degree of a polynomial $P(x) = \sum_{i=0}^{N-1} A_i x^i$ is the largest index $i$ such that $A_i \neq 0$. 

Since the input provides coefficients in increasing order of their powers ($A_0$ for $x^0$, $A_1$ for $x^1$, etc.), we can simply iterate through the array of coefficients. By keeping track of the index $i$ whenever we encounter a non-zero coefficient, the last index updated will naturally be the highest power with a non-zero coefficient.

**Key logic:**
- Initialize `degree = 0`.
- Iterate through the array from $i = 0$ to $N-1$.
- If $A_i \neq 0$, update `degree = i`.
- After the loop finishes, `degree` will hold the highest index with a non-zero coefficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of coefficients. We perform a single pass through the input array. With $T$ test cases, the total time complexity is $O(T \times N)$, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the coefficients (or $O(1)$ if we process the input on the fly without storing it in a vector).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The degree of a polynomial is the highest power of x whose coefficient is non-zero.
 * We are given N coefficients A_0, A_1, ..., A_{N-1} corresponding to x^0, x^1, ..., x^{N-1}.
 * We need to find the largest index i such that A_i != 0.
 * 
 * Constraints:
 * T <= 100, N <= 1000.
 * Time complexity per test case: O(N).
 * Total time complexity: O(T * N), which is well within the 1s limit.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int degree = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        // If the current coefficient is non-zero, update the degree.
        // Since we iterate from 0 to N-1, the last index i that satisfies 
        // A[i] != 0 will be the highest power.
        if (A[i] != 0) {
            degree = i;
        }
    }
    cout << degree << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```