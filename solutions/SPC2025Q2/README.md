# [Itz Simple (SPC2025Q2)](https://www.codechef.com/problems/SPC2025Q2)

- **Difficulty Rating**: 791
- **Solved in**: 1 attempt(s)

## Problem Summary
Ved and Varun are playing a game with $N$ chairs, each having a specific height $A_i$. Ved takes the chair with the maximum height, while Varun takes all the remaining chairs. Ved starts with an initial height $K$ and Varun starts with an initial height $P$. We need to determine who has a greater total height after adding the heights of their respective chairs, or if their totals are equal.

## Intuition & Mathematical Observation
The problem defines the final heights as follows:
1. **Ved's Total Height**: $K + \max(A_1, A_2, \dots, A_N)$
2. **Varun's Total Height**: $P + (\sum_{i=1}^{N} A_i - \max(A_1, A_2, \dots, A_N))$

By calculating the sum of all chair heights and identifying the maximum height in the array, we can compute both totals directly. Since the constraints are small ($N \le 100$, $A_i \le 100$, $K, P \le 10^4$), the total height will not exceed $20,000$, which fits well within a standard 32-bit integer (though `long long` is used for safety).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to find the sum and the maximum value.
- **Space Complexity**: $O(N)$ to store the array, though this could be optimized to $O(1)$ by calculating the sum and max on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Ved gets the tallest chair (max(A_i)).
 * Varun gets all other chairs.
 * Ved's total height = K + max(A_i)
 * Varun's total height = P + (sum of all A_i - max(A_i))
 * 
 * We need to compare these two values and print Ved, Varun, or Equal.
 */

void solve() {
    int N;
    long long K, P;
    cin >> N >> K >> P;

    vector<long long> A(N);
    long long max_val = -1;
    long long sum_val = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        if (A[i] > max_val) {
            max_val = A[i];
        }
        sum_val += A[i];
    }

    // Ved gets the tallest chair
    long long ved_height = K + max_val;
    
    // Varun gets all chairs except the tallest one
    long long varun_height = P + (sum_val - max_val);

    if (ved_height > varun_height) {
        cout << "Ved" << "\n";
    } else if (varun_height > ved_height) {
        cout << "Varun" << "\n";
    } else {
        cout << "Equal" << "\n";
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
    }
    return 0;
}
```