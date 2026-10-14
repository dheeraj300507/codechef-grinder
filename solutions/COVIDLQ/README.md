# [COVID Pandemic and Long Queue (COVIDLQ)](https://www.codechef.com/problems/COVIDLQ)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a queue represented by an array of size $N$ consisting of $0$s (empty space) and $1$s (a person). The rule for social distancing states that any two people must be at least 6 feet apart. In the context of the array indices, if two people are at indices $i$ and $j$ (where $i < j$), the condition is satisfied if $j - i \ge 6$. We need to determine if the given queue configuration follows this rule.

## Intuition & Mathematical Observation
The problem requires us to track the position of the most recently encountered person. 
1. We initialize a variable `last_pos` to a value that ensures the first person encountered does not trigger a false violation (e.g., $-10$).
2. As we iterate through the array, whenever we encounter a $1$ at index $i$, we check the distance from the previous person: `i - last_pos`.
3. If `i - last_pos < 6`, the social distancing rule is violated, and we can immediately conclude the answer is "NO".
4. If we successfully traverse the entire array without violating this condition, the answer is "YES".

This approach is optimal because it only requires a single pass through the input array.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of people in the queue. We iterate through the array exactly once.
- **Space Complexity**: $O(N)$ to store the array, though this could be optimized to $O(1)$ by processing the input elements on the fly without storing them in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sequence of 0s and 1s representing a queue.
 * We need to ensure that for any two people (1s), the distance between them 
 * is at least 6 feet.
 * 
 * If the indices of two people are i and j (where i < j), the distance is (j - i).
 * The condition is (j - i) >= 6.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Initialize with a value that won't trigger a false violation
    int last_pos = -10; 
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            // Check if the distance to the last person is less than 6
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
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