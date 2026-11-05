# [Easy Math (RPD)](https://www.codechef.com/problems/RPD)

- **Difficulty Rating**: 1133
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, we need to select two distinct indices $i$ and $j$ ($i \neq j$) such that the sum of the digits of the product $A[i] \times A[j]$ is maximized. We are required to output this maximum sum.

## Intuition & Mathematical Observation
The constraints for this problem are quite small:
- $N \le 100$
- $A[i] \le 10^4$

Since $N$ is at most 100, the total number of pairs $(i, j)$ is given by $\binom{N}{2} = \frac{N(N-1)}{2}$, which is at most $\frac{100 \times 99}{2} = 4,950$. 

Given that the maximum value of $A[i]$ is $10^4$, the maximum possible product is $10^4 \times 10^4 = 10^8$. The sum of digits of a number up to $10^8$ is relatively small (the maximum sum of digits for a number less than $10^8$ is for $99,999,999$, which is $9 \times 8 = 72$). 

Because the number of pairs is very small and the calculation for the sum of digits is efficient, a **brute-force approach** checking every possible pair is optimal and well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2 \times \log(\max(A_i^2)))$, where $T$ is the number of test cases. With $N=100$, this results in approximately $10^6$ operations, which easily passes within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of N integers (2 <= N <= 100).
 * We need to find two different elements A[i] and A[j] (i != j) such that
 * the sum of digits of their product (A[i] * A[j]) is maximized.
 * 
 * Constraints:
 * N <= 100
 * A[i] <= 10^4
 * 
 * Since N is small (up to 100), an O(N^2) approach is perfectly acceptable.
 * 100 * 100 = 10,000 operations per test case.
 * With T = 100, total operations are ~1,000,000, which easily fits in 1s.
 */

// Function to calculate the sum of digits of a number
int sumOfDigits(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int max_sum = 0;

    // Iterate through all pairs (i, j) where i < j
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long product = A[i] * A[j];
            int current_sum = sumOfDigits(product);
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    cout << max_sum << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```