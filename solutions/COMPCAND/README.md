# [Can You Eat It (COMPCAND)](https://www.codechef.com/problems/COMPCAND)

- **Difficulty Rating**: 960
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a candy of length $N$ and you eat $K$ units of the candy in each bite. You need to determine if it is possible to eat the entire candy such that no part of the candy remains. If it is possible, output the total number of bites taken; otherwise, output -1.

## Intuition & Mathematical Observation
The problem asks whether $N$ can be partitioned into equal segments of size $K$. 

1. **Divisibility**: If $N$ is perfectly divisible by $K$ (i.e., $N \pmod K == 0$), then we can consume the entire candy in exactly $N/K$ bites.
2. **Remainder**: If $N$ is not divisible by $K$, there will always be a remainder $R$ where $0 < R < K$. Since we must eat exactly $K$ units per bite, we cannot finish the remaining $R$ units. Thus, it is impossible to finish the candy, and we output -1.
3. **Edge Case**: If $N = 0$, the candy is already finished, requiring 0 bites.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a candy of length N and we eat K units per bite.
 * We can eat the entire candy if and only if N is perfectly divisible by K.
 * If N % K == 0, the number of bites is N / K.
 * If N % K != 0, we will eventually be left with a remainder (N % K) which is 
 * greater than 0 but less than K, meaning we cannot finish the candy.
 * 
 * Special case: If N = 0, we have already eaten the candy, so 0 bites.
 * Constraints: N, K up to 10^6, T up to 10^5. O(1) per test case is required.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // If candy length is 0, we need 0 bites.
        if (n == 0) {
            cout << 0 << "\n";
        } 
        // If N is divisible by K, we can finish it in N/K bites.
        else if (n % k == 0) {
            cout << (n / k) << "\n";
        } 
        // Otherwise, we are left with a remainder < K, so it's impossible.
        else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
```