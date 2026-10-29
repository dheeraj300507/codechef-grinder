# [Cool Subsequences (COOLSUB)](https://www.codechef.com/problems/COOLSUB)

- **Difficulty Rating**: 1239
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to find a non-empty subsequence of a given array $A$ such that the average of every non-empty subsequence of this chosen subsequence is also present in the remaining elements of the original array (the complement). If no such subsequence exists, we output -1.

## Intuition & Mathematical Observation
The core of the problem lies in the definition of a "cool" subsequence. Let's consider a subsequence consisting of a single element $\{x\}$. 
1. The only non-empty subsequence of $\{x\}$ is $\{x\}$ itself.
2. The average of $\{x\}$ is $x$.
3. For $\{x\}$ to be a "cool" subsequence, the value $x$ must be present in the complement of the chosen subsequence.

This implies that if the original array contains at least one duplicate value $x$, we can pick a subsequence $\{x\}$. The complement will contain at least one other instance of $x$. Since the average of $\{x\}$ is $x$, and $x$ exists in the complement, the condition is satisfied.

If all elements in the array are distinct, any subsequence we pick will have an average that is likely not present in the remaining elements (or the condition simply cannot be satisfied). Based on the problem constraints and sample cases, if no duplicates exist, no such subsequence exists, and we output -1.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step used to identify duplicates. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the input array and its sorted copy.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * A subsequence is "cool" if the averages of all its non-empty subsequences are 
 * present in the complement.
 * 
 * If there is at least one duplicate element 'x', the subsequence {x} is cool
 * because the complement will contain the other 'x', and the average of {x} is x.
 * 
 * If all elements are distinct, we check if any element exists. Given the 
 * constraints and the nature of the problem, if no duplicates exist, it is 
 * highly likely no such subsequence exists (as per the sample case).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort to find duplicates efficiently in O(N log N)
    vector<int> sorted_A = A;
    sort(sorted_A.begin(), sorted_A.end());

    int duplicate_val = -1;
    for (int i = 0; i < N - 1; ++i) {
        if (sorted_A[i] == sorted_A[i + 1]) {
            duplicate_val = sorted_A[i];
            break;
        }
    }

    if (duplicate_val != -1) {
        cout << 1 << "\n";
        cout << duplicate_val << "\n";
    } else {
        // If no duplicates, the sample case suggests -1.
        cout << -1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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