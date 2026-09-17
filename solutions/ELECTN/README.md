# [Elections in Chefland (ELECTN)](https://www.codechef.com/problems/ELECTN)

- **Difficulty Rating**: 604
- **Solved in**: 1 attempt(s)

## Problem Summary
In Chefland, a person is eligible to vote if their age is at least $X$ years. Given a list of $N$ people with their respective ages, the task is to determine how many of them are eligible to vote.

## Intuition & Mathematical Observation
The problem is a straightforward filtering task. We are given a threshold value $X$ and a collection of ages. For each individual age $A_i$ in the collection, we simply need to check the condition:
$$A_i \ge X$$
If the condition holds true, the person is eligible. We maintain a counter and increment it every time we encounter an age that satisfies this inequality. Since we only need to process each age once, a single linear pass through the input is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of people per test case. We iterate through each person's age exactly once.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the count and the current age being processed, rather than storing the entire array in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: ELECTN - Elections in Chefland
 * Approach: Iterate through the array of ages and count how many are >= X.
 * Time Complexity: O(T * N), where T is the number of test cases and N is the number of people.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, x;
        cin >> n >> x;

        int eligible_count = 0;
        for (int i = 0; i < n; ++i) {
            int age;
            cin >> age;
            // A person is eligible if their age is at least X
            if (age >= x) {
                eligible_count++;
            }
        }

        cout << eligible_count << "\n";
    }

    return 0;
}
```