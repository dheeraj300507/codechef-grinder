# [More Cookies (MORECOOK)](https://www.codechef.com/problems/MORECOOK)

- **Difficulty Rating**: 890
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has $C$ cookies, and there are $N$ friends, each having $A_i$ cookies. Alice wants to increase her cookie count by $x$ (where $x \ge 0$) such that her new total $C' = C + x$ satisfies two conditions:
1. There is at least one friend with strictly fewer cookies than Alice ($A_i < C'$).
2. No friend has exactly the same number of cookies as Alice ($A_i \neq C'$).

We need to find the smallest non-negative integer $x$ that satisfies these conditions.

## Intuition & Mathematical Observation
Since the constraints on $N$ and $A_i$ are small (up to 100), we do not need a complex mathematical formula. We can use a **brute-force simulation** approach:
1. Start with $x = 0$.
2. Calculate the candidate total $C' = C + x$.
3. Iterate through the array $A$ to verify the two conditions:
   - **Condition 1**: Check if any $A_i < C'$.
   - **Condition 2**: Check if no $A_i == C'$.
4. If both conditions are met, $x$ is our answer. If not, increment $x$ by 1 and repeat.

Because the number of friends is small and the values are bounded, this loop will terminate very quickly.

## Complexity Analysis
- **Time Complexity**: $O(T \times x_{max} \times N)$, where $T$ is the number of test cases, $x_{max}$ is the minimum cookies needed (which is small), and $N$ is the number of friends. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the array of friends' cookies.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has C cookies. Friends have A_1, A_2, ..., A_N cookies.
 * Alice is happy if:
 * 1. There exists at least one friend with A_i < C.
 * 2. There is no friend with A_i == C.
 * 
 * We need to find the minimum extra cookies 'x' such that (C + x) satisfies the conditions.
 */

void solve() {
    int N, C;
    cin >> N >> C;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int x = 0;
    while (true) {
        int current_C = C + x;
        
        // Check condition 2: No other friend has equal cookies
        bool equal_exists = false;
        for (int i = 0; i < N; ++i) {
            if (A[i] == current_C) {
                equal_exists = true;
                break;
            }
        }
        
        // Check condition 1: At least one friend has strictly less
        bool less_exists = false;
        for (int i = 0; i < N; ++i) {
            if (A[i] < current_C) {
                less_exists = true;
                break;
            }
        }
        
        if (!equal_exists && less_exists) {
            cout << x << "\n";
            return;
        }
        
        x++;
    }
}

int main() {
    // Fast I/O
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