# [Best Seats (BESTSEATS)](https://www.codechef.com/problems/BESTSEATS)

- **Difficulty Rating**: 848
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers representing the cost of seats in a row, the goal is to find the minimum sum of any two adjacent seats. We need to iterate through the array and calculate the sum of every pair $(A[i], A[i+1])$ and identify the smallest one.

## Intuition & Mathematical Observation
Since we are looking for the minimum sum of two adjacent elements, we can perform a single linear scan through the array. 
1. We initialize a variable `min_cost` with a very large value (infinity).
2. We loop from index $0$ to $N-2$.
3. In each iteration, we calculate the sum of the current element $A[i]$ and the next element $A[i+1]$.
4. If this sum is smaller than our current `min_cost`, we update `min_cost`.
5. After checking all adjacent pairs, `min_cost` will hold the minimum value.

Given that $N$ is small (up to 100), this $O(N)$ approach is highly efficient and well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of seats. We traverse the array exactly once.
- **Space Complexity**: $O(N)$ to store the input array. (Note: This could be optimized to $O(1)$ by storing only the previous element, but $O(N)$ is perfectly acceptable given the constraints).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Best Seats
 * The goal is to find the minimum sum of two adjacent elements in an array A of size N.
 * Since N is small (up to 100), a simple linear scan O(N) is optimal.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_cost with a value larger than any possible sum.
    // Max A_i is 100, so max sum is 200.
    long long min_cost = 1e18;
    
    // Iterate through the array and check the sum of every pair of adjacent seats.
    for (int i = 0; i < N - 1; ++i) {
        long long current_sum = (long long)A[i] + A[i + 1];
        if (current_sum < min_cost) {
            min_cost = current_sum;
        }
    }
    
    cout << min_cost << "\n";
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