# [Movie Hype (MOVHYPE)](https://www.codechef.com/problems/MOVHYPE)

- **Difficulty Rating**: 921
- **Solved in**: 1 attempt(s)

## Problem Summary
In a theater with $2N+1$ seats, the odd-numbered seats ($1, 3, 5, \dots, 2N+1$) are occupied by people with specific "hype levels" $A_1, A_2, \dots, A_{N+1}$. The even-numbered seats ($2, 4, \dots, 2N$) are empty. The "loudness" of an empty seat is defined as the maximum hype level of the two people sitting immediately adjacent to it. We need to find the **minimum** loudness among all $N$ empty seats.

## Intuition & Mathematical Observation
- The empty seats are located at positions $2, 4, \dots, 2N$.
- An empty seat at position $2i$ (where $i$ ranges from $1$ to $N$) is adjacent to the occupied seats at $2i-1$ and $2i+1$.
- Given the input array $A$ of size $N+1$, the hype levels are $A_0, A_1, \dots, A_N$ (using 0-based indexing).
- The empty seat at index $i$ (in terms of gaps) is adjacent to $A_i$ and $A_{i+1}$.
- The loudness for each gap is $\max(A_i, A_{i+1})$.
- To find the minimum loudness, we simply iterate through the array, calculate the maximum of every adjacent pair, and track the smallest value found.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of empty seats. We perform a single pass through the array of size $N+1$.
- **Space Complexity**: $O(N)$ to store the hype levels. This could be optimized to $O(1)$ by storing only the previous element, but $O(N)$ is well within limits for the given constraints.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The theater has 2N+1 seats.
 * Occupied seats are 1, 3, 5, ..., 2N+1.
 * Empty seats are 2, 4, 6, ..., 2N.
 * 
 * Let the hype levels be A_0, A_1, ..., A_N.
 * The empty seat between A_i and A_{i+1} has a loudness of max(A_i, A_{i+1}).
 * We iterate through all i from 0 to N-1 and find the minimum of these values.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N + 1);
    for (int i = 0; i <= N; ++i) {
        cin >> A[i];
    }
    
    // Initialize min_loudness with a value larger than any possible hype level
    long long min_loudness = 200; 
    
    // There are N empty seats, corresponding to gaps between (A_0, A_1), (A_1, A_2), ..., (A_{N-1}, A_N).
    for (int i = 0; i < N; ++i) {
        long long current_loudness = max(A[i], A[i + 1]);
        if (current_loudness < min_loudness) {
            min_loudness = current_loudness;
        }
    }
    
    cout << min_loudness << "\n";
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