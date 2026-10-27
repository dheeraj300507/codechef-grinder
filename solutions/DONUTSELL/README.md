# [Selling Donuts (DONUTSELL)](https://www.codechef.com/problems/DONUTSELL)

- **Difficulty Rating**: 754
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ types of donuts, each with a specific initial quantity stored in an array $A$. There are $M$ customers arriving in a sequence, where each customer requests a specific type of donut. If the requested donut type is available (quantity > 0), we decrement the count for that type. If the quantity is 0, the customer is considered "sad." The goal is to count the total number of sad customers after all $M$ requests are processed.

## Intuition & Mathematical Observation
The problem is a direct simulation task. Since the constraints on $N$ and $M$ are small (up to 100), we do not need any complex data structures or optimization algorithms. 

1. **Data Storage**: We use a vector (or array) of size $N+1$ to store the counts of each donut type, allowing for $O(1)$ access using the donut type index.
2. **Simulation**: We iterate through the list of $M$ customer requests. For each request:
   - Check if the current count of the requested donut type is greater than 0.
   - If yes, decrement the count.
   - If no, increment a counter tracking the number of sad customers.
3. **Efficiency**: Because we process each customer exactly once and perform constant-time operations for each, the simulation is highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$ per test case. We spend $O(N)$ to read the initial donut counts and $O(M)$ to process the customer requests. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the quantities of the $N$ donut types.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Selling Donuts
 * Approach:
 * We are given N types of donuts with initial counts A_i.
 * M customers arrive sequentially, each requesting a specific type B_i.
 * If A[B_i] > 0, we decrement A[B_i] and the customer is satisfied.
 * If A[B_i] == 0, the customer is sad.
 * 
 * Since N and M are small (up to 100), a simple simulation is O(M) per test case,
 * which is well within the time limits.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    // Use 1-based indexing for convenience to match donut types 1 to N
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    int sad_customers = 0;
    for (int i = 0; i < M; ++i) {
        int type;
        cin >> type;
        
        // Check if the requested donut type is available
        if (A[type] > 0) {
            A[type]--;
        } else {
            // No donuts left of this type, customer is sad
            sad_customers++;
        }
    }

    cout << sad_customers << "\n";
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