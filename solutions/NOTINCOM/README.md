# [Nothing in Common (NOTINCOM)](https://www.codechef.com/problems/NOTINCOM)

- **Difficulty Rating**: 1386
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two sets of integers, one belonging to Alice (size $N$) and one to Berta (size $M$), determine the number of elements that are present in both sets. Since each collection contains distinct integers, we are essentially looking for the size of the intersection of the two sets.

## Intuition & Mathematical Observation
The problem asks for the count of common elements. A naive approach would be to compare every element of Alice's set with every element of Berta's set, resulting in an $O(N \times M)$ complexity, which is too slow given $N, M \le 10^5$.

Since the values of the integers are constrained to $10^6$, we can use a **Frequency Array** (or a boolean lookup table) to store the presence of Berta's numbers. 
1. Mark all of Berta's numbers in a boolean array `berta_has` of size $1,000,001$.
2. Iterate through Alice's numbers and check if the corresponding index in `berta_has` is `true`.
3. This reduces the lookup time for each of Alice's elements to $O(1)$.
4. After processing, we must reset the `berta_has` array to `false` for the next test case to ensure no data leakage between test cases.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$ per test case. We iterate through Berta's set once to populate the lookup table and through Alice's set once to count the matches. With $T$ test cases, the total time complexity is $O(T \times (N + M))$.
- **Space Complexity**: $O(V)$, where $V$ is the maximum possible value of an integer ($10^6$). This is used for the boolean lookup array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has a set of N integers and Berta has a set of M integers.
 * We need to find the number of elements in Alice's set that are also present in Berta's set.
 * 
 * Approach:
 * We use a boolean array to store Berta's numbers for O(1) lookup.
 * Given the constraint Ai, Bi <= 10^6, a boolean array of size 1,000,001 is efficient.
 */

const int MAX_VAL = 1000000;
bool berta_has[MAX_VAL + 1];

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<int> alice(n);
    for (int i = 0; i < n; ++i) {
        cin >> alice[i];
    }

    vector<int> berta(m);
    for (int i = 0; i < m; ++i) {
        cin >> berta[i];
        berta_has[berta[i]] = true;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (berta_has[alice[i]]) {
            count++;
        }
    }

    cout << count << "\n";

    // Cleanup for next test case: only reset indices that were set to true
    for (int i = 0; i < m; ++i) {
        berta_has[berta[i]] = false;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```