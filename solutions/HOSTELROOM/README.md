# [Hostel Room (HOSTELROOM)](https://www.codechef.com/problems/HOSTELROOM)

- **Difficulty Rating**: 1169
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an initial number of people $X$ in a hostel room. You are then provided with a sequence of $N$ events, where each event represents a change in the number of people (either an arrival or a departure). Your task is to determine the maximum number of people present in the room at any point in time, including the initial state.

## Intuition & Mathematical Observation
The problem asks us to track the state of a variable over time and identify its peak value. 

1. **State Tracking**: We maintain a variable `current_people` initialized to $X$. As we iterate through the array of changes, we update `current_people` by adding the value of the current event.
2. **Peak Tracking**: Since we need the maximum value observed, we maintain a second variable `max_people`. We initialize it to $X$ (the starting state) and update it whenever `current_people` exceeds the current `max_people`.
3. **Constraints**: With $N \le 100$ and $X \le 100$, the maximum possible value is well within the limits of a standard 32-bit integer. Using `long long` is a safe practice to prevent overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of events. We perform a single pass through the input array.
- **Space Complexity**: $O(1)$, as we only store a few variables (`current_people`, `max_people`, `change`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with X people. We iterate through the array A.
 * At each step i, the number of people changes by A[i].
 * We need to track the current number of people and maintain the maximum value observed.
 * 
 * Constraints:
 * T <= 100, N <= 100, X <= 100, A_i between -100 and 100.
 * The maximum possible number of people will not exceed 100 + (100 * 100) = 10100.
 * Standard 'int' is sufficient, but 'long long' is used for safety.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;

    long long current_people = X;
    long long max_people = X;

    for (int i = 0; i < N; ++i) {
        long long change;
        cin >> change;
        current_people += change;
        // Update max_people if the current count is higher
        if (current_people > max_people) {
            max_people = current_people;
        }
    }

    cout << max_people << "\n";
}

int main() {
    // Fast I/O for performance
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