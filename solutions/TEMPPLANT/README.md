# [Plant (TEMPPLANT)](https://www.codechef.com/problems/TEMPPLANT)

- **Difficulty Rating**: 675
- **Solved in**: 2 attempt(s)

## Problem Summary
You are given an array of $N$ temperatures representing $N$ consecutive days. You need to plant a seed on two consecutive days $(i, i+1)$. The resulting height of the tree is defined as the minimum of the temperatures on those two days, i.e., $\min(A_i, A_{i+1})$. The goal is to choose the pair $(i, i+1)$ that maximizes this height.

## Intuition & Mathematical Observation
The problem asks us to evaluate the minimum value for every adjacent pair in the array and identify the largest among those minimums. 

1. **Iteration**: Since we need to check every consecutive pair, we can iterate through the array from index $0$ to $N-2$.
2. **Comparison**: For each index $i$, we calculate $H_i = \min(A_i, A_{i+1})$.
3. **Maximization**: We maintain a variable `max_height` and update it whenever we find a pair that yields a higher value than the current maximum.
4. **Constraints**: With $N$ up to 100 and $T$ up to 100, a simple linear scan $O(N)$ per test case is well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of days. We perform a single pass through the array.
- **Space Complexity**: $O(N)$ to store the input array. This could be optimized to $O(1)$ by only storing the previous element, but $O(N)$ is perfectly acceptable given the constraints.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We are given N days with temperatures A_1, A_2, ..., A_N.
 * We need to choose two consecutive days (i, i+1) to plant the seed.
 * The height of the tree is min(A_i, A_{i+1}).
 * We want to maximize this value over all possible i from 0 to N-2.
 * 
 * Complexity:
 * Time: O(N) per test case. With N=100 and T=100, total operations ~10^4.
 * Space: O(N) to store the temperatures.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Initialize max_height with the smallest possible value
    // Since A_i >= 1, 0 is a safe initial value.
    int max_height = 0;
    
    // Iterate through all possible pairs of consecutive days
    // There are N-1 such pairs.
    for (int i = 0; i < N - 1; ++i) {
        int current_height = min(A[i], A[i + 1]);
        if (current_height > max_height) {
            max_height = current_height;
        }
    }
    
    cout << max_height << "\n";
}

int main() {
    // Fast I/O setup
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