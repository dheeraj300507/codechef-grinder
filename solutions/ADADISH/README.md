# [Ada and Dishes (ADADISH)](https://www.codechef.com/problems/ADADISH)

- **Difficulty Rating**: 1237
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ dishes, each requiring a specific preparation time $C_i$. We have two burners available, and each burner can process dishes sequentially. A burner can only work on one dish at a time. We need to distribute the dishes between the two burners such that the time when both burners finish their assigned tasks is minimized. In other words, we want to minimize $\max(\text{sum of times on burner 1}, \text{sum of times on burner 2})$.

## Intuition & Mathematical Observation
The constraint on $N$ is very small ($N \le 4$). This allows us to explore all possible ways to partition the set of dishes into two groups. 

For each dish, we have two choices: assign it to Burner 1 or assign it to Burner 2. Since there are $N$ dishes, there are $2^N$ possible ways to distribute them. We can represent these assignments using a bitmask from $0$ to $2^N - 1$. 
- If the $j$-th bit of the mask is $1$, we assign dish $j$ to Burner 1.
- If the $j$-th bit of the mask is $0$, we assign dish $j$ to Burner 2.

For every mask, we calculate the total time taken by Burner 1 and Burner 2. The time taken for that specific configuration is $\max(\text{Burner 1 time}, \text{Burner 2 time})$. By iterating through all $2^N$ masks, we can find the minimum possible value among all configurations.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot 2^N \cdot N)$, where $T$ is the number of test cases. Given $N \le 4$, $2^4 = 16$, making this approach extremely efficient.
- **Space Complexity**: $O(N)$ to store the preparation times of the dishes.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N dishes with preparation times C_i and two burners.
 * Since N is very small (N <= 4), we can solve this using recursion or bitmasking.
 * We want to partition the set of dishes into two subsets (burner 1 and burner 2)
 * such that the maximum of the sum of times in each subset is minimized.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }

    int min_time = 1e9;

    // Since N is at most 4, we can iterate through all 2^N possible 
    // assignments of dishes to two burners using a bitmask.
    for (int i = 0; i < (1 << N); ++i) {
        int burner1 = 0;
        int burner2 = 0;
        for (int j = 0; j < N; ++j) {
            if ((i >> j) & 1) {
                burner1 += C[j];
            } else {
                burner2 += C[j];
            }
        }
        min_time = min(min_time, max(burner1, burner2));
    }

    cout << min_time << "\n";
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