# [All Even (ALLEV)](https://www.codechef.com/problems/ALLEV)

- **Difficulty Rating**: 617
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we are allowed to perform an operation: take the last element and add it to the second-to-last element, then remove the last element. We can repeat this operation any number of times. The goal is to determine if it is possible to reach a state where every element in the resulting array is even.

## Intuition & Mathematical Observation
The operation essentially allows us to merge a suffix of the array into a single element. If we decide to reduce the array to a size $k$ (where $1 \le k \le N$), the resulting array will consist of the first $k-1$ elements of the original array, followed by the sum of the remaining elements from index $k-1$ to $N-1$.

For the resulting array to consist only of even numbers:
1. All elements $A[0], A[1], \dots, A[k-2]$ must be even.
2. The sum of the suffix $A[k-1] + A[k] + \dots + A[N-1]$ must be even.

We can iterate through all possible values of $k$ from $1$ to $N$. For each $k$, we verify the two conditions above. If any $k$ satisfies both, the answer is "Yes". If we check all possible $k$ and none satisfy the condition, the answer is "No".

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ in the provided implementation, as we iterate through $k$ and then calculate the suffix sum. Given the constraints for this difficulty level, this is efficient enough. It can be optimized to $O(N)$ using prefix sums, but $O(N^2)$ is well within the limits for typical $N \le 1000$.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We can reduce the array to any size k (where 1 <= k <= N) 
 * by merging the last (N-k) elements into the k-th element.
 * 
 * For a fixed k:
 * - A[0], A[1], ..., A[k-2] must all be even.
 * - The sum (A[k-1] + A[k] + ... + A[N-1]) must be even.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    bool possible = false;
    // Try every possible final size k
    for (int k = 1; k <= N; ++k) {
        bool ok = true;
        
        // Check if prefix A[0]...A[k-2] are all even
        for (int i = 0; i < k - 1; ++i) {
            if (A[i] % 2 != 0) {
                ok = false;
                break;
            }
        }
        
        if (!ok) continue;
        
        // Check if the sum of the remaining suffix is even
        long long suffix_sum = 0;
        for (int i = k - 1; i < N; ++i) {
            suffix_sum += A[i];
        }
        
        if (suffix_sum % 2 == 0) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```