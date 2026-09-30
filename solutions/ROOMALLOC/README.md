# [Room Allocation (ROOMALLOC)](https://www.codechef.com/problems/ROOMALLOC)

- **Difficulty Rating**: 729
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ colleges, each with a specific number of members $A_i$. The constraints are:
1. People from different colleges cannot share a room.
2. Each room can accommodate at most 2 people.
We need to calculate the minimum number of rooms required to accommodate all members from all colleges.

## Intuition & Mathematical Observation
Since members from different colleges cannot share a room, we must calculate the rooms required for each college independently and then sum them up.

For a single college with $A_i$ members:
- If $A_i$ is even, we can perfectly pair them up, requiring $A_i / 2$ rooms.
- If $A_i$ is odd, we will have one person left over after filling rooms with pairs, requiring $(A_i - 1) / 2 + 1$ rooms.

Both cases can be unified using the ceiling division formula for integers:
$$\text{Rooms for college } i = \lceil A_i / 2 \rceil = \frac{A_i + 1}{2}$$
By summing this value for all $N$ colleges, we obtain the total minimum number of rooms required.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of colleges. We iterate through the list of colleges exactly once.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the running total.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each college has A_i members.
 * People from different colleges cannot share a room.
 * Each room can hold at most 2 people.
 * 
 * For a college with A_i members:
 * If A_i is even, we need A_i / 2 rooms.
 * If A_i is odd, we need (A_i + 1) / 2 rooms.
 * This can be simplified using integer division: (A_i + 1) / 2.
 * 
 * Total rooms = Sum of rooms needed for each college.
 */

void solve() {
    int N;
    cin >> N;
    long long total_rooms = 0;
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        // Each college needs ceil(A / 2.0) rooms.
        // Using integer arithmetic: (A + 1) / 2
        total_rooms += (A + 1) / 2;
    }
    cout << total_rooms << "\n";
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