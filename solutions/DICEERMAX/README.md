# [Erase and Maximize (DICEERMAX)](https://www.codechef.com/problems/DICEERMAX)

- **Difficulty Rating**: 1226
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ dice, each initially having faces $\{1, 2, 3, 4, 5, 6\}$. We must choose values $x_1, x_2, \dots, x_N$ such that $\sum x_i = S$ and $1 \le x_i \le 6$. After choosing these values, the chosen face $x_i$ is removed from the $i$-th die. We then want to maximize the sum of new values $y_i$ chosen from the remaining faces of each die.

## Intuition & Mathematical Observation
For any die $i$, if we choose $x_i$, the new set of available faces is $\{0, 1, 2, 3, 4, 5, 6\} \setminus \{x_i\}$. To maximize the new sum $\sum y_i$:
- If $x_i < 6$, we can pick $y_i = 6$.
- If $x_i = 6$, we must pick $y_i = 5$ (since 6 is no longer available).

To maximize the total score, we want to minimize the number of dice where $x_i = 6$. Let $k$ be the number of dice where $x_i = 6$. The total score is:
$$\text{Score} = (N - k) \times 6 + k \times 5 = 6N - k$$

To minimize $k$, we want the remaining $(N-k)$ dice to contribute as much as possible to the sum $S$ without being 6. The maximum value a non-6 die can take is 5. Thus:
$$S \le (N - k) \times 5 + k \times 6$$
$$S \le 5N - 5k + 6k$$
$$S \le 5N + k$$
$$k \ge S - 5N$$

Since $k$ cannot be negative, the minimum number of 6s required is $k = \max(0, S - 5N)$. Substituting this into our score formula gives the maximum possible result.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the score (6N - k), we need to minimize k (the number of 6s used).
 * Given the constraint sum(x_i) = S, and knowing that non-6 dice can contribute 
 * at most 5, we derive k = max(0, S - 5N).
 */

void solve() {
    long long N, S;
    cin >> N >> S;
    
    // k is the minimum number of 6s we must use to reach sum S.
    // If S <= 5N, we don't need any 6s (k=0).
    // If S > 5N, each unit above 5N forces one die to be a 6 instead of a 5.
    long long k = max(0LL, S - 5 * N);
    
    // The score is 6 for every die that wasn't a 6, and 5 for every die that was.
    long long max_score = 6 * (N - k) + 5 * k;
    cout << max_score << "\n";
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