# [Ordered Distances (ORDDIST)](https://www.codechef.com/problems/ORDDIST)

- **Difficulty Rating**: 1112
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an initial sequence $X$ of $N$ integers and a target sequence $Y$, we need to determine if there exists a "pivot" element $P$ chosen from the original sequence $X$ such that when we construct a list of pairs $(|X_j - P|, X_j)$ for all $j \in [1, N]$ and sort them lexicographically, the sequence of the second elements of these pairs matches the sequence $Y$. If such a pivot exists, output its 1-based index; otherwise, output -1.

## Intuition & Mathematical Observation
The problem asks us to verify if any element $X_i$ can serve as a pivot. Since the constraints on $N$ are small ($N \le 100$), we can use a brute-force approach:

1. **Pivot Selection**: Iterate through every index $i$ from $0$ to $N-1$ and treat $X_i$ as the pivot $P$.
2. **Pair Construction**: For a fixed $P$, generate a list of pairs where each pair consists of the absolute difference from the pivot and the original value: `pair = (|X[j] - P|, X[j])`.
3. **Sorting**: Sort these pairs lexicographically. C++ `std::sort` on `std::pair<int, int>` naturally sorts by the first element (the distance) and breaks ties using the second element (the original value), which aligns perfectly with the problem's requirements.
4. **Verification**: Compare the sequence of second elements from the sorted list with the target sequence $Y$. If they match, we have found our pivot.

## Complexity Analysis
- **Time Complexity**: For each test case, we iterate through $N$ possible pivots. For each pivot, we perform a sort operation on $N$ elements, which takes $O(N \log N)$. Thus, the total time complexity is $O(T \times N^2 \log N)$. Given $N=100$ and $T=100$, this results in approximately $10^6$ operations, well within the typical 1-second time limit.
- **Space Complexity**: $O(N)$ to store the input arrays $X$, $Y$, and the temporary list of pairs.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * We are given an initial sequence X and a transformed sequence Y.
 * We need to find if there exists a pivot index i (1 <= i <= N) such that
 * if we set P = X[i], the sorted list of pairs (|X[j] - P|, X[j])
 * results in the sequence Y.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    vector<int> Y(N);
    for (int i = 0; i < N; ++i) cin >> Y[i];

    // Try every possible pivot index i (0-indexed internally)
    for (int i = 0; i < N; ++i) {
        int P = X[i];
        vector<pair<int, int>> L(N);
        for (int j = 0; j < N; ++j) {
            L[j] = {abs(X[j] - P), X[j]};
        }

        // Sort based on the problem definition:
        // (A, B) < (C, D) if A < C or (A == C and B < D)
        // std::sort uses lexicographical comparison for pairs by default.
        sort(L.begin(), L.end());

        // Check if the resulting sequence matches Y
        bool match = true;
        for (int k = 0; k < N; ++k) {
            if (L[k].second != Y[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << (i + 1) << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    // Fast I/O to ensure we stay well within time limits
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