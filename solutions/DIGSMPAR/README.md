# [Digit Sum Parities (DIGSMPAR)](https://www.codechef.com/problems/DIGSMPAR)

- **Difficulty Rating**: 1077
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to find the smallest integer $X > N$ such that the parity of the sum of digits of $X$ is different from the parity of the sum of digits of $N$.

## Intuition & Mathematical Observation
The parity of the sum of digits of an integer changes very frequently as we increment the number. For example, when moving from $N$ to $N+1$, the digit sum usually increases by 1 (unless a carry occurs, such as moving from 19 to 20). 

Because the parity of the digit sum flips almost every time we increment the number, we do not need to perform any complex mathematical search. We can simply iterate starting from $N+1$ and check the parity of the digit sum for each subsequent integer. The loop will terminate extremely quickly (usually within 1 to 2 iterations), making this approach highly efficient and well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(T \times K \times \log_{10}(N))$, where $T$ is the number of test cases, $K$ is the number of iterations required to find the next parity (which is a very small constant, $K \le 2$), and $\log_{10}(N)$ is the number of digits in $N$. Given the constraints, this is effectively $O(T \log N)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current number and its digit sum.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the smallest integer X > N such that digitSum(X) parity != digitSum(N) parity.
 * Since N < 10^9, the digit sum is relatively small (max digit sum for 999,999,999 is 81).
 * The parity of the digit sum changes very frequently as we increment N.
 * In the worst case, we only need to check a few consecutive integers to find one with a different parity.
 * A simple loop incrementing N and checking the parity of the digit sum will be highly efficient.
 */

// Function to calculate the sum of digits of a number
int getDigitSum(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}

void solve() {
    long long n;
    cin >> n;
    
    int targetParity = getDigitSum(n) % 2;
    long long x = n + 1;
    
    // Increment x until the parity of its digit sum is different from n's digit sum
    while (true) {
        if ((getDigitSum(x) % 2) != targetParity) {
            cout << x << "\n";
            break;
        }
        x++;
    }
}

int main() {
    // Fast I/O setup
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