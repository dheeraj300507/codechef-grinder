# [Leg Space (LEGSP)](https://www.codechef.com/problems/LEGSP)

- **Difficulty Rating**: 326
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is traveling on a bus with $N$ students and $M$ seats. Chef is happy if there is at least one empty seat available on the bus. We need to determine if Chef is happy given the values of $N$ and $M$.

## Intuition & Mathematical Observation
The problem states that the bus is "full" if the number of students equals the number of seats ($N = M$). If there are fewer students than seats ($N < M$), there will be at least one empty seat, making Chef happy. 

- If $N < M$: Chef is happy (**YES**).
- If $N = M$: The bus is full, so Chef is not happy (**NO**).

Since the problem constraints guarantee $N \le M$, we simply need to check if $N$ is strictly less than $M$.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution performs a single comparison and output operation regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a constant amount of memory to store the variables $N$ and $M$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is happy if the bus is NOT full.
 * The bus is full if the number of students (N) equals the number of seats (M).
 * The bus is not full if the number of students (N) is strictly less than the number of seats (M).
 * Given N <= M, the condition for Chef to be happy is N < M.
 * If N == M, the bus is full, and Chef is not happy.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, M;
    if (cin >> N >> M) {
        // Check if there is at least one empty seat
        if (N < M) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```