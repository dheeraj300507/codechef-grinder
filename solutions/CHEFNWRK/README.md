# [Chef and Work (CHEFNWRK)](https://www.codechef.com/problems/CHEFNWRK)

- **Difficulty Rating**: 1185
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ boxes with given weights $W_1, W_2, \dots, W_N$ that must be moved in the order they are given. Chef can carry any number of consecutive boxes in one trip, provided the total weight of the boxes in that trip does not exceed $K$. We need to find the minimum number of trips required to move all boxes. If any single box weighs more than $K$, it is impossible to move it, and we should output -1.

## Intuition & Mathematical Observation
The problem requires moving boxes in their original sequence. Since we want to minimize the number of trips, we should use a **Greedy Approach**:
1. **Feasibility Check**: First, iterate through all boxes. If any box $W_i > K$, it is impossible to move, so we immediately return -1.
2. **Greedy Packing**: Start a trip and add boxes one by one as long as the current sum of weights does not exceed $K$. Once adding the next box would exceed $K$, finish the current trip, increment the trip counter, and start a new trip with the current box.
3. **Efficiency**: Because we process each box exactly once, this greedy strategy ensures we pack the maximum possible weight into each trip, which mathematically guarantees the minimum number of trips.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of boxes. We iterate through the array of weights exactly once.
- **Space Complexity**: $O(N)$ to store the weights of the boxes. (Note: This could be optimized to $O(1)$ if we processed input on the fly, but $O(N)$ is well within limits).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs to pick boxes in order from 1 to N.
 * He can pick a sequence of boxes as long as their sum <= K.
 * If any single box weight > K, it's impossible to move it, return -1.
 * Otherwise, we greedily pack as many boxes as possible into one trip.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store weights.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<int> W(N);
    for (int i = 0; i < N; ++i) {
        cin >> W[i];
    }

    // Check if any single box is heavier than K
    for (int i = 0; i < N; ++i) {
        if (W[i] > K) {
            cout << -1 << "\n";
            return;
        }
    }

    int trips = 0;
    int current_weight = 0;
    int i = 0;
    
    while (i < N) {
        // Start a new trip
        trips++;
        current_weight = 0;
        
        // Fill the current trip as much as possible
        while (i < N && current_weight + W[i] <= K) {
            current_weight += W[i];
            i++;
        }
    }

    cout << trips << "\n";
}

int main() {
    // Fast I/O
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